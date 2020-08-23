#pragma once
#ifdef BK_PLATFORM_WINDOWS

extern Brisket::Application* Brisket::CreateApplication();

int main(int argc, char** argv)
{
	Brisket::Log::Init();
	BK_CORE_WARN("Initialized Log");
	int a = 2;
	BK_INFO("Initialized Client Log, Var= {0}", a);

	auto app = Brisket::CreateApplication();
	app->Run();
	delete app;
}
#endif