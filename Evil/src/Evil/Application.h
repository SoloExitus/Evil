#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Evil/Events/ApplicationEvent.h"

#include "Window.h"

namespace Evil
{
	class EVIL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


