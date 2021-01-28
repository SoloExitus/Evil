#include "SandBox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

SandBox2D::SandBox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{

}

void SandBox2D::OnAttach()
{
	m_CheckerboardTexture = Evil::Texture2D::Create("assets/textures/Checkerboard.png");
}

void SandBox2D::OnDetach()
{
}

void SandBox2D::OnUpdate(Evil::Timestep ts)
{
	EVIL_PROFILE_FUNCTION()

	// Update
	{
		EVIL_PROFILE_SCOPE("CameraController::OnUpdate");
		m_CameraController.OnUpdate(ts);
	}

	// Render
	{
		EVIL_PROFILE_SCOPE("Renderer Prep");
		Evil::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 0.1f });
		Evil::RenderCommand::Clear();
	}

	{
		EVIL_PROFILE_SCOPE("Renderer Draw");
		Evil::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Evil::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Evil::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Evil::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
		Evil::Renderer2D::EndScene();
	}
}

void SandBox2D::OnImGuiRender()
{
	EVIL_PROFILE_FUNCTION();
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void SandBox2D::OnEvent(Evil::Event& e)
{
	m_CameraController.OnEvent(e);
}
