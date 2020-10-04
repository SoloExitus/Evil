
#include <Evil.h>

class ExampleLayer : public Evil::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{}

	void OnUpdate() override
	{
		EVIL_INFO("ExampleLayer::Update");
	}

	void OnEvent(Evil::Event& event) override
	{
		EVIL_TRACE("{0}", event);
	}
};

class SandBox : public Evil::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Evil::ImGuiLayer());
	}
	~SandBox()
	{

	}
};

Evil::Application* Evil::CreateApplication() 
{
	return new SandBox();
}