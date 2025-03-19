#include "sppch.h"
#include "OpenGLVertexArray.h"

#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace Saiph {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type) 
		{
		case Saiph::ShaderDataType::Float: return GL_FLOAT;
		case Saiph::ShaderDataType::Float2: return GL_FLOAT;
		case Saiph::ShaderDataType::Float3: return GL_FLOAT;
		case Saiph::ShaderDataType::Float4: return GL_FLOAT;
		case Saiph::ShaderDataType::Mat3: return GL_FLOAT;
		case Saiph::ShaderDataType::Mat4: return GL_FLOAT;
		case Saiph::ShaderDataType::Int: return GL_INT;
		case Saiph::ShaderDataType::Int2: return GL_INT;
		case Saiph::ShaderDataType::Int3: return GL_INT;
		case Saiph::ShaderDataType::Int4: return GL_INT;
		case Saiph::ShaderDataType::Bool: return GL_BOOL;

		}
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	const void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		SP_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout");
		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();


		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout) {
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset
			);
			index++;
		}
		m_VertexBuffers.push_back(vertexBuffer);
	}

	const void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

	VertexArray* OpenGLVertexArray::Create()
	{
		return nullptr;
	}

}