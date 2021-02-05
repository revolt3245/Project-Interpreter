#include "Token.h"

//getter
TokenType Token::getType() {
	return this->Type;
}
std::string Token::getValue() {
	return this->Value;
}
//setter
void Token::setType(TokenType sType) {
	this->Type = sType;
}
void Token::setValue(std::string sValue) {
	this->Value = sValue;
}

//print
std::ostream& operator<<(std::ostream& os, const Token& obj) {
	os << obj.Type << " " << obj.Value;
	return os;
}