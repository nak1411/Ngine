#include <Ngine.h>

class Testbox : public Ngine::Application
{
public:
	Testbox()
	{

	}

	~Testbox()
	{

	}

};

Ngine::Application* Ngine::CreateApplication()
{
	return new Testbox();
}