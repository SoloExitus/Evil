
#include <Evil.h>

class SandBox : public Evil::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}
};

Evil::Application* Evil::CreateApplication() 
{
	return new SandBox();
}