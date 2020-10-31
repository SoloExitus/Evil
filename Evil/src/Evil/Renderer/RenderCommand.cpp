#include "evilpch.h"
#include "RenderCommand.h"

#include "Evil/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Evil
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}