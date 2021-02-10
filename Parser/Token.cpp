#include "Token.h"

//TokenType Enum
TokenType operator++(const TokenType& token) {
	TokenType res = static_cast<TokenType>(std::underlying_type<TokenType>::type(token) + 1);
	return res;
}
bool operator>(const TokenType& token1, const TokenType& token2) {
	auto v1 = std::underlying_type<TokenType>::type(token1);
	auto v2 = std::underlying_type<TokenType>::type(token2);
	return v1 > v2;
}
bool operator<(const TokenType& token1, const TokenType& token2) {
	auto v1 = std::underlying_type<TokenType>::type(token1);
	auto v2 = std::underlying_type<TokenType>::type(token2);
	return v1 < v2;
}
bool operator>=(const TokenType& token1, const TokenType& token2) {
	auto v1 = std::underlying_type<TokenType>::type(token1);
	auto v2 = std::underlying_type<TokenType>::type(token2);
	return v1 >= v2;
}
bool operator<=(const TokenType& token1, const TokenType& token2) {
	auto v1 = std::underlying_type<TokenType>::type(token1);
	auto v2 = std::underlying_type<TokenType>::type(token2);
	return v1 <= v2;
}

std::ostream& operator<<(std::ostream& os, const TokenType& tokentype) {
	switch (tokentype) {
	case TokenType::PLUS:
		os << "PLUS";
		break;
	case TokenType::MINUS:
		os << "MIN";
		break;
	case TokenType::MULT:
		os << "MULT";
		break;
	case TokenType::DIV:
		os << "DIV";
		break;
	case TokenType::LPAREN:
		os << "LPN";
		break;
	case TokenType::RPAREN:
		os << "RPN";
		break;
	case TokenType::NUM:
		os << "NUM";
		break;
	case TokenType::VAR:
		os << "VAR";
		break;
	case TokenType::LAST:
		os << "EOF";
		break;
	}
	return os;
}
//TokenType Member
TokenType Token::getType() {
	return this->Type;
}
std::string Token::getValue() {
	return this->Value;
}

//Setter
void Token::setType(TokenType sType) {
	this->Type = sType;
}
void Token::setValue(std::string sValue) {
	this->Value = sValue;
}

std::ostream& operator<<(std::ostream& os, const Token& obj) {
	os << obj.Type << " " << obj.Value;
	return os;
}

Token& Token::operator=(const Token& obj) {
	this->Type = obj.Type;
	this->Value = obj.Value;
	return *this;
}