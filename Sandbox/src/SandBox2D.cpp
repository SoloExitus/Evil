#include "SandBox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Evil/Platform/OpenGL/OpenGLShader.h"

SandBox2D::SandBox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{

}

void SandBox2D::OnAttach()
{
	m_SquareVA = Evil::VertexArray::Create();

	float squareVertices[5 * 4] =
	{
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	Evil::Ref<Evil::VertexBuffer> squareVB;
	squareVB.reset(Evil::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

	squareVB->SetLayout({
		{ Evil::ShaderDataType::Float3, "a_Position" },
	});

	m_SquareVA->AddVertexBuffer(squareVB);

	uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
	Evil::Ref<Evil::IndexBuffer> squareIB;

	squareIB.reset(Evil::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
	m_SquareVA->SetIndexBuffer(squareIB);

	m_FlatColorShader = Evil::Shader::Create("assets/shaders/FlatColor.glsl");
}

void SandBox2D::OnDetach()
{
}

void SandBox2D::OnUpdate(Evil::Timestep ts)
{

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Evil::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 0.1f });
	Evil::RenderCommand::Clear();

	Evil::Renderer::BeginScene(m_CameraController.GetCamera());

	std::dynamic_pointer_cast<Evil::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Evil::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);
	Evil::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

	Evil::Renderer::EndScene();
}

void SandBox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void SandBox2D::OnEvent(Evil::Event& e)
{
	m_CameraController.OnEvent(e);
}
