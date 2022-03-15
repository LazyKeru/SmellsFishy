#include "../../header/regex/regex.hpp"
#include "../../header/util/util.hpp"

bool Regex::search(const std::string& regex, const std::string& string, MatchFlags flags)
{
	return std::regex_search(string, std::regex(regex), std::regex_constants::match_flag_type(flags));
}

bool Regex::match(const std::string& regex, const std::string& string, MatchFlags flags)
{
	return std::regex_match(string, std::regex(regex), std::regex_constants::match_flag_type(flags));
}

std::vector<std::string> Regex::findAll(const std::string& regex, const std::string& string, MatchFlags flags)
{
	std::regex r(regex);
	std::sregex_iterator begin(string.begin(), string.end(), r);
	std::sregex_iterator end;

	std::vector<std::string> v;
	v.reserve(std::distance(begin, end));

	for (auto& s = begin; s != end; s++)
		v.push_back(s->str());

	return v;
}

Regex::MatchFlags operator+(const Regex::MatchFlags& first, const Regex::MatchFlags& last)
{
	return static_cast<Regex::MatchFlags>(static_cast<int>(first) | static_cast<int>(last));
}