#pragma once

#include "Evil.h"

class SandBox2D: public Evil::Layer
{
public:
	SandBox2D();
	virtual ~SandBox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Evil::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Evil::Event& e) override;
private:
	Evil::OrthographicCameraController m_CameraController;

	// Temp
	Evil::Ref<Evil::VertexArray> m_SquareVA;
	Evil::Ref<Evil::Shader> m_FlatColorShader;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};