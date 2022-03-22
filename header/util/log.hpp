#include <iostream>
#include <filesystem>

namespace Log
{
    class CustomLog
    {
    public:
        CustomLog(std::ostream &out, const std::string &filePath, const std::string &messageType) : output(out)
        {
            before = '[' + std::filesystem::path(filePath).filename().string() + "] " + messageType + '\t';
        }

        template <typename T>
        std::ostream &operator<<(T other)
        {
            return output << before << other;
        }

    private:
        std::ostream &output;
        std::string before;
    };
}

#define INIT_LOG                                                          \
    static Log::CustomLog log_msg(std::clog, __FILE__, "   Message:  ");  \
    static Log::CustomLog log_warn(std::clog, __FILE__, " < Warning > "); \
    static Log::CustomLog log_err(std::clog, __FILE__, "<<< ERROR >>>");
