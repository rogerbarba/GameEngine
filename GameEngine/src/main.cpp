#include "Core/Core.hpp"

int main()
{
	Core core(800, 600, "Game Engine", 60);

	core.init();

	core.run();

	core.deInit();

	return 0;
}