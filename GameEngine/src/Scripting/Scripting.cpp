#include "Scripting.hpp"
#include "../Core/Core.hpp"

sol::state& Scripting::getLua()
{
	return this->lua;
}

void Scripting::init(Core& core)
{
	lua.open_libraries(sol::lib::base);

	core.expose(this->lua);
}