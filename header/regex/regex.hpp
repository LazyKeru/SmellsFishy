#pragma once
#include <regex>
#include <string>
#include <cassert>

namespace Regex
{
	// Flags specifying the matches we are looking for. Add them with the + operator
	enum class MatchFlags : int
	{
		// The first character in [first,last) will be treated as if it is not at 
		// the beginning of a line (i.e. ^ will not match [first,first)
		notBeginningOfLine = 0x0000,	

		// The last character in[first, last) will be treated as if it is not at 
		// the end of a line(i.e.$ will not match[last, last)
		notEndOfLine = 0x0001,	

		// "\b" will not match [first,first)
		notBeginningOfWord = 0x0002,	

		// "\b" will not match [last,last)
		notEndOfWord = 0x0004,	

		// If more than one match is possible, then any match is an acceptable result
		any = 0x0008,	

		// Do not match empty sequences
		notNull = 0x0010,	

		// Only match a sub-sequence that begins at first
		continuous = 0x0020,	

		// --first is a valid iterator position. When set, causes notBeginningOfLine 
		// and notBeginningOfWord to be ignored
		prevAvailable = 0x0040,	
	};

	std::vector<std::string> process(const std::string& regex, const std::string& string, MatchFlags flags = MatchFlags(0));

	/// <summary>
	/// returns true if the regex matches for a part of the string 
	/// <para>example: regex = gr(a|e)y : "grey" -> true | "is grey" -> true</para>
	/// </summary>
	bool search(const std::string& regex, const std::string& string, MatchFlags flags = MatchFlags(0));

	/// <summary>
	/// returns true if the regex matches for ALL the string 
	/// <para>example: regex = gr(a|e)y : "grey" -> true | "is grey" -> false</para>
	/// </summary>
	bool match(const std::string& regex, const std::string& string, MatchFlags flags = MatchFlags(0));

	/// <summary>
	/// returns all the matches
	/// </summary>
	/// <returns>
	/// returns a vector (a resizable array) elements can be accessed like a C array
	/// <para>ex: vector[i] = 0 | use .size() to get its size</para>
	/// </returns>
	
	std::vector<std::string> findAll(const std::string& regex, const std::string& string, MatchFlags flags = MatchFlags(0));


}

Regex::MatchFlags operator+(const Regex::MatchFlags& first, const Regex::MatchFlags& last);