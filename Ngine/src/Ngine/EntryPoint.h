#pragma once
#ifdef NE_PLATFORM_WINDOWS

extern Ngine::Application* Ngine::CreateApplication();

int main(int arc, char** argv)
{
	auto app = Ngine::CreateApplication();
	app->Run();
	delete app;
}
#endif