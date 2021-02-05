#pragma once
#include <thread>
#include <queue>

#include "FiniteStateMachine.h"

class Lexer
{
public:
	//Constructor
	Lexer() :FSM() {};
	Lexer(FiniteStateMachine nFSM) :FSM(nFSM) {};
	//Destructor
	~Lexer() {};
	//Getter
	FiniteStateMachine getFSM();
	//Setter
	void setFSM(FiniteStateMachine sFSM);
	//run
	void run(std::string code, std::queue<Token>& TokenBuffer);
private:
	FiniteStateMachine FSM;
};

