#pragma once

#include "Core.h"
#include "Nnuts/Events/Event.h"

namespace Nnuts {

class NNUTS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	
// To be defined by the Client
	Application* CreateApplication();
	
}

