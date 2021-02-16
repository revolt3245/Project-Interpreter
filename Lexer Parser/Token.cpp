#include "Token.h"

//TokenType Enum
TokenType operator++(TokenType& token) {
	TokenType res = static_cast<TokenType>(std::underlying_type<TokenType>::type(token) + 1);
	token = res;
	return res;
}

std::ostream& operator<<(std::ostream& os, const TokenType& tokentype) {
	switch (tokentype) {
	case TokenType::PLUS:
		os << "+";
		break;
	case TokenType::MINUS:
		os << "-";
		break;
	case TokenType::MULT:
		os << "*";
		break;
	case TokenType::DIV:
		os << "/";
		break;
	case TokenType::LPAREN:
		os << "(";
		break;
	case TokenType::RPAREN:
		os << ")";
		break;
	case TokenType::EQUAL:
		os << "=";
		break;
	case TokenType::SEMICOLON:
		os << ";";
		break;
	case TokenType::COLON:
		os << ":";
		break;
	case TokenType::T_INT:
		os << "int";
		break;
	case TokenType::T_DOUBLE:
		os << "double";
		break;
	case TokenType::T_CHAR:
		os << "char";
		break;
	case TokenType::T_VAR:
		os << "var";
		break;
	case TokenType::NUM:
		os << "NUM";
		break;
	case TokenType::VAR:
		os << "VAR";
		break;
	case TokenType::LAST:
		os << "#";
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