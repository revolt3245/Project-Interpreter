#pragma once

#include <iostream>

enum class Command {
	REDUCE,
	SHIFT,
	GOTO
};
struct PushdownCommand {
	Command cmd;
	int state;
};

std::ostream& operator<<(std::ostream& os, const Command& obj);
std::ostream& operator<<(std::ostream& os, const PushdownCommand& obj);