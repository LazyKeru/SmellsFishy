#include "../../header/util/argument.hpp"

Argument::Argument(bool needInput, std::string flag[2]) : defined(false), needInput(needInput), flag{flag[0], flag[1]}
{
}

Argument::Argument(bool _needInput, std::string _flag, std::string _flagSuffix) : defined(false), needInput(_needInput), flag{_flag, _flagSuffix}
{
}