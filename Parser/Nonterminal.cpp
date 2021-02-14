#include "Nonterminal.h"

NonterminalType operator++(const NonterminalType& token) {
	auto res = static_cast<NonterminalType>(std::underlying_type<NonterminalType>::type(token) + 1);
	return res;
}

bool operator>(const NonterminalType& token1, const NonterminalType& token2) {
	auto v1 = std::underlying_type<NonterminalType>::type(token1);
	auto v2 = std::underlying_type<NonterminalType>::type(token2);

	return v1 > v2;
}
bool operator<(const NonterminalType& token1, const NonterminalType& token2) {
	auto v1 = std::underlying_type<NonterminalType>::type(token1);
	auto v2 = std::underlying_type<NonterminalType>::type(token2);

	return v1 < v2;
}
bool operator>=(const NonterminalType& token1, const NonterminalType& token2) {
	auto v1 = std::underlying_type<NonterminalType>::type(token1);
	auto v2 = std::underlying_type<NonterminalType>::type(token2);

	return v1 >= v2;
}
bool operator<=(const NonterminalType& token1, const NonterminalType& token2) {
	auto v1 = std::underlying_type<NonterminalType>::type(token1);
	auto v2 = std::underlying_type<NonterminalType>::type(token2);

	return v1 <= v2;
}

std::ostream& operator<<(std::ostream& os, const NonterminalType& token) {
	switch (token) {
	case NonterminalType::BEGIN:
		os << "S";
		break;
	case NonterminalType::EXPR:
		os << "Expr";
		break;
	case NonterminalType::E:
		os << "E";
		break;
	case NonterminalType::T:
		os << "T";
		break;
	case NonterminalType::F:
		os << "F";
		break;
	case NonterminalType::LAST:
		os << "LAST";
		break;
	}
	return os;
}