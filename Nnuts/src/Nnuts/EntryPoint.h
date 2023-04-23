#pragma once

#ifdef NN_PLATFORM_WINDOWS

extern Nnuts::Application* Nnuts::CreateApplication();

int main(int argc, char** argv) {
	std::cout << "Nnuts Engine v0.1 alpha" << std::endl;

	auto app = Nnuts::CreateApplication();
	app->Run();
	delete app;
}

#endif