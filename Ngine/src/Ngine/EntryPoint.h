#pragma once

#ifdef NG_PLATFORM_WINDOWS

extern Ngine::Application* Ngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Ngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
