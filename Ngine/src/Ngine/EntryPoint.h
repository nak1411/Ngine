#pragma once
#ifdef NE_PLATFORM_WINDOWS


extern Ngine::Application* Ngine::CreateApplication();

int main(int argc, char** argv)
{
	// Initialize logging
	Ngine::Log::Init();

	// Start app
	auto app = Ngine::CreateApplication();
	app->Run();

	// Clean-up app
	delete app;
}
#endif