#pragma once

#include <string>
#include "../Input/Input.hpp"

class Core
{
private:
	int windowWidth;
	int windowHeight;
	std::string windowTitle;
	int targetFPS;

	void Update();
	void Draw();

	Input input;

public:
	Core(int windowWidth, int windowHeight, std::string windowTitle, int targetFPS);

	void Init();

	void Run();

	void DeInit();
};