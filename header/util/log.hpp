#pragma once
/************************/
/**      Includes      **/
/************************/
#include <iostream>
#include <filesystem>

namespace Log
{
    class CustomLog
    {
    public:
        /**
         * @brief Construct a new Custom Log object
         * 
         * @param out The messages that will be outputted
         * @param filePath The path to the file calling this function
         * @param messageType The type of the message
         */
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

#define INIT_LOG                                                        \
    namespace Log                                                       \
    {                                                                   \
        /** 
         * @brief Normal message
         * @example Log::msg << "This is a normal message";
         */                                                             \
        static CustomLog msg(std::clog, __FILE__, "   Message:  ");     \
        /**
         * @brief Warning message
         * @example Log::warn << "This is a warning message";
         */                                                             \
        static CustomLog warn(std::clog, __FILE__, " < Warning > ");    \
        /**
         * @brief Error message
         * @example Log::err << "This is an error message";
         */                                                             \
        static CustomLog err(std::clog, __FILE__, "<<< ERROR >>>");     \
    }