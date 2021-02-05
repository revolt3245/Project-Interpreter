#pragma once
#include <map>
#include <regex>
#include <vector>

#include "TokenType.h"
#include "UnionType.h"

std::map<TokenType, std::regex> regex_map(std::vector<std::regex>);

std::multimap<UnionType, std::vector<UnionType>> reduction_map(std::vector<std::pair<UnionType, std::vector<UnionType>>>);