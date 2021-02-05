#pragma once

namespace Evil
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}


/* Printable keys form glfw.h */
#define EVIL_KEY_SPACE              ::Evil::Key::Space
#define EVIL_KEY_APOSTROPHE         ::Evil::Key::Apostrophe  /* ' */
#define EVIL_KEY_COMMA              ::Evil::Key::Comma  /* , */
#define EVIL_KEY_MINUS              ::Evil::Key::Minus  /* - */
#define EVIL_KEY_PERIOD             ::Evil::Key::Period  /* . */
#define EVIL_KEY_SLASH              ::Evil::Key::Slash  /* / */
#define EVIL_KEY_0                  ::Evil::Key::D0
#define EVIL_KEY_1                  ::Evil::Key::D1
#define EVIL_KEY_2                  ::Evil::Key::D2
#define EVIL_KEY_3                  ::Evil::Key::D3
#define EVIL_KEY_4                  ::Evil::Key::D4
#define EVIL_KEY_5                  ::Evil::Key::D5
#define EVIL_KEY_6                  ::Evil::Key::D6
#define EVIL_KEY_7                  ::Evil::Key::D7
#define EVIL_KEY_8                  ::Evil::Key::D8
#define EVIL_KEY_9                  ::Evil::Key::D9
#define EVIL_KEY_SEMICOLON          ::Evil::Key::Semicon  /* ; */
#define EVIL_KEY_EQUAL              ::Evil::Key::Equal  /* = */
#define EVIL_KEY_A                  ::Evil::Key::A
#define EVIL_KEY_B                  ::Evil::Key::B
#define EVIL_KEY_C                  ::Evil::Key::C
#define EVIL_KEY_D                  ::Evil::Key::D
#define EVIL_KEY_E                  ::Evil::Key::E
#define EVIL_KEY_F                  ::Evil::Key::F
#define EVIL_KEY_G                  ::Evil::Key::G
#define EVIL_KEY_H                  ::Evil::Key::H
#define EVIL_KEY_I                  ::Evil::Key::I
#define EVIL_KEY_J                  ::Evil::Key::J
#define EVIL_KEY_K                  ::Evil::Key::K
#define EVIL_KEY_L                  ::Evil::Key::L
#define EVIL_KEY_M                  ::Evil::Key::M
#define EVIL_KEY_N                  ::Evil::Key::N
#define EVIL_KEY_O                  ::Evil::Key::O
#define EVIL_KEY_P                  ::Evil::Key::P
#define EVIL_KEY_Q                  ::Evil::Key::Q
#define EVIL_KEY_R                  ::Evil::Key::R
#define EVIL_KEY_S                  ::Evil::Key::S
#define EVIL_KEY_T                  ::Evil::Key::T
#define EVIL_KEY_U                  ::Evil::Key::U
#define EVIL_KEY_V                  ::Evil::Key::V
#define EVIL_KEY_W                  ::Evil::Key::W
#define EVIL_KEY_X                  ::Evil::Key::X
#define EVIL_KEY_Y                  ::Evil::Key::Y
#define EVIL_KEY_Z                  ::Evil::Key::Z
#define EVIL_KEY_LEFT_BRACKET       ::Evil::Key::LeftBracket  /* [ */
#define EVIL_KEY_BACKSLASH          ::Evil::Key::Backslash  /* \ */
#define EVIL_KEY_RIGHT_BRACKET      ::Evil::Key::RightBracket  /* ] */
#define EVIL_KEY_GRAVE_ACCENT       ::Evil::Key::GraveAccent  /* ` */
#define EVIL_KEY_WORLD_1            ::Evil::Key::World1 /* non-US #1 */
#define EVIL_KEY_WORLD_2            ::Evil::Key::World2 /* non-US #2 */

/* Function keys */
#define EVIL_KEY_ESCAPE             ::Evil::Key::Escape
#define EVIL_KEY_ENTER              ::Evil::Key::Enter
#define EVIL_KEY_TAB                ::Evil::Key::Tab
#define EVIL_KEY_BACKSPACE          ::Evil::Key::Backspace
#define EVIL_KEY_INSERT             ::Evil::Key::Insert
#define EVIL_KEY_DELETE             ::Evil::Key::Delete
#define EVIL_KEY_RIGHT              ::Evil::Key::Right
#define EVIL_KEY_LEFT               ::Evil::Key::Left
#define EVIL_KEY_DOWN               ::Evil::Key::Down
#define EVIL_KEY_UP                 ::Evil::Key::Up
#define EVIL_KEY_PAGE_UP            ::Evil::Key::PageUp
#define EVIL_KEY_PAGE_DOWN          ::Evil::Key::PageDown
#define EVIL_KEY_HOME               ::Evil::Key::Home
#define EVIL_KEY_END                ::Evil::Key::End
#define EVIL_KEY_CAPS_LOCK          ::Evil::Key::CapsLock
#define EVIL_KEY_SCROLL_LOCK        ::Evil::Key::ScrollLock
#define EVIL_KEY_NUM_LOCK           ::Evil::Key::NumLock
#define EVIL_KEY_PRINT_SCREEN       ::Evil::Key::PrintScreen
#define EVIL_KEY_PAUSE              ::Evil::Key::Pause
#define EVIL_KEY_F1                 ::Evil::Key::F1
#define EVIL_KEY_F2                 ::Evil::Key::F2
#define EVIL_KEY_F3                 ::Evil::Key::F3
#define EVIL_KEY_F4                 ::Evil::Key::F4
#define EVIL_KEY_F5                 ::Evil::Key::F5
#define EVIL_KEY_F6                 ::Evil::Key::F6
#define EVIL_KEY_F7                 ::Evil::Key::F7
#define EVIL_KEY_F8                 ::Evil::Key::F8
#define EVIL_KEY_F9                 ::Evil::Key::F9
#define EVIL_KEY_F10                ::Evil::Key::F10
#define EVIL_KEY_F11                ::Evil::Key::F11
#define EVIL_KEY_F12                ::Evil::Key::F12
#define EVIL_KEY_F13                ::Evil::Key::F13
#define EVIL_KEY_F14                ::Evil::Key::F14
#define EVIL_KEY_F15                ::Evil::Key::F15
#define EVIL_KEY_F16                ::Evil::Key::F16
#define EVIL_KEY_F17                ::Evil::Key::F17
#define EVIL_KEY_F18                ::Evil::Key::F18
#define EVIL_KEY_F19                ::Evil::Key::F19
#define EVIL_KEY_F20                ::Evil::Key::F20
#define EVIL_KEY_F21                ::Evil::Key::F21
#define EVIL_KEY_F22                ::Evil::Key::F22
#define EVIL_KEY_F23                ::Evil::Key::F23
#define EVIL_KEY_F24                ::Evil::Key::F24
#define EVIL_KEY_F25                ::Evil::Key::F25

/* Keypad */
#define EVIL_KEY_KP_0               ::Evil::Key::KP0
#define EVIL_KEY_KP_1               ::Evil::Key::KP1
#define EVIL_KEY_KP_2               ::Evil::Key::KP2
#define EVIL_KEY_KP_3               ::Evil::Key::KP3
#define EVIL_KEY_KP_4               ::Evil::Key::KP4
#define EVIL_KEY_KP_5               ::Evil::Key::KP5
#define EVIL_KEY_KP_6               ::Evil::Key::KP6
#define EVIL_KEY_KP_7               ::Evil::Key::KP7
#define EVIL_KEY_KP_8               ::Evil::Key::KP8
#define EVIL_KEY_KP_9               ::Evil::Key::KP9
#define EVIL_KEY_KP_DECIMAL         ::Evil::Key::KPDecimal
#define EVIL_KEY_KP_DIVIDE          ::Evil::Key::KPDivide
#define EVIL_KEY_KP_MULTIPLY        ::Evil::Key::KPMultiply
#define EVIL_KEY_KP_SUBTRACT        ::Evil::Key::KPSubtract
#define EVIL_KEY_KP_ADD             ::Evil::Key::KPAdd
#define EVIL_KEY_KP_ENTER           ::Evil::Key::KPEnter
#define EVIL_KEY_KP_EQUAL           ::Evil::Key::KPEqual

#define EVIL_KEY_LEFT_SHIFT         ::Evil::Key::LeftShift
#define EVIL_KEY_LEFT_CONTROL       ::Evil::Key::LeftControl
#define EVIL_KEY_LEFT_ALT           ::Evil::Key::LeftAlt
#define EVIL_KEY_LEFT_SUPER         ::Evil::Key::LeftSuper
#define EVIL_KEY_RIGHT_SHIFT        ::Evil::Key::RightShift
#define EVIL_KEY_RIGHT_CONTROL      ::Evil::Key::RightControl
#define EVIL_KEY_RIGHT_ALT          ::Evil::Key::RightAlt
#define EVIL_KEY_RIGHT_SUPER        ::Evil::Key::RightSuper
#define EVIL_KEY_MENU               ::Evil::Key::Menu