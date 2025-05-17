#pragma once

#include "Core.h"

#include "Window.h"
#include "Pixelyn/LayerStack.h"
#include "Pixelyn/Events/Event.h"
#include "Pixelyn/Events/ApplicationEvent.h"

namespace Pixelyn {

	class PIXELYN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}