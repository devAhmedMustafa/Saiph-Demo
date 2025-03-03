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

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);

		bool OnWindowResizeEvent(WindowResizeEvent& e);

	};


}