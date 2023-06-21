#include <Nnuts.h>

// test code for the glm library

//#include <glm/vec3.hpp>
//#include <glm/vec4.hpp>
//#include <glm/mat4x4.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//glm::mat4 camera(float Translate, glm::vec2 const& Rotate) {
//	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.f);
//	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
//	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
//	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
//	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
//	return Projection * View * Model;
//}

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
		PushLayer(new Nnuts::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Nnuts::Application* Nnuts::CreateApplication() {
	return new Sandbox();
}