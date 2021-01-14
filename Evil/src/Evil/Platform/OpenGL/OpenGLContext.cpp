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

	#ifdef EVIL_ENABLE_ASSERTS
			int versionMajor;
			int versionMinor;
			glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
			glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

			EVIL_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Evil requires at least OpenGL version 4.5!");
	#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}