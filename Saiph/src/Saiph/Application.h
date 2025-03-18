#pragma once

#include "Core.h"
#include "Window.h"
#include "Saiph/LayerStack.h"
#include "Saiph/Events/ApplicationEvent.h"

#include "Saiph/ImGui/ImGuiLayer.h";

#include "Saiph/Renderer/Buffer.h"
#include "Saiph/Renderer/Shader.h"
#include "Saiph/Renderer/VertexArray.h"



namespace Saiph {


	class SAIPH_API Application
	{
	private:

		static Application* s_Instance;

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;

		LayerStack m_LayerStack;

		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

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