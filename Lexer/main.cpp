#include <iostream>

#include "Token.h"
#include "Rules.h"
#include "FiniteStateMachine.h"
#include "Lexer.h"
#include "VirtualMachine.h"
#include "Initialize.h"
#include "UnionType.h"
#include "AbstractSyntaxTree.h"

int main() {
	//std::string test = "a123*(123 + b23)";
	//Lexer l;
	//initializer(l);
	//VirtualMachine vm(l);
	//vm.setScript(test);

	//vm.run();
	//vm.scopeTokenBuffer();

	AbstractSyntaxTree n1(Token(TokenType::NUM, "123"));
	AbstractSyntaxTree n2(Token(TokenType::VAR, "a123"));
	AbstractSyntaxTree n3(Token(TokenType::MULTIPLY, "*"), &n2, &n1);
	AbstractSyntaxTree n4(Token(TokenType::NUM, "23"));
	AbstractSyntaxTree n5(Token(TokenType::PLUS, "+"), &n4, &n3);

	std::cout << n5 << std::endl;

	return 0;
}