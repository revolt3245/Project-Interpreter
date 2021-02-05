#include <iostream>
#include <iostream>

#include "Token.h"
#include "Rules.h"
#include "FiniteStateMachine.h"

int main() {
	std::vector<std::regex> regex_arr(0);
	regex_arr.push_back(std::regex("^[0-9]+"));
	regex_arr.push_back(std::regex("^[a-zA-Z_][a-zA-Z0-9_]*"));
	regex_arr.push_back(std::regex("^[+]"));
	regex_arr.push_back(std::regex("^[*]"));

	auto rmap = regex_map(regex_arr);

	FiniteStateMachine fsm(rmap);

	std::string test = "b123";
	Token Test;

	if(fsm.step(test, Test))std::cout << Test << std::endl;

	//std::cout << "token count : " << rmap.size() << std::endl;

	return 0;
}