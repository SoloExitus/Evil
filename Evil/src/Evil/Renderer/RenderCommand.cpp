#include "evilpch.h"
#include "RenderCommand.h"

#include "Evil/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Evil
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = CreateScope<OpenGLRendererAPI>();
}