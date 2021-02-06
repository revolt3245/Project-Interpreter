#pragma once
enum class PushdownCommandEnum{
	Reduction,
	Transition,
	Goto
};
struct PushdownCommand
{
	int value;
	PushdownCommandEnum command;
};

