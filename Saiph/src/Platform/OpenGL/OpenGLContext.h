#pragma once

#include "Saiph/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Saiph {

	class OpenGLContext : public GraphicsContext
	{

		GLFWwindow* m_WindowHandle;

	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	};

}