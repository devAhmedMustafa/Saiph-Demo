#pragma once

#include "Saiph/Layer.h"
#include "Saiph/Events/KeyEvent.h"
#include "Saiph/Events/MouseEvent.h"
#include "Saiph/Events/ApplicationEvent.h"

namespace Saiph {

	class SAIPH_API ImGuiLayer : public Layer
	{
		float m_Time = 0.0f;
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:

	};


}