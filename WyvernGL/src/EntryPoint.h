#pragma once

extern Wyvern::Application* Wyvern::createApplication();

int main(int argc, char** argv) 
{
	auto app = Wyvern::createApplication();
	app->run();
	delete app;
}