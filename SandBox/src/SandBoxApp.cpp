#include <Saiph.h>
#include <iostream>

class ExampleLayer : public Saiph::Layer {
public:
	ExampleLayer() : Layer("Example"){
		SP_INFO("Layer created");
	}

	void OnUpdate() override {
		if (Saiph::Input::IsKeyPressed(SP_KEY_TAB))
			SP_INFO("Tab key is pressed!");
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
	}

	~SandBox() {

	}
};

Saiph::Application* Saiph::CreateApplication() {
	return new SandBox();
}