#include "ValueContainer.h"

//Getter
int ValueContainer::getAsInt() {
	if (this->Type == ValueType::INT)return this->Value.i;
	else if (this->Type == ValueType::DOUBLE)return static_cast<int>(this->Value.d);
	else return static_cast<int>(this->Value.c);
}
double ValueContainer::getAsDouble() {
	if (this->Type == ValueType::INT)return static_cast<double>(this->Value.i);
	else if (this->Type == ValueType::DOUBLE)return this->Value.d;
	else return static_cast<char>(this->Value.c);
}
char ValueContainer::getAsChar() {
	if (this->Type == ValueType::INT)return static_cast<char>(this->Value.i);
	else if (this->Type == ValueType::DOUBLE)return static_cast<char>(this->Value.d);
	else return this->Value.c;
}

//Setter
void ValueContainer::setValue(int sInt) {
	this->Value.i = sInt;
	this->Type = ValueType::INT;
}
void ValueContainer::setValue(double sDouble) {
	this->Value.d = sDouble;
	this->Type = ValueType::DOUBLE;
}
void ValueContainer::setValue(char sChar) {
	this->Value.c = sChar;
	this->Type = ValueType::CHAR;
}

//cast operator
ValueContainer::operator int() const {
	if (this->Type == ValueType::INT)return this->Value.i;
	else if (this->Type == ValueType::DOUBLE)return static_cast<int>(this->Value.d);
	else return static_cast<int>(this->Value.c);
}
ValueContainer::operator double() const {
	if (this->Type == ValueType::INT)return static_cast<double>(this->Value.i);
	else if (this->Type == ValueType::DOUBLE)return this->Value.d;
	else return static_cast<char>(this->Value.c);
}
ValueContainer::operator char() const {
	if (this->Type == ValueType::INT)return static_cast<char>(this->Value.i);
	else if (this->Type == ValueType::DOUBLE)return static_cast<char>(this->Value.d);
	else return this->Value.c;
}

//Operator Overloading
ValueContainer& ValueContainer::operator=(const ValueContainer& obj) {
	this->Type = obj.Type;
	this->Value = obj.Value;
	return *this;
}
ValueContainer& ValueContainer::operator=(const int& Int) {
	this->Type = ValueType::INT;
	this->Value.i = Int;
	return *this;
}
ValueContainer& ValueContainer::operator=(const double& Double) {
	this->Type = ValueType::DOUBLE;
	this->Value.i = Double;
	return *this;
}
ValueContainer& ValueContainer::operator=(const char& Char) {
	this->Type = ValueType::CHAR;
	this->Value.i = Char;
	return *this;
}

//Disp Operator
std::ostream& operator<<(std::ostream& os, const ValueContainer& obj1) {
	switch (obj1.Type) {
	case ValueType::INT:
		os << obj1.Value.i;
		break;
	case ValueType::DOUBLE:
		os << obj1.Value.d;
		break;
	case ValueType::CHAR:
		os << obj1.Value.c;
		break;
	}
	return os;
}