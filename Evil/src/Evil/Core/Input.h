#pragma once

#include "Evil/Core/Base.h"
#include "Evil/Core/KeyCodes.h"
#include "Evil/Core/MouseCodes.h"

namespace Evil
{
	class Input
	{
	protected:
		Input() = default;
	public:
		virtual ~Input() = default;

		Input(const Input&) = delete;
		Input& operator=(const Input&) = delete;

		static bool IsKeyPressed(KeyCode key) { return s_Instance->IsKeyPressedImpl(key); }

		static bool IsMouseButtonPressed(MouseCode button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		static std::pair<float,float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(KeyCode key) = 0;
		virtual bool IsMouseButtonPressedImpl(MouseCode button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;

		static Scope<Input> Create();
	private:
		static Scope<Input> s_Instance;
	};
}
