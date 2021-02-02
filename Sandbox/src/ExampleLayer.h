#pragma once

#include "Evil.h"

class ExampleLayer : public Evil::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Evil::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Evil::Event& e) override;
private:
	Evil::ShaderLibrary m_ShaderLibrary;
	Evil::Ref<Evil::Shader> m_Shader;
	Evil::Ref<Evil::VertexArray> m_VertexArray;

	Evil::Ref<Evil::Shader> m_FlatColorShader;
	Evil::Ref<Evil::VertexArray> m_SquareVA;

	Evil::Ref<Evil::Texture2D> m_Texture, m_CLogoTexture;

	Evil::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};