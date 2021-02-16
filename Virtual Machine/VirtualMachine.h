#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

#include "ValueContainer.h"

struct Mnemonic {
	enum class OpCode {
		PUSH,
		POP,
		ADD,
		SUB,
		MULT,
		DIV
	} opcode;
	enum class DestinationClass {
		GLOBAL,
		LOCAL,
		OUTPUT,
		CONST
	} dclass;

	std::string value;
};
class VirtualMachine
{
public:
	//Constructor
	VirtualMachine() {};
	VirtualMachine(std::string Path) {};
	VirtualMachine(std::vector<std::string> nCode) {};

	//Destructor
	~VirtualMachine();

	//Initialize
	void initialize();
private:
	std::vector<std::string> Code;
	int CodePointer;

	std::vector<ValueContainer> Stack;
	std::multimap<std::string, ValueContainer*> GlobalVariables;
	//std::vector<std::multimap<std::string, ValueContainer>> LocalVariables;

	std::queue<ValueContainer> OutputBuffer;
};

