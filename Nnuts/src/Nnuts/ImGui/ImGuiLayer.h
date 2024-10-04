#pragma once

#include "Nnuts/Layer.h"

#include "Nnuts/Events/ApplicationEvent.h"
#include "Nnuts/Events/KeyEvent.h"
#include "Nnuts/Events/MouseEvent.h"

namespace Nnuts {
	
	class NNUTS_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}