#include <Brisket.h>

class Sandbox :public Brisket::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox() 
	{

	}
};

Brisket::Application* Brisket::CreateApplication()
{
	return new Sandbox;
}