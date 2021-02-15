#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include "PushdownAutomata.h"

int main() {
	std::vector<std::pair<UnionType, UnionReduction>> ruleVector(0);
	ruleVector.push_back({ NonterminalType::BEGIN, {{NonterminalType::EXPR}, nullptr} });
	ruleVector.push_back({ NonterminalType::EXPR, {{TokenType::VAR, TokenType::EQUAL, NonterminalType::E}, nullptr} });
	ruleVector.push_back({ NonterminalType::EXPR, {{NonterminalType::E}, nullptr} });
	ruleVector.push_back({ NonterminalType::E , { {NonterminalType::E, TokenType::PLUS, NonterminalType::T}, nullptr } });
	ruleVector.push_back({ NonterminalType::E , { {NonterminalType::E, TokenType::MINUS, NonterminalType::T}, nullptr } });
	ruleVector.push_back({ NonterminalType::E , { {NonterminalType::T}, nullptr } });
	ruleVector.push_back({ NonterminalType::T , { {NonterminalType::T, TokenType::MULT, NonterminalType::F}, nullptr } });
	ruleVector.push_back({ NonterminalType::T , { {NonterminalType::T, TokenType::DIV, NonterminalType::F}, nullptr } });
	ruleVector.push_back({ NonterminalType::T , { {NonterminalType::F}, nullptr } });
	ruleVector.push_back({ NonterminalType::F , { {TokenType::LPAREN, NonterminalType::E, TokenType::RPAREN}, nullptr } });
	ruleVector.push_back({ NonterminalType::F , { {TokenType::NUM}, nullptr } });
	ruleVector.push_back({ NonterminalType::F , { {TokenType::VAR}, nullptr } });

	PushdownAutomata pa(ruleVector);

	return 0;
}