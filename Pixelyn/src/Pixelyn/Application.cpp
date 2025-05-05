#include "pxpch.h"
#include "Application.h"

#include "Pixelyn/Events/ApplicationEvent.h"
#include "Log.h"

namespace Pixelyn {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			PX_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			PX_TRACE(e.ToString());
		}

		while (true);
	}

}