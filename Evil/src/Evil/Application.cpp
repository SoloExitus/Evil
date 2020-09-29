#include "evilpch.h"
#include "Application.h"

#include "Evil/Events/ApplicationEvent.h"
#include "Evil/Log.h"

namespace Evil
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		EVIL_TRACE(e);

		while (true);
	}
}