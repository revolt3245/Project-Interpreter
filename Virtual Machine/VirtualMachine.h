#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>

#include "ValueContainer.h"

class VirtualMachine
{
public:
	//Constructor
	VirtualMachine();
	VirtualMachine(std::string Path);
	VirtualMachine(std::vector<std::string> nCode);

	//Destructor
	~VirtualMachine();
private:
	std::vector<std::string> Code;
	int CodePointer;

	std::vector<ValueContainer> Register;
	std::multimap<std::string, ValueContainer> GlobalVariables;
	std::vector<std::multimap<std::string, ValueContainer>> Variables;

};

