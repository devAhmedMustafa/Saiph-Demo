#pragma once

#include "Core.h"
#include "Window.h"
#include "Saiph/LayerStack.h"
#include "Saiph/Events/ApplicationEvent.h"

namespace Saiph {


	class SAIPH_API Application
	{
	private:

		static Application* s_Instance;

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;

	public: 
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer*);
		void PushOverlay(Layer*);

		inline static Application& Get() {	return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent&);

	};

	Application* CreateApplication();

}