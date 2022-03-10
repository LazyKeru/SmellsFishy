#pragma once
#include <string>
#include <cassert>

namespace util
{
	inline void assertCondition(bool condition, bool onlyInDebug = false)
	{
		if (onlyInDebug && !_DEBUG) return;

		assert(condition);
	}
}