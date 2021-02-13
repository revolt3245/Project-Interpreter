#include "PushdownCommand.h"

std::ostream& operator<<(std::ostream& os, const Command& obj) {
	switch (obj) {
	case Command::REDUCE:
		os << "RED";
		break;
	case Command::SHIFT:
		os << "SHIFT";
		break;
	case Command::GOTO:
		os << "GOTO";
		break;
	}
	return os;
}
std::ostream& operator<<(std::ostream& os, const PushdownCommand& obj) {
	os << obj.cmd << " " << obj.state;
	return os;
}