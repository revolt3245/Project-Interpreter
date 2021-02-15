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
	ValueContainer() { this->Value.i = 0;};
	ValueContainer(int nInt) { setValue(nInt); };
	ValueContainer(double nDouble) { setValue(nDouble); };
	ValueContainer(char nChar) { setValue(nChar); };

	//Destructor
	~ValueContainer() {};

	//Getter
	int getAsInt();
	double getAsDouble();
	char getAsChar();

	//Setter
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
private:
	union value {
		int i;
		double d;
		char c;
	} Value;
	ValueType Type;
};

