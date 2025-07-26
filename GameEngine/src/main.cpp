#include "Core/Core.hpp"

int main()
{
	Core core(800, 600, "Game Engine", 60);

	core.run();

	return 0;
}