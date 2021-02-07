#pragma once
#include <map>
#include <regex>
#include <vector>
#include <queue>
#include <algorithm>

#include "TokenType.h"
#include "UnionReduction.h"
#include "PushdownCommand.h"

std::map<TokenType, std::regex> regex_map(std::vector<std::regex>);

std::multimap<NonterminalType, UnionReduction> reduction_map(std::vector<std::pair<NonterminalType, UnionReduction>>);

std::vector<std::map<NonterminalType, PushdownCommand>> state_transition_map(std::multimap<NonterminalType, UnionReduction>);