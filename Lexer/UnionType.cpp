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

std::ostream& operator<<(std::ostream& os, const UnionType& obj) {
	if (obj.isTerminal) {
		os << obj.type.tt;
	}
	else {
		os << obj.type.nt;
	}
	return os;
}

bool operator==(const UnionType& obj1, const UnionType& obj2) {
	bool t1 = obj1.isTerminal;
	bool t2 = obj2.isTerminal;
	if (t1 ^ t2) {
		return false;
	}
	else {
		if (t1) {
			auto v1 = std::underlying_type<TokenType>::type(obj1.type.tt);
			auto v2 = std::underlying_type<TokenType>::type(obj2.type.tt);
			return v1 == v2;
		}
		else {
			auto v1 = std::underlying_type<NonterminalType>::type(obj1.type.nt);
			auto v2 = std::underlying_type<NonterminalType>::type(obj2.type.nt);
			return v1 == v2;
		}
	}
}

bool operator<(const UnionType& obj1, const UnionType& obj2) {
	bool t1 = obj1.isTerminal;
	bool t2 = obj2.isTerminal;
	if (t1 ^ t2) {
		return t2;
	}
	else {
		if (t1) {
			auto v1 = std::underlying_type<TokenType>::type(obj1.type.tt);
			auto v2 = std::underlying_type<TokenType>::type(obj2.type.tt);
			return v1 < v2;
		}
		else {
			auto v1 = std::underlying_type<TokenType>::type(obj1.type.nt);
			auto v2 = std::underlying_type<TokenType>::type(obj2.type.nt);
			return v1 < v2;
		}
	}
}
bool operator>(const UnionType& obj1, const UnionType& obj2) {
	bool t1 = obj1.isTerminal;
	bool t2 = obj2.isTerminal;
	if (t1 ^ t2) {
		return t1;
	}
	else {
		if (t1) {
			auto v1 = std::underlying_type<TokenType>::type(obj1.type.tt);
			auto v2 = std::underlying_type<TokenType>::type(obj2.type.tt);
			return v1 > v2;
		}
		else {
			auto v1 = std::underlying_type<TokenType>::type(obj1.type.nt);
			auto v2 = std::underlying_type<TokenType>::type(obj2.type.nt);
			return v1 > v2;
		}
	}
}