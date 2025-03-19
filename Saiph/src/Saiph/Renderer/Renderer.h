#pragma once

#include "RenderCommand.h"

namespace Saiph {


	class Renderer
	{

	public:

		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& va);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};

}