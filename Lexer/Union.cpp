#include "Union.h"

UnionType Union::getType() {
	return this->Type;
}
AbstractSyntaxTree Union::getValue() {
	return this->Value;
}
//setter
void Union::setType(UnionType sType) {
	this->Type = sType;
}
void Union::setValue(AbstractSyntaxTree sValue) {
	this->Value = sValue;
}

//print
std::ostream& operator<<(std::ostream& os, const Union& obj) {
	os << obj.Type;
	return os;
}