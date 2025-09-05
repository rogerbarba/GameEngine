#pragma once

#include "sol/sol.hpp"

// Forward declaration to avoid infinite loop with Core.hpp
class Core;

class Scripting
{
private:
	sol::state lua;

public:
	sol::state& getLua();

	void init(Core& core);

	void load();
};