#include "sppch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Saiph {


	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			SP_CORE_ASSERT(false, "RendererAPI::None is not supported");
			return nullptr;

		case RendererAPI::OpenGL:
			return new OpenGLVertexArray();

		}

		SP_CORE_ASSERT(false, "Unknown Renderer API");
		return nullptr;
	}

}