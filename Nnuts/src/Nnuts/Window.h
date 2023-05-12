#pragma once

#include "Nnpch.h"

#include "Nnuts/Core.h"
#include "Nnuts/Events/Event.h"

namespace Nnuts {
	//Defined Window Properties for an abstract(OpenGL) Window
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string title = "Nnuts Engine",
					unsigned int width = 1280,
					unsigned int height = 720)
			:Title(title), Width(width), Height(height) {}
	};

	//Interface representing a dessktop based Window
	class NNUTS_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVsync(bool enabled) = 0;
		virtual bool IsVsync() const = 0;

		// Generate window on current platform (will return win32 windows
		// when using windows and similarly will extend towards other 
		// platforms like MacOS or Linux)
		static Window* Create(const WindowProps& props = WindowProps());

	};
}