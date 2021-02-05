#include "UnionType.h"

void UnionType::initializeAsTokenType(TokenType tt) {
	this->type.tt = tt;
	this->isTerminal = true;
}
void UnionType::initializeAsNonterminalType(NonterminalType nt) {
	this->type.nt = nt;
	this->isTerminal = false;
}

void UnionType::getType(UnionType_raw& gtype, bool& isTerminal) {
	gtype = this->type;
	isTerminal = this->isTerminal;
}

std::ostream& operator<<(std::ostream& os, UnionType& obj) {
	if (obj.isTerminal) {
		os << obj.type.tt;
	}
	else {
		os << obj.type.nt;
	}
	return os;
}