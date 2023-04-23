#include <Nnuts.h>

class Sandbox : public Nnuts::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Nnuts::Application* Nnuts::CreateApplication() {
	return new Sandbox();
}