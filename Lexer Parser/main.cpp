#include <iostream>
#include <vector>
#include <regex>
#include <thread>
#include <ctime>

#include "PushdownAutomata.h"
#include "FiniteStateMachine.h"
#include "Global Memory.h"
#include "Initialize.h"

std::string code = "var test1:int = 12; var test2:int = 3; test1 + test2;";

clock_t delay = 0.05 * CLOCKS_PER_SEC;

void lex();
void parse();
void print();

int main() {
	std::vector<std::regex> regex_vec(0);
	std::vector<std::pair<UnionType, UnionReduction>> ruleVector(0);

	Initialize(regex_vec, ruleVector);

	fsm.set_Rules(regex_vec);
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
			std::cout << std::endl << std::endl;
			std::cout << "StringStream" << std::endl;
			for (auto i : OutputBuffer) {
				std::cout << i << std::endl;
			}
			recvFlag = true;
		}
		while (clock() - start < delay);
	}
}