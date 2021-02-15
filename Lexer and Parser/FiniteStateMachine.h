#pragma once

#include <regex>

#include "Rules.h"
#include "Token.h"

class FiniteStateMachine
{
public:
	//Constructor
	FiniteStateMachine() :Rules(std::map<TokenType, std::regex>()){	};
	FiniteStateMachine(std::map<TokenType, std::regex> nRules) :Rules(nRules) {	};
	FiniteStateMachine(std::vector<std::regex> nRegex) :Rules(regex_map(nRegex)) {	};

	//Destructor
	~FiniteStateMachine() {};

	std::map<TokenType, std::regex> getRules();
	//setter
	void set_Rules(std::map<TokenType, std::regex> sRules);
	void set_Rules(std::vector<std::regex> sRegex);

	//Step
	bool step(std::string& c, Token& output);
private:
	std::map<TokenType, std::regex> Rules;
};

