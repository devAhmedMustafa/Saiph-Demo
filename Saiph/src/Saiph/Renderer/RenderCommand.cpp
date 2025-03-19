#include "sppch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Saiph {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}