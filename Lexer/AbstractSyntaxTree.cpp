#include "AbstractSyntaxTree.h"

std::ostream& operator<<(std::ostream& os, const AbstractSyntaxTree& obj) {
	Token x = obj.Type;
	static int count = 0;
	static bool lineChanged = false;
	if (lineChanged) {
		lineChanged = false;
		for (int i = 0; i < count; i++) {
			os << static_cast<char>(0x09) << static_cast<char>(0x09);
		}
	}
	if (x.getType() == TokenType::NUM || x.getType() == TokenType::VAR) {
		lineChanged = true;
		os << x << std::endl;
	}
	else {
		count += 1;
		os << x << static_cast<char>(0x09) << static_cast<char>(0x09);
		os << *(obj.L) << *(obj.R);
		count -= 1;
	}
	return os;
}