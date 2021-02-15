#include "FiniteStateMachine.h"

//getter
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

//Step
bool FiniteStateMachine::step(std::string& c, Token& output) {
	std::smatch m;
	if (c.size() == 0) {
		output.setType(TokenType::LAST);
		output.setValue("");
		return true;
	}

	for (TokenType i = TokenType::BEGIN; i != TokenType::LAST; ++i) {
		std::regex_search(c, m, Rules[i]);
		auto mstr = m.str();
		auto msize = mstr.size();

		if (msize > 0) {
			output.setType(i);
			output.setValue(mstr);
			c = c.substr(msize);
			return true;
		}
	}
	c = c.substr(1);
	return false;
}