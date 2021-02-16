#include <iostream>
#include <vector>
#include <regex>
#include <thread>
#include <ctime>

#include "PushdownAutomata.h"
#include "FiniteStateMachine.h"
#include "Global Memory.h"

std::queue<UnionToken> GlobalQueue;
std::vector<UnionToken> GlobalQueueScope(0);
std::vector<UnionToken> GlobalTokenStack;
std::vector<int> GlobalStateStack(1);

UnionToken* GlobalTokenBuffer;
int* GlobalStateBuffer;

size_t TokenBufferSize;
size_t StateBufferSize;
std::string code = "var a123:int = 12 * (d + 3) - 23 / d5; a123 = 2;";
bool ParseComplete = false;
bool LexComplete = false;
bool recvFlag = false;
bool sendFlag = true;

FiniteStateMachine fsm;
PushdownAutomata pa;

clock_t delay = 0.05 * CLOCKS_PER_SEC;

void lex();
void parse();
void print();

int main() {
	std::vector<std::regex> regex_vec(0);
	regex_vec.push_back(std::regex("^[+]"));
	regex_vec.push_back(std::regex("^[-]"));
	regex_vec.push_back(std::regex("^[*]"));
	regex_vec.push_back(std::regex("^[/]"));
	regex_vec.push_back(std::regex("^[(]"));
	regex_vec.push_back(std::regex("^[)]"));
	regex_vec.push_back(std::regex("^[=]"));
	regex_vec.push_back(std::regex("^[;]"));
	regex_vec.push_back(std::regex("^[:]"));
	regex_vec.push_back(std::regex("^int"));
	regex_vec.push_back(std::regex("^double"));
	regex_vec.push_back(std::regex("^char"));
	regex_vec.push_back(std::regex("^var"));
	regex_vec.push_back(std::regex("^[0-9]+"));
	regex_vec.push_back(std::regex("^[A-Za-z_][A-Za-z0-9_]*"));
	
	fsm.set_Rules(regex_vec);

	std::vector<std::pair<UnionType, UnionReduction>> ruleVector(0);
	ruleVector.push_back({ NonterminalType::BEGIN, {{NonterminalType::PROGRAM}, nullptr} });

	ruleVector.push_back({ NonterminalType::PROGRAM, {{NonterminalType::PROGRAM, NonterminalType::EXE}, nullptr} });
	ruleVector.push_back({ NonterminalType::PROGRAM, {{NonterminalType::EXE}, nullptr} });

	ruleVector.push_back({ NonterminalType::EXE, {{NonterminalType::EXPR, TokenType::SEMICOLON}, nullptr} });

	ruleVector.push_back({ NonterminalType::EXPR, {{NonterminalType::DECLARE}, nullptr} });
	ruleVector.push_back({ NonterminalType::EXPR, {{NonterminalType::DECLARE, TokenType::EQUAL, NonterminalType::E}, nullptr} });
	ruleVector.push_back({ NonterminalType::EXPR, {{TokenType::VAR, TokenType::EQUAL, NonterminalType::E}, nullptr} });
	ruleVector.push_back({ NonterminalType::EXPR, {{NonterminalType::E}, nullptr} });

	ruleVector.push_back({ NonterminalType::DECLARE, {{TokenType::T_VAR, TokenType::VAR, TokenType::COLON, NonterminalType::TYPES}, nullptr} });

	ruleVector.push_back({ NonterminalType::TYPES, {{TokenType::T_INT}, nullptr} });
	ruleVector.push_back({ NonterminalType::TYPES, {{TokenType::T_DOUBLE}, nullptr} });
	ruleVector.push_back({ NonterminalType::TYPES, {{TokenType::T_CHAR}, nullptr} });

	ruleVector.push_back({ NonterminalType::E , { {NonterminalType::E, TokenType::PLUS, NonterminalType::T}, nullptr } });
	ruleVector.push_back({ NonterminalType::E , { {NonterminalType::E, TokenType::MINUS, NonterminalType::T}, nullptr } });
	ruleVector.push_back({ NonterminalType::E , { {NonterminalType::T}, nullptr } });

	ruleVector.push_back({ NonterminalType::T , { {NonterminalType::T, TokenType::MULT, NonterminalType::F}, nullptr } });
	ruleVector.push_back({ NonterminalType::T , { {NonterminalType::T, TokenType::DIV, NonterminalType::F}, nullptr } });
	ruleVector.push_back({ NonterminalType::T , { {NonterminalType::F}, nullptr } });

	ruleVector.push_back({ NonterminalType::F , { {TokenType::LPAREN, NonterminalType::E, TokenType::RPAREN}, nullptr } });
	ruleVector.push_back({ NonterminalType::F , { {TokenType::NUM}, nullptr } });
	ruleVector.push_back({ NonterminalType::F , { {TokenType::VAR}, nullptr } });

	pa.setRules(ruleVector);

	std::thread t1(lex);
	std::thread t2(parse);
	std::thread t3(print);

	t1.join();
	t2.join();
	t3.join();
}

void lex() {
	while (!LexComplete) {
		clock_t start = clock();
		Token x;
		if (fsm.step(code, x)) {
			GlobalQueue.push(x);
			if (x.getType() == TokenType::LAST) {
				LexComplete = true;
			}
		}
		while (clock() - start < delay);
	}
}

void parse() {
	while (!ParseComplete) {
		if (recvFlag) {
			recvFlag = false;
			ParseComplete = pa.Step(GlobalQueue, GlobalTokenStack, GlobalStateStack);

			sendFlag = true;
		}
	}
}

void print() {
	while (!LexComplete || !ParseComplete) {
		clock_t start = clock();
		system("CLS");
		std::cout << "Code" << std::endl;
		std::cout << code << std::endl;
		std::cout << std::endl;
		if (sendFlag) {
			sendFlag = false;
			std::cout << "TokenStack" << std::endl;
			for (auto i : GlobalTokenStack) {
				std::cout << i.getType() << " ";
			}
			std::cout << std::endl << std::endl;
			std::cout << "StateStack" << std::endl;
			for (auto i : GlobalStateStack) {
				std::cout << i << " ";
			}
			recvFlag = true;
		}
		while (clock() - start < delay);
	}
}