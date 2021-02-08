#pragma once

#include <vector>

#include "UnionType.h"
#include "AST.h"
#include "UnionToken.h"

struct UnionReduction {
	std::vector<UnionType> ReductionRules;
	AST(*ReductionAction)(std::vector<UnionToken> token);
};

typedef std::pair<UnionReduction, int> MarkedReduction;