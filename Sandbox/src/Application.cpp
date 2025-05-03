#include <Pixelyn.h>

class Sandbox : public Pixelyn::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Pixelyn::Application* Pixelyn::CreateApplication()
{
	return new Sandbox();
}