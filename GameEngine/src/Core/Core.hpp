#pragma once

#include <string>
#include "../Input/Input.hpp"
#include "../ResourceManager/ResourceManager.hpp"

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
	ResourceManager resourceManager;

public:
	Core(int windowWidth, int windowHeight, std::string windowTitle, int targetFPS);

	void Init();

	void Run();

	void DeInit();
};