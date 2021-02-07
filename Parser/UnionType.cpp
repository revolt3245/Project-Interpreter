#include "UnionType.h"

//Getter
TokenType UnionType::getTypeAsTerminal() {
	if (this->isTerminal) {
		return this->Type.tt;
	}
	else {
		throw std::runtime_error("This is not Terminal Type!");
	}
}
NonterminalType UnionType::getTypeAsNonterminal() {
	if (!this->isTerminal) {
		return this->Type.nt;
	}
	else {
		throw std::runtime_error("This is not Nonterminal Type!");
	}
}
bool UnionType::getIsTerminal() {
	return this->isTerminal;
}

//Setter
void UnionType::setType(TokenType tt) {
	this->isTerminal = true;
	this->Type.tt = tt;
}
void UnionType::setType(NonterminalType nt) {
	this->isTerminal = false;
	this->Type.nt = nt;
}

//Disp
std::ostream operator<<(std::ostream& os, const UnionType& obj) {
	if (obj.isTerminal) {
		os << obj.Type.tt;
	}
	else {
		os << obj.Type.nt;
	}
}

//Operator
UnionType operator++(const UnionType& obj) {
	UnionType res;
	if (!obj.isTerminal) {
		if (obj.Type.nt == static_cast<NonterminalType>(std::underlying_type<NonterminalType>::type(NonterminalType::LAST) - 1)) {
			res.isTerminal = true;
			res.Type.tt = TokenType::BEGIN;
		}
		else {
			res.isTerminal = false;
			res.Type.nt = ++(obj.Type.nt);
		}
	}
	else {
		res.isTerminal = true;
		res.Type.tt = ++(obj.Type.tt);
	}
	return res;
}

bool operator<(const UnionType& obj1, const UnionType& obj2) {
	if (obj1.isTerminal ^ obj2.isTerminal) {
		return obj2.isTerminal;
	}
	else {
		auto v1 = (obj1.isTerminal) ? std::underlying_type<TokenType>::type(obj1.Type.tt) : std::underlying_type<NonterminalType>::type(obj1.Type.nt);
		auto v2 = (obj2.isTerminal) ? std::underlying_type<TokenType>::type(obj2.Type.tt) : std::underlying_type<NonterminalType>::type(obj2.Type.nt);

		return v1 < v2;
	}
}
bool operator>(const UnionType& obj1, const UnionType& obj2) {
	if (obj1.isTerminal ^ obj2.isTerminal) {
		return obj1.isTerminal;
	}
	else {
		auto v1 = (obj1.isTerminal) ? std::underlying_type<TokenType>::type(obj1.Type.tt) : std::underlying_type<NonterminalType>::type(obj1.Type.nt);
		auto v2 = (obj2.isTerminal) ? std::underlying_type<TokenType>::type(obj2.Type.tt) : std::underlying_type<NonterminalType>::type(obj2.Type.nt);

		return v1 > v2;
	}
}
bool operator<=(const UnionType& obj1, const UnionType& obj2) {
	if (obj1.isTerminal ^ obj2.isTerminal) {
		return obj2.isTerminal;
	}
	else {
		auto v1 = (obj1.isTerminal) ? std::underlying_type<TokenType>::type(obj1.Type.tt) : std::underlying_type<NonterminalType>::type(obj1.Type.nt);
		auto v2 = (obj2.isTerminal) ? std::underlying_type<TokenType>::type(obj2.Type.tt) : std::underlying_type<NonterminalType>::type(obj2.Type.nt);

		return v1 <= v2;
	}
}
bool operator>=(const UnionType& obj1, const UnionType& obj2) {
	if (obj1.isTerminal ^ obj2.isTerminal) {
		return obj1.isTerminal;
	}
	else {
		auto v1 = (obj1.isTerminal) ? std::underlying_type<TokenType>::type(obj1.Type.tt) : std::underlying_type<NonterminalType>::type(obj1.Type.nt);
		auto v2 = (obj2.isTerminal) ? std::underlying_type<TokenType>::type(obj2.Type.tt) : std::underlying_type<NonterminalType>::type(obj2.Type.nt);

		return v1 >= v2;
	}
}

UnionType& UnionType::operator=(const TokenType& tt) {
	this->isTerminal = true;
	this->Type.tt = tt;
	return *this;
}
UnionType& UnionType::operator=(const NonterminalType& nt) {
	this->isTerminal = false;
	this->Type.nt = nt;
	return *this;
}
UnionType& UnionType::operator=(const UnionType& ut) {
	this->isTerminal = ut.isTerminal;
	if (this->isTerminal) {
		this->Type.tt = ut.Type.tt;
	}
	else {
		this->Type.nt = ut.Type.nt;
	}
	return *this;
}