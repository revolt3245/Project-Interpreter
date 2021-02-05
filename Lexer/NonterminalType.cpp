#include "NonterminalType.h"

NonterminalType operator++(NonterminalType& obj) {
	obj = static_cast<NonterminalType>(std::underlying_type<NonterminalType>::type(obj) + 1);
	return obj;
}
NonterminalType operator*(NonterminalType obj) {
	return obj;
}

std::ostream& operator<<(std::ostream& os, const NonterminalType& obj) {
	switch (obj) {
	case NonterminalType::BEGIN:
		os << "BEGIN";
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
	}
	return os;
}

int NonterminalTypesize() {
	int count = 0;
	for (NonterminalType i = NonterminalType::BEGIN; i != NonterminalType::LAST; ++i) {
		count++;
	}
	return count;
}