#include "Union.h"

UnionType Union::getType() {
	return this->Type;
}
std::string Union::getValue() {
	return this->Value;
}
//setter
void Union::setType(UnionType sType) {
	this->Type = sType;
}
void Union::setValue(std::string sValue) {
	this->Value = sValue;
}

//print
std::ostream& operator<<(std::ostream& os, const Union& obj) {
	os << obj.Type << " " << obj.Value;
	return os;
}