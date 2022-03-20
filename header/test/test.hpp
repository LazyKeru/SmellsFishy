#pragma once
#include <string>

namespace test
{
    enum class logType
    {
        message,
        warning,
        error
    };
    void log(const std::string &messge, const std::string &filePath = "", logType log_type = logType::message);
    /**
     * @brief Test function for the regex function
     *
     * @return true
     * @return false
     */
    bool regex();
    /**
     * @brief Test function for the fileToString function
     *
     * @return true
     * @return false
     */
    bool files();
}