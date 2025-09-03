#include "Core/Core.hpp"

int main()
{
	Core core;

	core.init();

	core.run();

	core.deInit();

	return 0;
}