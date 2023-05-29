#include <Nnuts.h>

// This is how a layer will be created and implemented in an app

class ExampleLayer : public Nnuts::Layer {
public:
	ExampleLayer()
		: Layer("Exmaple") {}

	void OnUpdate() override {
		NN_INFO("ExampleLayer::Update");
	}

	void OnEvent(Nnuts::Event& event) override {
		NN_TRACE("{0}", event);
	}
};

class Sandbox : public Nnuts::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

Nnuts::Application* Nnuts::CreateApplication() {
	return new Sandbox();
}