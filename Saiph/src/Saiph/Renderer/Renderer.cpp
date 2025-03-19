#include "sppch.h"
#include "Renderer.h"

namespace Saiph {

	void Renderer::BeginScene()
	{
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const std::shared_ptr<VertexArray>& va)
	{
		va->Bind();
		RenderCommand::DrawIndexed(va);
	}

}