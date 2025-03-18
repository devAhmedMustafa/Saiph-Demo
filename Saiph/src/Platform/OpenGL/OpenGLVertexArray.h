#pragma once

#include "Saiph/Renderer/VertexArray.h"

namespace Saiph {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray() {}

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) const override;
		virtual const void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) const override;

		static VertexArray* Create();

	private:
		uint32_t m_RendererID;
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
	};

}