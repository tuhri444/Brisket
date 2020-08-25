#pragma once
#ifdef BK_PLATFORM_WINDOWS

extern Brisket::Application* Brisket::CreateApplication();

int main(int argc, char** argv)
{
	Brisket::Log::Init();
	BK_CORE_WARN("Initialized Log");
	BK_WARN("Initialized Client Log");

	auto app = Brisket::CreateApplication();
	app->Run();
	delete app;
}
#endif