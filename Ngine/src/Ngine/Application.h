#pragma once

#include "Core.h"

namespace Ngine {

	class NGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// TODO in CLient
	Application* CreateApplication();
}

