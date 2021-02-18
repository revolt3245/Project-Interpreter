#include "Actions.h"

extern std::map<std::string, ValueContainer> Hashmap;
extern std::vector<ValueContainer> Stack;

extern std::vector<std::string> OutputBuffer;
extern std::stringstream ss;

UnionToken FuncR0(std::vector<UnionToken> args) {
	return UnionToken(NonterminalType::BEGIN);
}
UnionToken FuncR1(std::vector<UnionToken> args) {
	return UnionToken(NonterminalType::PROGRAM);
}
UnionToken FuncR2(std::vector<UnionToken> args) {
	return UnionToken(NonterminalType::PROGRAM);
}
UnionToken FuncR3(std::vector<UnionToken> args) {
	return UnionToken(NonterminalType::EXE);
}
UnionToken FuncR4(std::vector<UnionToken> args) {
	return UnionToken(NonterminalType::EXPR);
}
UnionToken FuncR5(std::vector<UnionToken> args) {
	auto key = args[0].getValue();
	if (args[3].getValue() == "int")Hashmap[key] = int(Stack.back());
	else if (args[3].getValue() == "double")Hashmap[key] = double(Stack.back());
	else if (args[3].getValue() == "char")Hashmap[key] = char(Stack.back());
	Stack.pop_back();
	return UnionToken(NonterminalType::EXPR);
}
UnionToken FuncR6(std::vector<UnionToken> args) {
	auto key = args[0].getValue();
	auto value = Hashmap[key];
	Hashmap[key].setValue(Stack.back());
	Stack.pop_back();
	return UnionToken(NonterminalType::EXPR);
}
UnionToken FuncR7(std::vector<UnionToken> args) {
	std::string o_buffer;
	//ss << Stack.back() << std::endl;
	std::cout << Stack.back() << std::endl;
	//ss >> o_buffer;
	//OutputBuffer.push_back(o_buffer);
	Stack.pop_back();
	return UnionToken(NonterminalType::EXPR);
}
UnionToken FuncR8(std::vector<UnionToken> args) {
	auto key = args[1].getValue();
	ValueContainer value;
	if (args[3].getValue() == "int") value.setValueType(ValueType::INT);
	else if (args[3].getValue() == "double") value.setValueType(ValueType::DOUBLE);
	else if (args[3].getValue() == "char") value.setValueType(ValueType::CHAR);

	Hashmap.insert({ key, value });
	return UnionToken(NonterminalType::DECLARE, key);
}
UnionToken FuncR9(std::vector<UnionToken> args) {
	return UnionToken(NonterminalType::TYPES, "int");
}
UnionToken FuncR10(std::vector<UnionToken> args) {
	return UnionToken(NonterminalType::TYPES, "double");
}
UnionToken FuncR11(std::vector<UnionToken> args) {
	return UnionToken(NonterminalType::TYPES, "char");
}
UnionToken FuncR12(std::vector<UnionToken> args) {
	auto x = Stack.back();
	Stack.pop_back();
	x = x + Stack.back();
	Stack.pop_back();
	Stack.push_back(x);
	return UnionToken(NonterminalType::E);
}
UnionToken FuncR13(std::vector<UnionToken> args) {
	auto x = Stack.back();
	Stack.pop_back();
	x = x - Stack.back();
	Stack.pop_back();
	Stack.push_back(x);
	return UnionToken(NonterminalType::E);
}
UnionToken FuncR14(std::vector<UnionToken> args) {
	return UnionToken(NonterminalType::E);
}
UnionToken FuncR15(std::vector<UnionToken> args) {
	auto x = Stack.back();
	Stack.pop_back();
	x = x * Stack.back();
	Stack.pop_back();
	Stack.push_back(x);
	return UnionToken(NonterminalType::T);
}
UnionToken FuncR16(std::vector<UnionToken> args) {
	auto x = Stack.back();
	Stack.pop_back();
	x = x / Stack.back();
	Stack.pop_back();
	Stack.push_back(x);
	return UnionToken(NonterminalType::T);
}
UnionToken FuncR17(std::vector<UnionToken> args) {
	return UnionToken(NonterminalType::T);
}
UnionToken FuncR18(std::vector<UnionToken> args) {
	return UnionToken(NonterminalType::F);
}
UnionToken FuncR19(std::vector<UnionToken> args) {
	auto value = std::stoi(args[0].getValue());
	ValueContainer V(value);
	Stack.push_back(V);
	return UnionToken(NonterminalType::F);
}
UnionToken FuncR20(std::vector<UnionToken> args) {
	Stack.push_back(Hashmap[args[0].getValue()]);
	return UnionToken(NonterminalType::F);
}