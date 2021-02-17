#include "UnionToken.h"

//Getter
UnionType UnionToken::getType() {
	return this->Type;
}
//AST UnionToken::getValue() {
//	return this->Value;
//}
std::string UnionToken::getValue() {
	return this->Value;
}

//Setter
void UnionToken::setType(UnionType sType) {
	this->Type = sType;
}
//void UnionToken::setValue(AST sValue) {
//	this->Value = sValue;
//}
void UnionToken::setValue(std::string sValue) {
	this->Value = sValue;
}

//Disp
std::ostream& operator<<(std::ostream& os, const UnionToken& obj) {
	os << obj.Type;
	return os;
}

//Equal
UnionToken& UnionToken::operator=(const UnionToken& obj) {
	this->Type = obj.Type;
	this->Value = obj.Value;
	return *this;
}
UnionToken& UnionToken::operator=(const Token& obj) {
	auto t = obj;
	this->Type = t.getType();
	//this->Value = AST(obj);
	return *this;
}