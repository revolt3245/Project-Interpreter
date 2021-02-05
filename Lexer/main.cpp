#include <iostream>
#include <iostream>

#include "Token.h"
#include "Rules.h"
#include "FiniteStateMachine.h"
#include "Lexer.h"
#include "VirtualMachine.h"
#include "Initialize.h"

int main() {
	std::string test = "a123+123";
	Lexer l;
	initializer(l);
	VirtualMachine vm(l);
	vm.setScript(test);

	vm.run();
	vm.scopeTokenBuffer();

	return 0;
}