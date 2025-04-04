#pragma once
#include "Saiph/Renderer/RendererAPI.h"

namespace Saiph {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& va) override;
	};

}