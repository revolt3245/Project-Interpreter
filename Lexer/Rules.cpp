#include "Rules.h"

typedef std::pair<UnionReduction, int> MarkedReduction;

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

std::multimap<UnionType, UnionReduction> reduction_map(std::vector<std::pair<UnionType, UnionReduction>> reductions) {
	std::multimap<UnionType, UnionReduction> res;
	for (auto i : reductions) {
		res.insert(i);
	}
	return res;
}

std::vector<std::map<UnionType, PushdownCommand>> state_transition_map(std::multimap<UnionType, UnionReduction> reducemap) {
	std::vector<std::map<UnionType, PushdownCommand>> res(0);
	std::queue<std::vector<MarkedReduction>> StateBuffer;
	return res;
}

//MarkedReduction SetMarkedReduction(std::multimap<UnionType, UnionReduction> reducemap) {
//	return;
//}