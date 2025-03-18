#include "sppch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Saiph/Log.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Saiph {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			SP_CORE_ASSERT(false, "RendererAPI::None is not supported");
			return nullptr;

		case RendererAPI::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);

		}

		SP_CORE_ASSERT(false, "Unknown Renderer API");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			SP_CORE_ASSERT(false, "RendererAPI::None is not supported");
			return nullptr;

		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer(indices, size);

		}

		SP_CORE_ASSERT(false, "Unknown Renderer API");
		return nullptr;
	}

}