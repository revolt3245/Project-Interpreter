#pragma once

#include "Lexer.h"

class VirtualMachine
{
public:
	//Constructor
	VirtualMachine() :Lex(), Script(""){
		initializer();
	};
	VirtualMachine(Lexer nLex) :Lex(nLex), Script("") {
		initializer();
	};
	//Destructor
	~VirtualMachine() {};

	//Getter
	std::string getScript();
	Lexer getLex();

	//Setter
	void setScript(std::string sScript);
	void setLex(Lexer sLex);

	//Scope
	void scopeTokenBuffer();

	//run
	void run();

	//initializer
	void initializer();
private:
	void Lex_run();

	std::string Script;
	Lexer Lex;
	std::queue<Token> TokenBuffer;
};

