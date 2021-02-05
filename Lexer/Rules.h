#pragma once
#include <map>
#include <regex>
#include <vector>

#include "TokenType.h"

std::map<TokenType, std::regex> regex_map(std::vector<std::regex>);