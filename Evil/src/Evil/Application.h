#pragma once

#include "Core.h"

#include "Window.h"
#include "Evil/LayerStack.h"
#include "Evil/Events/Event.h"
#include "Evil/Events/ApplicationEvent.h"



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
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


