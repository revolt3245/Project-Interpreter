#include "Rules.h"

std::map<TokenType, std::regex> regex_map(std::vector<std::regex> regex) {
	auto regexData = regex.data();
	std::map<TokenType, std::regex> res;
	for (TokenType i = TokenType::BEGIN; i != TokenType::eof; ++i) {
		std::pair<TokenType, std::regex> p(i, *regexData);
		res.insert(p);
		regexData++;
	}
	return res;
}