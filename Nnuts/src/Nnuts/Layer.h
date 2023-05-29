#pragma once

#include "Nnuts/Core.h"
#include "Nnuts/Events/Event.h"

// To create a layer, the client will have to create a subclass
// with the following layer class as base and then implement the 
// functions as desired

namespace Nnuts {
	class NNUTS_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}

