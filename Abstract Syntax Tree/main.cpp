#include <iostream>
#include <vector>
#include <regex>
#include <thread>
#include <fstream>
#include <ctime>

#include "PushdownAutomata.h"
#include "FiniteStateMachine.h"
#include "Global Memory.h"
#include "Initialize.h"

PushdownAutomata pa;
FiniteStateMachine fsm;

std::map<std::string, ValueContainer> Hashmap;
std::vector<ValueContainer> Stack;

std::vector<std::string> OutputBuffer;
std::stringstream ss;

extern std::queue<UnionToken> GlobalQueue;
extern std::vector<UnionToken> GlobalTokenStack;
extern std::vector<int> GlobalStateStack;

extern bool ParseComplete;
extern bool LexComplete;
extern bool recvFlag;
extern bool sendFlag;

bool GlobalHalt = false;
bool LinescanComplete = true;

std::queue<std::string> codes;
std::string codebuff;

void getInput();
void lex();
void parse();

int main() {
	std::vector<std::regex> regex_vec(0);
	std::vector<std::pair<UnionType, UnionReduction>> ruleVector(0);

	codebuff = "";

	GlobalTokenStack.push_back(UnionToken(NonterminalType::PROGRAM));

	Initialize(regex_vec, ruleVector);

	fsm.set_Rules(regex_vec);
	pa.setRules(ruleVector);

	std::thread t0(getInput);
	std::thread t1(lex);
	std::thread t2(parse);

	t0.join();
	t1.join();
	t2.join();

	return 0;
}

void getInput() {
	while (!LexComplete) {
		if (GlobalTokenStack.size() == 1) {
			std::string ibuff;
			std::getline(std::cin, ibuff);
			codes.push(ibuff);
			if (ibuff.find("halt") != std::string::npos) {
				GlobalHalt = true;
				break;
			}
		}
	}
	return;
}

void lex() {
	while (!LexComplete) {
		Token x;
		if (fsm.step(codebuff, x)) {
			if (x.getType() == TokenType::HALT) {
				LexComplete = true;
				GlobalQueue.push(Token(TokenType::LAST, ""));
			}
			else if(x.getType() != TokenType::LAST){
				GlobalQueue.push(x);
			}
			else {
				if (!codes.empty()) {
					codebuff = codes.front();
					codes.pop();
				}
			}
		}
	}
}

void parse() {
	while (!ParseComplete) {
		ParseComplete = pa.Step(GlobalQueue, GlobalTokenStack, GlobalStateStack);
	}
}