#include "raylib.h"
#include "Core/Core.hpp"

int main()
{
	Core core(800, 600, "Game Engine", 60);

	core.Init();

	core.Run();

	core.DeInit();

	return 0;
}