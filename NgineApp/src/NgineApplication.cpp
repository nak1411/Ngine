#include <Ngine.h>

class NgineApp : public Ngine::Application

{
public:
	NgineApp()
	{

	}

	~NgineApp()
	{

	}
};

Ngine::Application* Ngine::CreateApplication()
{
	return new NgineApp();
}