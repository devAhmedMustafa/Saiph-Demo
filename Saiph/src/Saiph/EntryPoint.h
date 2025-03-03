#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Saiph::Application* Saiph::CreateApplication();

int main(int argc, char** argv) {

	Saiph::Log::Init();
	SP_CORE_WARN("Initialized");

	auto app = Saiph::CreateApplication();
	app->Run();
	delete app;
}

#endif