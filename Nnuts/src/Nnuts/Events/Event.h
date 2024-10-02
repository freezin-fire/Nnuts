#pragma once

#include "Nnuts/Core.h"
#include <Nnpch.h>
//#include <functional>

namespace Nnuts {

	// Currently, these events are blocked. So like if an
	// event occurs then the whole app will stop and will
	// process that event first. Will work on making a
	// proper event handeler buffer/queue in future.

	enum class EventType {
		None = 0,

		// Window Events:
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		// Application Events:
		AppTick, AppUpdate, AppRender,
		// Keyboard/Gamepad Events:
		KeyPressed, KeyReleased, KeyTyped,
		// Mouse Events:
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// Define categories and subcategories of different events that are
	// going to occur in the application. BIT(x) macro shifts the bit to
	// left and provides binary categorical differentiation for subcategories
	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};


	// Macros for assigning unique event class type and category for a new Event
#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	// Event class defination
	class NNUTS_API Event {
	public:
		bool m_Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	};

	// Event Dispatcher defination, here T is any event like WindowResize
	// or ButtonPressed.
	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			:m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
	
	inline std::ostream& operator <<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}

	template<typename T>
	struct fmt::formatter<
		T, std::enable_if_t<std::is_base_of<Event, T>::value, char>>
		: fmt::formatter<std::string> {
		auto format(const T& event, fmt::format_context& ctx) {
			return fmt::format_to(ctx.out(), "{}", event.ToString());
		}
	};

	template <typename... T>
	std::string StringFromArgs(fmt::format_string<T...> fmt, T&&... args) {
		return fmt::format(fmt, std::forward<T>(args)...);
	}
}