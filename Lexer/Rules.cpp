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

std::multimap<NonterminalType, UnionReduction> reduction_map(std::vector<std::pair<NonterminalType, UnionReduction>> reductions) {
	std::multimap<NonterminalType, UnionReduction> res;
	for (auto i : reductions) {
		res.insert(i);
	}
	return res;
}

std::vector<std::map<NonterminalType, PushdownCommand>> state_transition_map(std::multimap<NonterminalType, UnionReduction> reducemap) {
	std::vector<std::map<NonterminalType, PushdownCommand>> res(0);
	std::queue<std::vector<MarkedReduction>> StateBuffer;
	std::vector<std::vector<MarkedReduction>> States;
	return res;
}

std::vector<MarkedReduction> setmarkedreduction(std::multimap<NonterminalType, UnionReduction> reducemap) {
	std::vector<MarkedReduction> test(0);
	int count = 1;
	NonterminalType ind = NonterminalType::BEGIN;
	std::queue<NonterminalType> nonterminalBuffer;
	while (count != 0) {
		count = 0;
		for (auto i = reducemap.lower_bound(ind); i != reducemap.upper_bound(ind); i++) {
			auto j = find(test.begin(), test.end(), MarkedReduction((*i).second, 0));
			if (j != test.end()) {
				test.push_back(MarkedReduction((*i).second, 0));
				auto Type = (*i).second.ReductionRule[0].getType();
				UnionType_raw rowtype;
				bool isterminal;
				Type.getType(rowtype, isterminal);
				if (!isterminal) {
					nonterminalBuffer.push(rowtype.nt);
				}
				count++;
			}
		}
		count += nonterminalBuffer.size();
		if (!nonterminalBuffer.empty()) {
			ind = nonterminalBuffer.front();
			nonterminalBuffer.pop();
		}
	}
	return test;
}