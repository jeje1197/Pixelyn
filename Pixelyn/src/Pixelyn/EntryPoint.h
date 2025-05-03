#pragma once

#ifdef PX_PLATFORM_WINDOWS

extern Pixelyn::Application* Pixelyn::CreateApplication();

// The entry point of the application is controlled from the engine side
int main(int argc, char** argx)
{
	Pixelyn::Log::Init();
	PX_CORE_WARN("Initialized Log!");
	int a = 5;
	PX_INFO("Hello! Var={0}", a);

	auto app = Pixelyn::CreateApplication();
	app->Run();
	delete app;
}

#endif