#include "Lexer.h"

//Getter
FiniteStateMachine Lexer::getFSM() {
	return this->FSM;
}
//Setter
void Lexer::setFSM(FiniteStateMachine sFSM) {
	this->FSM = sFSM;
}
//run
void Lexer::run(std::string code, std::queue<Token>& TokenBuffer) {
	while (code.size() > 0) {
		Token temp;
		if (this->FSM.step(code, temp)) {
			TokenBuffer.push(temp);
		}
	}
}