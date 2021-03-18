#pragma once

#include "Evil/Core/Base.h"
#include "Evil/Core/KeyCodes.h"
#include "Evil/Core/MouseCodes.h"

namespace Evil
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	
	};
}
