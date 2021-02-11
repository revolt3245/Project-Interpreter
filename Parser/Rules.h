#pragma once

#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

#include "UnionType.h"
#include "UnionReduction.h"
#include "PushdownCommand.h"

typedef std::multimap<UnionType, MarkedReduction> ReductionState;

std::multimap<UnionType, UnionReduction> ReduceMap(std::vector<std::pair<UnionType, UnionReduction>> rules);

std::multimap<UnionType, MarkedReduction> ReduceMapToMarkedMap(std::multimap<UnionType, UnionReduction> reducemap);
std::vector<std::pair<UnionType, UnionReduction>> ReduceMapToRules(std::multimap<UnionType, UnionReduction> reducemap);

std::multimap<UnionType, MarkedReduction> ReduceMapToMarkedMap(std::multimap<UnionType, UnionReduction> reducemap, UnionType token);
std::vector<UnionType> Follow(std::multimap<UnionType, MarkedReduction> markedmap);
std::multimap<UnionType, MarkedReduction> NextState(std::multimap<UnionType, UnionReduction>, std::multimap<UnionType, MarkedReduction>, UnionType);

std::vector<UnionType> NextToken(std::multimap<UnionType, UnionReduction> markedmap, UnionType token);
std::vector<UnionType> NextToken(std::multimap<UnionType, UnionReduction> reducemap, std::multimap<UnionType, MarkedReduction> markedmap);

std::vector<int> ReduceIndex(std::vector<std::pair<UnionType, UnionReduction>> reducemap, std::multimap<UnionType, MarkedReduction> markedmap);
std::vector<std::map<UnionType, PushdownCommand>> PushdownStateTransition(std::multimap<UnionType, UnionReduction> reducemap);

bool operator==(const std::pair<UnionType, MarkedReduction>& obj1, const std::pair<UnionType, MarkedReduction>& obj2);
bool operator==(const ReductionState& obj1, const ReductionState& obj2);