#include <Pixelyn.h>

class ExampleLayer : public Pixelyn::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		PX_INFO("ExampleLayer::Update");
	}

	void OnEvent(Pixelyn::Event& event) override
	{
		PX_TRACE("{0}", event.ToString());
	}

};

class Sandbox : public Pixelyn::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Pixelyn::Application* Pixelyn::CreateApplication()
{
	return new Sandbox();
}