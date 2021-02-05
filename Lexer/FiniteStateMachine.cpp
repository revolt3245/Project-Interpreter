#include "FiniteStateMachine.h"

//getter
std::vector<TokenType> FiniteStateMachine::getState() {
	return this->State;
}
std::map<TokenType, std::regex> FiniteStateMachine::getRules() {
	return this->Rules;
}
//setter
void FiniteStateMachine::set_Rules(std::map<TokenType, std::regex> sRules) {
	this->Rules = sRules;
}
void FiniteStateMachine::set_Rules(std::vector<std::regex> sRegex) {
	this->Rules = regex_map(sRegex);
}

//initializer
void FiniteStateMachine::initialize() {
	this->State = std::vector<TokenType>(0);
	for (TokenType i = TokenType::BEGIN; i != TokenType::eof; ++i) {
		this->State.push_back(i);
	}
}

//Step
bool FiniteStateMachine::step(std::string& c, Token& output) {
	std::smatch m;

	for (TokenType i = TokenType::BEGIN; i != TokenType::eof; ++i) {
		std::regex_search(c, m, Rules[i]);
		
		std::cout << i << std::endl;
		auto mstr = m.str();
		auto msize = mstr.size();

		std::cout << msize << std::endl;
		if (msize > 0) {
			output.setType(i);
			output.setValue(mstr);
			c = c.substr(msize);
			return true;
		}
	}
	c.substr(1);
	return false;
}