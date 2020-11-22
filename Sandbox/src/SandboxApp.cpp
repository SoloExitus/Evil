
#include <Evil.h>

#include "Evil/Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public Evil::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{

		m_VertexArray.reset(Evil::VertexArray::Create());

		float vertices[3 * 7] =
		{
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f
		};

		Evil::Ref<Evil::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Evil::VertexBuffer::Create(vertices, sizeof(vertices)));
		Evil::BufferLayout layout = {
			{ Evil::ShaderDataType::Float3, "a_Position" },
			{ Evil::ShaderDataType::Float4, "a_Color" }
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		Evil::Ref<Evil::IndexBuffer> indexBuffer;
		indexBuffer.reset(Evil::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Evil::VertexArray::Create());

		float squareVertices[5 * 4] =
		{
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Evil::Ref<Evil::VertexBuffer> squareVB;
		squareVB.reset(Evil::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

		squareVB->SetLayout({
			{ Evil::ShaderDataType::Float3, "a_Position" },
			{ Evil::ShaderDataType::Float2, "a_TexCoord" },
			});

		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		Evil::Ref<Evil::IndexBuffer> squareIB;
		squareIB.reset(Evil::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(Evil::Shader::Create(vertexSrc, fragmentSrc));

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

		m_FlatColorShader.reset(Evil::Shader::Create(flatColorShaderVertexSrc, flatColorShaderFragmentSrc));

		m_TextureShader.reset(Evil::Shader::Create("assets/shaders/Texture.glsl"));

		m_Texture = Evil::Texture2D::Create("assets/textures/Checkerboard.png");
		m_ChernoLogoTexture = Evil::Texture2D::Create("assets/textures/ChernoLogo.png");

		std::dynamic_pointer_cast<Evil::OpenGLShader>(m_TextureShader)->Bind();
		std::dynamic_pointer_cast<Evil::OpenGLShader>(m_TextureShader)->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(Evil::Timestep ts) override
	{

		if (Evil::Input::IsKeyPressed(EVIL_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		else if (Evil::Input::IsKeyPressed(EVIL_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if (Evil::Input::IsKeyPressed(EVIL_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;
		else if (Evil::Input::IsKeyPressed(EVIL_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;

		if (Evil::Input::IsKeyPressed(EVIL_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		else if (Evil::Input::IsKeyPressed(EVIL_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed * ts;

		Evil::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 0.1f });
		Evil::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Evil::Renderer::BeginScene(m_Camera);

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Evil::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Evil::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++) 
			for(int x=0;x < 20; x++)
		{
			glm::vec3 pos(x * 0.11f, y* 0.11f, 0.0f);
			glm::mat4 transform = glm::translate(glm::mat4(1.0f),pos) * scale;
			Evil::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
		}

		m_Texture->Bind();
		Evil::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		m_ChernoLogoTexture->Bind();
		Evil::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		//Triangle
		//Evil::Renderer::Submit(m_Shader, m_VertexArray);

		Evil::Renderer::EndScene();

	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(Evil::Event& event) override
	{

	}

private:
	Evil::Ref<Evil::Shader> m_Shader;
	Evil::Ref<Evil::VertexArray> m_VertexArray;

	Evil::Ref<Evil::Shader> m_FlatColorShader, m_TextureShader;
	Evil::Ref<Evil::VertexArray> m_SquareVA;

	Evil::Ref<Evil::Texture2D> m_Texture, m_ChernoLogoTexture;

	Evil::OrthographicCamera m_Camera;

	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class SandBox : public Evil::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
	}
	~SandBox()
	{

	}
};

Evil::Application* Evil::CreateApplication() 
{
	return new SandBox();
}