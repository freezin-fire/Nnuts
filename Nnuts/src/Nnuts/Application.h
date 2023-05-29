#pragma once

#include "Core.h"

#include "Window.h"
#include "Nnuts/LayerStack.h"
#include "Nnuts/Events/Event.h"
#include "Nnuts/Events/ApplicationEvent.h"

namespace Nnuts {

class NNUTS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	
// To be defined by the Client
	Application* CreateApplication();
	
}

