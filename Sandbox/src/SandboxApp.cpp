
#include <Evil.h>

class ExampleLayer : public Evil::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//EVIL_INFO("ExampleLayer::Update");

		if (Evil::Input::IsKeyPressed(EVIL_KEY_TAB))
			EVIL_TRACE("Tab kay is pressed (poll)!")

	}

	void OnEvent(Evil::Event& event) override
	{
		//EVIL_TRACE("{0}", event);

		if (event.GetEventType() == Evil::EventType::KeyPressed)
		{
			Evil::KeyPressedEvent& e = (Evil::KeyPressedEvent&)event;
			if (e.GetKeyCode() == EVIL_KEY_TAB)
				EVIL_TRACE("Tab kay is pressed (event)!")
			EVIL_TRACE("{0}", (char)e.GetKeyCode());
		}
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