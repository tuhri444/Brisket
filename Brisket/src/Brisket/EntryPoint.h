#pragma once
#ifdef BK_PLATFORM_WINDOWS

extern Brisket::Application* Brisket::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Brisket::CreateApplication();
	app->Run();
	delete app;
}
#endif