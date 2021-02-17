#pragma once
#include <iostream>

enum class ValueType {
	INT,
	DOUBLE,
	CHAR
};

class ValueContainer
{
public:
	//Constructor
	ValueContainer():Type(ValueType::INT) { setValue(0); };
	ValueContainer(int nInt) :Type(ValueType::INT) { setValue(nInt); };
	ValueContainer(double nDouble) :Type(ValueType::DOUBLE) { setValue(nDouble); };
	ValueContainer(char nChar) :Type(ValueType::CHAR) { setValue(nChar); };

	//Destructor
	~ValueContainer() {};

	//Getter
	ValueType getValueType();
	int getAsInt();
	double getAsDouble();
	char getAsChar();

	//Setter
	void setValueType(ValueType sType);
	void setValue(int sInt);
	void setValue(double sDouble);
	void setValue(char sChar);

	//cast operator
	operator int() const;
	operator double() const;
	operator char() const;

	//Operator Overloading
	ValueContainer& operator=(const ValueContainer& obj);
	ValueContainer& operator=(const int& Int);
	ValueContainer& operator=(const double& Double);
	ValueContainer& operator=(const char& Char);

	//Disp Operator
	friend std::ostream& operator<<(std::ostream& os, const ValueContainer& obj1);

	//Arithmatic
	friend ValueContainer operator+(const ValueContainer& obj1, const ValueContainer& obj2);
	friend ValueContainer operator-(const ValueContainer& obj1, const ValueContainer& obj2);
	friend ValueContainer operator*(const ValueContainer& obj1, const ValueContainer& obj2);
	friend ValueContainer operator/(const ValueContainer& obj1, const ValueContainer& obj2);
private:
	union value {
		int i;
		double d;
		char c;
	} Value;
	ValueType Type;
};

