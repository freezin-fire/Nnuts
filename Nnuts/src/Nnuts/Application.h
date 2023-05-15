#pragma once

#include "Core.h"
#include "Nnuts/Events/Event.h"
#include "Nnuts/Events/ApplicationEvent.h"

#include "Window.h"

namespace Nnuts {

class NNUTS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	
// To be defined by the Client
	Application* CreateApplication();
	
}

