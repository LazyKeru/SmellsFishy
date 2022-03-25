#include "../../header/util/argument.hpp"

Argument::Argument(bool needInput, std::string flag[2]) : defined(true), needInput(needInput), flag{flag[0], flag[1]}
{
}