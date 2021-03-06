#pragma once

#include "Evil/Core/Layer.h"

#include "Evil/Events/ApplicationEvent.h"
#include "Evil/Events/KeyEvent.h"
#include "Evil/Events/MouseEvent.h"

namespace Evil
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}