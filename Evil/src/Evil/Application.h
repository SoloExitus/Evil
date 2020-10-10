#pragma once

#include "Core.h"

#include "Window.h"
#include "Evil/LayerStack.h"
#include "Evil/Events/Event.h"
#include "Evil/Events/ApplicationEvent.h"

#include "Evil/ImGui/ImGuiLayer.h"

#include "Evil/Renderer/Shader.h"

#include "Evil/Renderer/Buffer.h"

namespace Evil
{
	class EVIL_API Application
	{
	public:
		Application();
		virtual ~Application();

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

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


