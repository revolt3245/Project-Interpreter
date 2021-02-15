#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <queue>

#include "Rules.h"
class PushdownAutomata
{
public:
	PushdownAutomata():Rules(), Commands() {};
	PushdownAutomata(std::vector<std::pair<UnionType, UnionReduction>> nRules) { 
		auto rm = ReduceMap(nRules);
		this->Rules = ReduceMapToRules(rm);
		this->Commands = PushdownStateTransition(rm);
	};

	~PushdownAutomata() {};

	std::vector<std::map<UnionType, PushdownCommand>> getCommands();
	std::vector<std::pair<UnionType, UnionReduction>> getRules();

	void setRules(std::vector<std::pair<UnionType, UnionReduction>> sRules);
	
	bool Step(std::queue<UnionToken>& token, std::vector<UnionToken>& TokenStack, std::vector<int>& StateStack);
private:
	std::vector<std::map<UnionType, PushdownCommand>> Commands;
	std::vector<std::pair<UnionType, UnionReduction>> Rules;
};

