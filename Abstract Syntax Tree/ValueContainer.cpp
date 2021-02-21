#include "ValueContainer.h"

//Getter
ValueType ValueContainer::getValueType() {
	return this->Type;
}
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
void ValueContainer::setValueType(ValueType sType) {
	switch (sType) {
	case ValueType::INT:
		*this = static_cast<int>(*this);
		break;
	case ValueType::DOUBLE:
		*this = static_cast<double>(*this);
		break;
	case ValueType::CHAR:
		*this = static_cast<char>(*this);
		break;
	}
	this->Type = sType;
}
void ValueContainer::setValue(ValueContainer sValue) {
	switch (this->Type) {
	case ValueType::INT:
		this->Value.i = sValue.getAsInt();
		break;
	case ValueType::DOUBLE:
		this->Value.i = sValue.getAsDouble();
		break;
	case ValueType::CHAR:
		this->Value.i = sValue.getAsChar();
		break;
	}
}
void ValueContainer::setValue(int sInt) {
	switch (this->Type) {
	case ValueType::INT:
		this->Value.i = sInt;
		break;
	case ValueType::DOUBLE:
		this->Value.d = static_cast<double>(sInt);
		break;
	case ValueType::CHAR:
		this->Value.c = static_cast<char>(sInt);
		break;
	default:
		break;
	}
}
void ValueContainer::setValue(double sDouble) {
	switch (this->Type) {
	case ValueType::INT:
		this->Value.i = static_cast<int>(sDouble);
		break;
	case ValueType::DOUBLE:
		this->Value.d = sDouble;
		break;
	case ValueType::CHAR:
		this->Value.c = static_cast<char>(sDouble);
		break;
	default:
		break;
	}
}
void ValueContainer::setValue(char sChar) {
	switch (this->Type) {
	case ValueType::INT:
		this->Value.i = static_cast<char>(sChar);
		break;
	case ValueType::DOUBLE:
		this->Value.d = static_cast<double>(sChar);
		break;
	case ValueType::CHAR:
		this->Value.c = sChar;
		break;
	default:
		break;
	}
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

ValueContainer operator+(const ValueContainer& obj1, const ValueContainer& obj2) {
	ValueContainer res;
	if (obj1.Type == ValueType::INT) {
		res.setValueType(ValueType::INT);
		res.setValue(int(obj1) + int(obj2));
	}	
	else if (obj1.Type == ValueType::DOUBLE) {
		res.setValueType(ValueType::DOUBLE);
		res.setValue(double(obj1) + double(obj2));
	}	
	else if (obj1.Type == ValueType::CHAR) {
		res.setValueType(ValueType::CHAR);
		res.setValue(char(obj1) + char(obj2));
	}

	return res;
}
ValueContainer operator-(const ValueContainer& obj1, const ValueContainer& obj2) {
	ValueContainer res;
	if (obj1.Type == ValueType::INT) {
		res.setValueType(ValueType::INT);
		res.setValue(int(obj1) - int(obj2));
	}
	else if (obj1.Type == ValueType::DOUBLE) {
		res.setValueType(ValueType::DOUBLE);
		res.setValue(double(obj1) - double(obj2));
	}
	else if (obj1.Type == ValueType::CHAR) {
		res.setValueType(ValueType::CHAR);
		res.setValue(char(obj1) - char(obj2));
	}

	return res;
}
ValueContainer operator*(const ValueContainer& obj1, const ValueContainer& obj2) {
	ValueContainer res;
	if (obj1.Type == ValueType::INT) {
		res.setValueType(ValueType::INT);
		res.setValue(int(obj1) * int(obj2));
	}
	else if (obj1.Type == ValueType::DOUBLE) {
		res.setValueType(ValueType::DOUBLE);
		res.setValue(double(obj1) * double(obj2));
	}
	else if (obj1.Type == ValueType::CHAR) {
		res.setValueType(ValueType::CHAR);
		res.setValue(char(obj1) * char(obj2));
	}

	return res;
}
ValueContainer operator/(const ValueContainer& obj1, const ValueContainer& obj2) {
	ValueContainer res;
	if (obj1.Type == ValueType::INT) {
		res.setValueType(ValueType::INT);
		res.setValue(int(obj1) / int(obj2));
	}
	else if (obj1.Type == ValueType::DOUBLE) {
		res.setValueType(ValueType::DOUBLE);
		res.setValue(double(obj1) / double(obj2));
	}
	else if (obj1.Type == ValueType::CHAR) {
		res.setValueType(ValueType::CHAR);
		res.setValue(char(obj1) / char(obj2));
	}

	return res;
}