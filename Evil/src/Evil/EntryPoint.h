#pragma once

#ifdef EVIL_PLATFORM_WINDOWS

extern Evil::Application* Evil::CreateApplication();

int main(int argc, char** argv)
{
	Evil::Log::Init();
	EVIL_CORE_WARN("Initialized Log!");
	int a = 5;
	EVIL_CORE_INFO("Hello! Var = {0}",a);

	auto app = Evil::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif //EVIL_PLATFORM_WINDOWS
