#include <Evil.h>
#include <Evil/Core/EntryPoint.h>

#include "SandBox2D.h"
#include "ExampleLayer.h"

class SandBox : public Evil::Application
{
public:
	SandBox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new SandBox2D());
	}
	~SandBox()
	{

	}
};

Evil::Application* Evil::CreateApplication() 
{
	return new SandBox();
}