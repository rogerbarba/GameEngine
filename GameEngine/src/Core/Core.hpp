#pragma once

#include <string>

class Core
{
private:
	int windowWidth;
	int windowHeight;
	std::string windowTitle;
	int targetFPS;

	void Update();
	void Draw();

public:
	Core(int windowWidth, int windowHeight, std::string windowTitle, int targetFPS);

	void Init();

	void Run();

	void DeInit();
};