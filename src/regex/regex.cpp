#include "../../header/regex/regex.hpp"
#include "../../header/util/util.hpp"

std::vector<std::string> Regex::process(StringRef regex, StringRef string, MatchFlags flags)
{
	Regex r;

	r.setString(string);
	r.setRegex(regex);
	r.setFlags(flags);

	return r.findAll();
}

bool Regex::search()
{
	assertConfig();
	return std::regex_search(string, regex, std::regex_constants::match_flag_type(currentFlags));
}

bool Regex::match()
{
	assertConfig();
	return std::regex_match(string, regex, std::regex_constants::match_flag_type(currentFlags));
}

std::vector<std::string> Regex::findAll()
{
	assertConfig();

	std::sregex_iterator begin(string.begin(), string.end(), regex);
	std::sregex_iterator end;

	std::vector<std::string> v;
	v.reserve(std::distance(begin, end));

	for (auto& s = begin; s != end; s++)
		v.push_back(s->str());

	return v;
}

void Regex::setFlags(MatchFlags f)
{
	currentFlags = f;
}

void Regex::addFlags(MatchFlags f)
{
	currentFlags = currentFlags + f;
}

void Regex::assertConfig()
{
	myAssert(!string.empty() && !regex._Empty(), "No character string or no regex loaded");
}

Regex::MatchFlags operator+(const Regex::MatchFlags& first, const Regex::MatchFlags& last)
{
	return static_cast<Regex::MatchFlags>(static_cast<int>(first) | static_cast<int>(last));
}