#include <Evil.h>
#include <Evil/Core/EntryPoint.h>

#include "SandBox2D.h"

class SandBox : public Evil::Application
{
public:
	SandBox()
	{
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
