#pragma once

#include "Core.h"

namespace Pixelyn {

	class PIXELYN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be define in client application
	Application* CreateApplication();
}


