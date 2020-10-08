#include "evilpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Evil
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		EVIL_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		EVIL_CORE_ASSERT(status, "Failed to initialize Glad!");

		EVIL_CORE_INFO("OpenGL info:");
		EVIL_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		EVIL_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		EVIL_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}