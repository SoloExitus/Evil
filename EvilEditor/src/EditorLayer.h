#pragma once

#include "Evil.h"

#include "Panels/SceneHierarchyPanel.h"

namespace Evil
{
	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;
	private:
		bool OnKeyPressed(KeyPressedEvent& e);

		void NewScene();
		void OpenScene();
		void SaveSceneAs();
	private:
		OrthographicCameraController m_CameraController;

		Ref<Texture2D> m_CheckerboardTexture;

		Ref<Scene> m_ActiveScene;
		Entity m_CameraEntity;
		Entity m_SecondCamera;
		Entity m_SquareEntity;

		bool m_PrimaryCamera = true;

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };

		Ref<Framebuffer> m_Framebuffer;

		glm::vec4 m_SquareColor;

		// Panels
		SceneHierarchyPanel m_SceneHierarchyPanel;
	};
}
