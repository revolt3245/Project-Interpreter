#pragma once

enum class Command {
	REDUCE,
	SHIFT,
	GOTO
};
struct PushdownCommand {
	Command cmd;
	int state;
};