#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "UnionType.h"
#include "AST.h"
#include "UnionToken.h"
#include "ValueContainer.h"

typedef UnionToken(*ra)(std::vector<UnionToken>);

struct UnionReduction {
	std::vector<UnionType> ReductionRules;
	//AST(*ReductionAction)(std::vector<UnionToken> token);
	ra ReductionAction;
};

std::ostream& operator<<(std::ostream& os, const UnionReduction& obj);
bool operator==(const UnionReduction& obj1, const UnionReduction& obj2);

typedef std::pair<UnionReduction, int> MarkedReduction;

std::ostream& operator<<(std::ostream& os, const MarkedReduction& obj);
bool operator==(const MarkedReduction& obj1, const MarkedReduction& obj2);