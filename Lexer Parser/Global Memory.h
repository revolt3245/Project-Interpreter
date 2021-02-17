#pragma once

#include <map>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include "ValueContainer.h"

static std::queue<UnionToken> GlobalQueue;
static std::vector<UnionToken> GlobalQueueScope(0);
static std::vector<UnionToken> GlobalTokenStack;
static std::vector<int> GlobalStateStack(1);

static std::map<std::string, ValueContainer> Hashmap;
static std::vector<ValueContainer> Stack;

static std::vector<std::string> OutputBuffer;
static std::stringstream ss;

static bool ParseComplete = false;
static bool LexComplete = false;
static bool recvFlag = false;
static bool sendFlag = true;

static FiniteStateMachine fsm;
static PushdownAutomata pa;