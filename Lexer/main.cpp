#include <iostream>

#include "Token.h"
#include "Rules.h"
#include "FiniteStateMachine.h"
#include "Lexer.h"
#include "VirtualMachine.h"
#include "Initialize.h"
#include "UnionType.h"
#include "AbstractSyntaxTree.h"
#include "UnionReduction.h"

int main() {
	//std::string test = "a123*(123 + b23)";
	//Lexer l;
	//initializer(l);
	//VirtualMachine vm(l);
	//vm.setScript(test);

	//vm.run();
	//vm.scopeTokenBuffer();

	UnionReduction r = { {Union(), Union(), Union()}, [](std::vector<Union> s1) {return s1[0].getValue(); } };

	r.ReductionAction(r.ReductionRule);
	return 0;
}