#pragma once

#include <iostream>

#include "Token.h"
class AST
{
public:
	//Construct
	AST() :Value(), Left(nullptr), Right(nullptr) {};
	AST(Token nValue) :Value(nValue), Left(nullptr), Right(nullptr) {};
	AST(AST* nLeft, AST* nRight) :Value(), Left(nLeft), Right(nRight) {};
	AST(Token nValue, AST* nLeft, AST* nRight) :Value(nValue), Left(nLeft), Right(nRight) {};

	//Destruct
	~AST() {};

	//Getter
	Token getValue();
	AST* getLeft();
	AST* getRight();

	//Setter
	void setValue(Token Value);
	void setBranches(AST* Left, AST* Right);
private:
	Token Value;
	AST* Left;
	AST* Right;
};