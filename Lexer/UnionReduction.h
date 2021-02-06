#pragma once
#include <vector>
#include "Union.h"

struct UnionReduction
{
	std::vector<Union> ReductionRule;
	AbstractSyntaxTree (*ReductionAction)(std::vector<Union>);
};

bool operator==(const UnionReduction& obj1, const UnionReduction& obj2);