#include "evilpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Evil/Platform/OpenGL/OpenGLVertexArray.h"

namespace Evil
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:		EVIL_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:	return new OpenGLVertexArray();


		}

		EVIL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}