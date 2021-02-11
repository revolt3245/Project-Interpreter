#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "Rules.h"
class PushdownAutomata
{
public:
private:
	std::vector<std::map<UnionType, PushdownCommand>> commands;
	std::vector<std::pair<UnionType, UnionReduction>> rules;
};

