#pragma once
#include <iostream>
#include <string>

#include "TokenType.h"

class Token
{
public:
	//constructor
	Token():Type(TokenType::eof), Value("") {};
	Token(TokenType nType, std::string nValue) :Type(nType), Value(nValue) {};
	//destructor
	~Token() {};

	//getter
	TokenType getType();
	std::string getValue();
	//setter
	void setType(TokenType sType);
	void setValue(std::string sValue);

	//print
	friend std::ostream& operator<<(std::ostream& os, const Token& obj);
private:
	TokenType Type;
	std::string Value;
};

