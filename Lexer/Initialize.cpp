#include "Initialize.h"

void initializer(Lexer& l) {
	std::vector<std::regex> regex_arr(0);
	regex_arr.push_back(std::regex("^[+]"));
	regex_arr.push_back(std::regex("^[*]"));
	regex_arr.push_back(std::regex("^[(]"));
	regex_arr.push_back(std::regex("^[)]"));
	regex_arr.push_back(std::regex("^[0-9]+"));
	regex_arr.push_back(std::regex("^[a-zA-Z_][a-zA-Z0-9_]*"));

	auto rmap = regex_map(regex_arr);

	FiniteStateMachine fsm(rmap);

	l.setFSM(fsm);
}