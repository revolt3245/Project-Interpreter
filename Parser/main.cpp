#include <iostream>

#include "Rules.h"
#include "PushdownAutomata.h"

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

	PushdownAutomata pa(ruleVector);
	std::queue<UnionToken> TokenQueue;
	TokenQueue.push(UnionToken(TokenType::NUM));
	TokenQueue.push(UnionToken(TokenType::MULT));
	TokenQueue.push(UnionToken(TokenType::LPAREN));
	TokenQueue.push(UnionToken(TokenType::VAR));
	TokenQueue.push(UnionToken(TokenType::PLUS));
	TokenQueue.push(UnionToken(TokenType::NUM));
	TokenQueue.push(UnionToken(TokenType::RPAREN));
	TokenQueue.push(UnionToken(TokenType::MINUS));
	TokenQueue.push(UnionToken(TokenType::VAR));
	TokenQueue.push(UnionToken(TokenType::DIV));
	TokenQueue.push(UnionToken(TokenType::VAR));
	TokenQueue.push(UnionToken(TokenType::LAST));
	std::vector<UnionToken> TokenStack(0);
	std::vector<int> StateStack(1);

	bool isComplete = false;

	auto commands = pa.getCommands();

	do {
		system("CLS");
		isComplete = pa.Step(TokenQueue, TokenStack, StateStack);
		std::cout << "TokenQueue" << std::endl;
		auto QueueSize = TokenQueue.size();
		if (QueueSize > 0) {
			for (auto i = 0; i < QueueSize; i++) {
				auto val = TokenQueue.front();
				std::cout << val << " ";
				TokenQueue.pop();
				TokenQueue.push(val);
			}
		}
		std::cout << std::endl;
		std::cout << "TokenStack" << std::endl;
		for (auto i = 0; i < TokenStack.size(); i++) {
			std::cout << TokenStack[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "StateStack" << std::endl;
		for (auto i = 0; i < StateStack.size(); i++) {
			std::cout << StateStack[i] << " ";
		}
		std::cout << std::endl;
	} while (!isComplete);

	std::cout << std::endl;
	std::cout << "Accepted" << std::endl;

	return 0;
}