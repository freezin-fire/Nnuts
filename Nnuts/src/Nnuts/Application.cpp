#include "Nnpch.h"
#include "Application.h"

#include "Nnuts/Events/ApplicationEvent.h"
#include "Log.h"

namespace Nnuts {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			NN_TRACE(e);
		}
		
		while (true);
	}
}