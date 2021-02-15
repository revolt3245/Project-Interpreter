#include "PushdownAutomata.h"

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
			auto command = this->Commands[state][token.getType()];

			if (command.cmd == Command::SHIFT) {
				TokenQueue.pop();
				TokenStack.push_back(token);
				StateStack.push_back(command.state);
			}
			else if (command.cmd == Command::REDUCE) {
				auto size = this->Rules[command.state].second.ReductionRules.size();
				auto AfterReduction = this->Rules[command.state].first;
				isComplete = (AfterReduction == NonterminalType::BEGIN);
				for (auto i = 0; i < size; i++) {
					TokenStack.pop_back();
					StateStack.pop_back();
				}
				TokenStack.push_back(AfterReduction);
			}
			else {
				throw std::runtime_error("Token Stack and State Stack does not match!");
			}
		}
	}
	else if (StateStack.size() == TokenStack.size()) {
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