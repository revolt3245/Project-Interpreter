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

	std::multimap<int, int> test;
	test.insert({ 1,1 });
	test.insert({ 1,2 });
	test.insert({ 2,2 });

	for (auto i = test.lower_bound(1); i != test.upper_bound(1); i++) {
		std::cout << (*i).second << std::endl;
	}

	return 0;
}