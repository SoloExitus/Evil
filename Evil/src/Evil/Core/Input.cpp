#include "evilpch.h"
#include "Evil/Core/Input.h"

#ifdef EVIL_PLATFORM_WINDOWS
	#include "Evil/Platform/Windows/WindowsInput.h"
#endif

namespace Evil 
{

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
		#ifdef EVIL_PLATFORM_WINDOWS
			return CreateScope<WindowsInput>();
		#else
			EVIL_CORE_ASSERT(false, "Unknown platform!");
			return nullptr;
		#endif
	}
}