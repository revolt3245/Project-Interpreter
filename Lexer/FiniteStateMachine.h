#pragma once

#include "Rules.h"
#include "Token.h"

class FiniteStateMachine
{
public:
	//Constructor
	FiniteStateMachine() :Rules(std::map<TokenType, std::regex>()){
		initialize();
	};
	FiniteStateMachine(std::map<TokenType, std::regex> nRules) :Rules(nRules) {
		initialize();
	};
	FiniteStateMachine(std::vector<std::regex> nRegex) :Rules(regex_map(nRegex)) {
		initialize();
	};

	//Destructor
	~FiniteStateMachine() {};

	//getter
	std::vector<TokenType> getState();
	std::map<TokenType, std::regex> getRules();
	//setter
	void set_Rules(std::map<TokenType, std::regex> sRules);
	void set_Rules(std::vector<std::regex> sRegex);

	//initializer
	void initialize();

	//Step
	bool step(std::string& c, Token& output);
private:
	std::vector<TokenType> State;
	std::map<TokenType, std::regex> Rules;
};

