#include "TokenType.h"

TokenType operator++(TokenType& obj) {
	obj = static_cast<TokenType>(std::underlying_type<TokenType>::type(obj) + 1);
	return obj;
}

TokenType operator*(TokenType obj) {
	return obj;
}

std::ostream& operator<<(std::ostream& os, const TokenType& obj) {
	switch (obj) {
	case TokenType::NUM:
		os << "NUM";
		break;
	case TokenType::VAR:
		os << "VAR";
		break;
	case TokenType::PLUS:
		os << "PLUS";
		break;
	case TokenType::MULTIPLY:
		os << "MULTIPLY";
		break;
	case TokenType::eof:
		os << "EOF";
		break;
	}
	return os;
}

int TokenTypesize() {
	int count = 0;
	for (TokenType i = TokenType::BEGIN; i != TokenType::eof; ++i) {
		count++;
	}
	return count;
}