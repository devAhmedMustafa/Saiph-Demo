#include <Saiph.h>
#include <iostream>

class ExampleLayer : public Saiph::Layer {
public:
	ExampleLayer() : Layer("Example"){
		SP_INFO("Layer created");
	}

	void OnUpdate() override {

	}

	void OnEvent(Saiph::Event& event) override {
		//std::cout << event << std::endl;
	}
};

class SandBox : public Saiph::Application {
public:
	SandBox() {
		SP_INFO("App started");
		PushLayer(new ExampleLayer());
		PushOverlay(new Saiph::ImGuiLayer());
	}

	~SandBox() {

	}
};

Saiph::Application* Saiph::CreateApplication() {
	return new SandBox();
}