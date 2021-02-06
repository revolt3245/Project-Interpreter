#pragma once
#include <map>
#include <regex>
#include <vector>
#include <queue>

#include "TokenType.h"
#include "UnionReduction.h"
#include "PushdownCommand.h"

std::map<TokenType, std::regex> regex_map(std::vector<std::regex>);

std::multimap<UnionType, UnionReduction> reduction_map(std::vector<std::pair<UnionType, UnionReduction>>);

std::vector<std::map<UnionType, PushdownCommand>> state_transition_map(std::multimap<UnionType, UnionReduction>);