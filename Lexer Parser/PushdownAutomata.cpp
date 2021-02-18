#include "PushdownAutomata.h"

extern std::map<std::string, ValueContainer> Hashmap;
extern std::vector<ValueContainer> Stack;

extern std::vector<std::string> OutputBuffer;

std::vector<std::map<UnionType, PushdownCommand>> PushdownAutomata::getCommands() {
	return this->Commands;
}
std::vector<std::pair<UnionType, UnionReduction>> PushdownAutomata::getRules() {
	return this->Rules;
}

void PushdownAutomata::setRules(std::vector<std::pair<UnionType, UnionReduction>> sRules) {
	this->Rules = sRules;
	this->Commands = PushdownStateTransition(this->Rules);
}

bool PushdownAutomata::Step(std::queue<UnionToken>& TokenQueue, std::vector<UnionToken>& TokenStack, std::vector<int>& StateStack) {
	bool isComplete = false;
	auto state = StateStack.back();
	auto token_stored = (TokenStack.empty())?UnionToken(NonterminalType::LAST):TokenStack.back();

	if (StateStack.size() == TokenStack.size() + 1) {
		if (TokenQueue.size() > 0) {
			auto token = TokenQueue.front();
			if (this->Commands[state].find(token.getType()) == Commands[state].end()) {
				throw std::runtime_error("There is no reduction rule!");
			}
			auto command = this->Commands[state][token.getType()];

			if (command.cmd == Command::SHIFT) {
				TokenQueue.pop();
				TokenStack.push_back(token);
				StateStack.push_back(command.state);
			}
			else if (command.cmd == Command::REDUCE) {
				auto size = this->Rules[command.state].second.ReductionRules.size();
				auto AfterReduction = this->Rules[command.state].first;
				std::vector<UnionToken> args(size);
				isComplete = (AfterReduction == NonterminalType::BEGIN);
				for (auto i = 0; i < size; i++) {
					args[size - i - 1] = TokenStack.back();
					TokenStack.pop_back();
					StateStack.pop_back();
				}
				auto token = this->Rules[command.state].second.ReductionAction(args);
				TokenStack.push_back(token);
			}
			else {
				throw std::runtime_error("Token Stack and State Stack does not match!");
			}
		}
	}
	else if (StateStack.size() == TokenStack.size()) {
		if (this->Commands[state].find(token_stored.getType()) == Commands[state].end()) {
			throw std::runtime_error("There is no reduction rule!");
		}
		auto command = this->Commands[state][token_stored.getType()];
		if (command.cmd == Command::GOTO) {
			StateStack.push_back(command.state);
		}
		else {
			throw std::runtime_error("Token Stack and State Stack does not match!");
		}
	}
	else {
		throw std::runtime_error("Token Stack and State Stack does not match!");
	}
	return isComplete;
}