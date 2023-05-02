#pragma once

#ifdef NN_PLATFORM_WINDOWS

extern Nnuts::Application* Nnuts::CreateApplication();

int main(int argc, char** argv) {
	Nnuts::Log::Init();
	NN_CORE_WARN("Logger Initialized!");
	int a = 5;
	NN_INFO("Heya! Var={0}", a);

	std::cout << "Nnuts Engine v0.1 alpha" << std::endl;

	auto app = Nnuts::CreateApplication();
	app->Run();
	delete app;
}

#endif