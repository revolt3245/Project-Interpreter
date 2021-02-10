#include <iostream>

#include "Rules.h"

int main() {
	std::vector<std::pair<UnionType, UnionReduction>> ruleVector(0);
	ruleVector.push_back({ NonterminalType::BEGIN, {{NonterminalType::E}, nullptr} });
	ruleVector.push_back({ NonterminalType::E , { {NonterminalType::E, TokenType::PLUS, NonterminalType::T}, nullptr } });
	ruleVector.push_back({ NonterminalType::E , { {NonterminalType::E, TokenType::MINUS, NonterminalType::T}, nullptr } });
	ruleVector.push_back({ NonterminalType::E , { {NonterminalType::T}, nullptr } });
	ruleVector.push_back({ NonterminalType::T , { {NonterminalType::T, TokenType::MULT, NonterminalType::F}, nullptr } });
	ruleVector.push_back({ NonterminalType::T , { {NonterminalType::T, TokenType::DIV, NonterminalType::F}, nullptr } });
	ruleVector.push_back({ NonterminalType::T , { {NonterminalType::F}, nullptr } });
	ruleVector.push_back({ NonterminalType::F , { {TokenType::LPAREN, NonterminalType::E, TokenType::RPAREN}, nullptr } });
	ruleVector.push_back({ NonterminalType::F , { {TokenType::NUM}, nullptr } });
	ruleVector.push_back({ NonterminalType::F , { {TokenType::VAR}, nullptr } });

	auto r_map = ReduceMap(ruleVector);
	auto m_map = ReduceMapToMarkedMap(r_map);
	auto Pushdown = PushdownStateTransition(r_map);
	auto s1 = NextState(r_map, m_map, NonterminalType::E);
	auto nToken = NextToken(r_map, s1);

	for (auto i = m_map.begin(); i != m_map.end(); i++) {
		std::cout << (*i).first << " : " << (*i).second << std::endl;
	}
	std::cout << std::endl;
	for (auto i : nToken) {
		std::cout << i << std::endl;
	}
	int count = 0;
	for (auto i : Pushdown) {
		std::cout << "State " << count++ << std::endl;
		for (auto j = i.begin(); j != i.end(); j++) {
			std::cout << (*j).first << " " << (*j).second << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}