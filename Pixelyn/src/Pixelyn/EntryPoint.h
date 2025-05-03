#pragma once

#ifdef PX_PLATFORM_WINDOWS

extern Pixelyn::Application* Pixelyn::CreateApplication();

// The entry point of the application is controlled from the engine side
int main(int argc, char** argx)
{
	auto app = Pixelyn::CreateApplication();
	app->Run();
	delete app;
}

#endif