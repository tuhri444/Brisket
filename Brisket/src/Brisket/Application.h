#pragma once
#include "Core.h"

namespace Brisket
{
	class BRISKET_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}


