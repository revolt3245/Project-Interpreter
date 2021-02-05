#include "VirtualMachine.h"

//Initialize
void VirtualMachine::initializer() {
	this->TokenBuffer = std::queue<Token>();
}

//Getter
std::string VirtualMachine::getScript() {
	return this->Script;
}
Lexer VirtualMachine::getLex() {
	return this->Lex;
}

//Setter
void VirtualMachine::setScript(std::string sScript) {
	this->Script = sScript;
}
void VirtualMachine::setLex(Lexer sLex) {
	this->Lex = sLex;
}

//Scope
void VirtualMachine::scopeTokenBuffer() {
	auto qsize = this->TokenBuffer.size();
	for (auto i = 0; i < qsize; i++) {
		auto member = TokenBuffer.front();
		this->TokenBuffer.pop();
		std::cout << member << std::endl;
		TokenBuffer.push(member);
	}
}

//run
void VirtualMachine::run() {
	this->Lex_run();
}

void VirtualMachine::Lex_run() {
	this->Lex.run(this->Script, this->TokenBuffer);
}