#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "UnionType.h"
#include "AST.h"

class UnionToken
{
public:
	//Constructor
	UnionToken() :Type(), Value() {};
	UnionToken(UnionType nType) :Type(nType), Value() {};
	//UnionToken(UnionType nType, AST nValue) :Type(nType), Value(nValue) {};
	UnionToken(UnionType nType, std::string nValue) :Type(nType), Value(nValue) {};
	UnionToken(Token nToken) :Type(nToken.getType()), Value(nToken.getValue()) {};

	//Destructor
	~UnionToken() {};

	//Getter
	UnionType getType();
	//AST getValue();
	std::string getValue();
	//Setter
	void setType(UnionType sType);
	//void setValue(AST sValue);
	void setValue(std::string sValue);

	//Disp
	friend std::ostream& operator<<(std::ostream& os, const UnionToken& obj);

	//Equal
	UnionToken& operator=(const UnionToken& obj);
	UnionToken& operator=(const Token& obj);
private:
	UnionType Type;
	//AST Value;
	std::string Value;
};