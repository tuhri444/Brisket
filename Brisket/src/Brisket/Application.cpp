  #include "Application.h"

#include "Brisket/Events/ApplicationEvent.h"
#include "Brisket/Log.h"

namespace Brisket {

	Application::Application()
	{

	}
	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 1720);
		BK_CORE_TRACE(e);
		while (true);
	}
}