#pragma once

#include "Core.h"

#include "Window.h"
#include "Nnuts/LayerStack.h"
#include "Nnuts/Events/Event.h"
#include "Nnuts/Events/ApplicationEvent.h"

#include "Nnuts/ImGui/ImGuiLayer.h"

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

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};
	
	// To be defined by the Client
	Application* CreateApplication();
	
}

