#pragma once

#include <iostream>
#include <vector>
#include <regex>

#include "PushdownAutomata.h"
#include "FiniteStateMachine.h"
#include "Global Memory.h"

void Initialize(std::vector<std::regex>& regex_vec, std::vector<std::pair<UnionType, UnionReduction>>& rule_vec);