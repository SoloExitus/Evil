#include "SandBox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

SandBox2D::SandBox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f }), m_ParticaleSystem(100000)
{

}

void SandBox2D::OnAttach()
{
	EVIL_PROFILE_FUNCTION();

	m_CheckerboardTexture = Evil::Texture2D::Create("assets/textures/Checkerboard.png");
	m_SpriteSheet = Evil::Texture2D::Create("assets/textures/RPGsheet.png");
	m_TextureTree = Evil::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 2, 1 }, { 128, 128 }, { 1, 2 });

	m_Particle.Position = { 0.0f, 0.0f };
	m_Particle.Velocity = { 0.0f, 0.0f }, m_Particle.VelocityVariation = { 3.0f, 1.0f };
	m_Particle.SizeBegin = 0.5f, m_Particle.SizeEnd = 0.0f, m_Particle.SizeVariation = 0.3f;
	m_Particle.ColorBegin = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f , 1.0f };
	m_Particle.LifeTime = 2.0f;
}

void SandBox2D::OnDetach()
{
	EVIL_PROFILE_FUNCTION();
}

void SandBox2D::OnUpdate(Evil::Timestep ts)
{
	EVIL_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Evil::Renderer2D::ResetStats();
	{
		EVIL_PROFILE_SCOPE("Renderer Prep");
		Evil::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 0.1f });
		Evil::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		EVIL_PROFILE_SCOPE("Renderer Draw");
		Evil::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Evil::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(-45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		Evil::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Evil::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		Evil::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.9f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
		Evil::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, glm::radians(rotation), m_CheckerboardTexture, 20.0f);
		Evil::Renderer2D::EndScene();

		Evil::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 1.0f};
				Evil::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Evil::Renderer2D::EndScene();

		if (Evil::Input::IsMouseButtonPressed(EVIL_MOUSE_BUTTON_LEFT))
		{
			auto [x, y] = Evil::Input::GetMousePosition();
			auto width = Evil::Application::Get().GetWindow().GetWidth();
			auto height = Evil::Application::Get().GetWindow().GetHeight();

			auto bounds = m_CameraController.GetBounds();
			auto pos = m_CameraController.GetCamera().GetPostion();
			auto boundWidth = bounds.GetWidth();
			auto boundHeight = bounds.GetHeight();

			x = (x / width) * boundWidth - boundWidth * 0.5f;
			y = boundHeight * 0.5f - (y / height) * boundHeight;

			m_Particle.Position = { x + pos.x, y + pos.y };
			for (int i = 0; i < 30; i++)
			{
				m_ParticaleSystem.Emit(m_Particle);
			}
		}

		m_ParticaleSystem.OnUpdate(ts);
		m_ParticaleSystem.OnRender(m_CameraController.GetCamera());

		Evil::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Evil::Renderer2D::DrawRotatedQuad({ 0.0f, 0.0f, 0.0f }, { 1.0f, 2.0f }, glm::radians(0.0f), m_TextureTree);
		Evil::Renderer2D::EndScene();
	}

}

void SandBox2D::OnImGuiRender()
{
	EVIL_PROFILE_FUNCTION();
	ImGui::Begin("Settings");

	auto stats = Evil::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quad Count: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());


	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void SandBox2D::OnEvent(Evil::Event& e)
{
	m_CameraController.OnEvent(e);
}
