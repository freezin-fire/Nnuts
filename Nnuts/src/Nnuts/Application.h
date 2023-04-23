#pragma once

#include "Core.h"

namespace Nnuts {

class NNUTS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	
	Application* CreateApplication();
	
}

