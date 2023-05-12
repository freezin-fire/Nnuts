#pragma once

#include "Core.h"
#include "Nnuts/Events/Event.h"
#include "Window.h"

namespace Nnuts {

class NNUTS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	
// To be defined by the Client
	Application* CreateApplication();
	
}

