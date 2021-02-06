#pragma once

#include <iostream>

#include "Token.h"
class AbstractSyntaxTree
{
public:
	//Constructor
	AbstractSyntaxTree() :Type(), L(nullptr), R(nullptr) {};
	AbstractSyntaxTree(Token nType) :Type(nType), L(nullptr), R(nullptr) {};
	AbstractSyntaxTree(AbstractSyntaxTree* nL, AbstractSyntaxTree* nR) :L(nL), R(nR) {};
	AbstractSyntaxTree(Token nType, AbstractSyntaxTree* nL, AbstractSyntaxTree* nR) :Type(nType), L(nL), R(nR) {};

	//Destructor
	~AbstractSyntaxTree() {};

	//disp
	friend std::ostream& operator<<(std::ostream& os, const AbstractSyntaxTree& obj);
private:
	Token Type;
	AbstractSyntaxTree* L;
	AbstractSyntaxTree* R;
};

