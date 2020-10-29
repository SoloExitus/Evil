#pragma once

#include "Core.h"

#include "Window.h"
#include "Evil/LayerStack.h"
#include "Evil/Events/Event.h"
#include "Evil/Events/ApplicationEvent.h"

#include "Evil/ImGui/ImGuiLayer.h"

#include "Evil/Renderer/Shader.h"
#include "Evil/Renderer/Buffer.h"
#include "Evil/Renderer/VertexArray.h"

namespace Evil
{
	class EVIL_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* Overlay);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


