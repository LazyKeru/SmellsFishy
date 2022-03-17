#pragma once
#include <random>

#ifndef NDEBUG
#   define myAssert(Condition, Error_Message) \
    _myAssert(#Condition, Error_Message, Condition, __FILE__, __LINE__)
#else
#   define myAssert(Expr, Msg) ;
#endif

/**
 * @brief 
 * 
 * @param expected_expression pointer to a char table. Tells the user the expected expression
 * @param error_message pointer to a char table. The error message if the condition is false
 * @param condition bool. If it is false, than the error message appears.
 * @param file pointer to a char table. The file location
 * @param line pointer to a char table. The line _myAssert was called
 */
void _myAssert(const char* expected_expression, const char* error_message, bool condition, const char* file, int line);

template <typename T>
T randomValue(T min, T max)
{
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}