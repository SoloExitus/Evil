#pragma once

namespace Evil
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define EVIL_MOUSE_BUTTON_0         ::Evil::Mouse::Button0
#define EVIL_MOUSE_BUTTON_1         ::Evil::Mouse::Button1
#define EVIL_MOUSE_BUTTON_2         ::Evil::Mouse::Button2
#define EVIL_MOUSE_BUTTON_3         ::Evil::Mouse::Button3
#define EVIL_MOUSE_BUTTON_4         ::Evil::Mouse::Button4
#define EVIL_MOUSE_BUTTON_5         ::Evil::Mouse::Button5
#define EVIL_MOUSE_BUTTON_6         ::Evil::Mouse::Button6
#define EVIL_MOUSE_BUTTON_7         ::Evil::Mouse::Button7
#define EVIL_MOUSE_BUTTON_LAST      ::Evil::Mouse::ButtonLast
#define EVIL_MOUSE_BUTTON_LEFT      ::Evil::Mouse::ButtonLeft
#define EVIL_MOUSE_BUTTON_RIGHT     ::Evil::Mouse::ButtonRight
#define EVIL_MOUSE_BUTTON_MIDDLE    ::Evil::Mouse::ButtonMiddle