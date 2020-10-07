#pragma once

#include "Evil/Layer.h"

#include "Evil/Events/ApplicationEvent.h"
#include "Evil/Events/KeyEvent.h"
#include "Evil/Events/MouseEvent.h"

namespace Evil
{
	class EVIL_API ImGuiLayer : public Layer
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