#include <Ngine.h>

#include"Ngine/EntryPoint.h"

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