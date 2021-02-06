#pragma once

#include "UnionType.h"
#include "Token.h"
#include "AbstractSyntaxTree.h"

class Union
{
public:
	//Constructor
	Union() :Type(), Value() {};
	Union(Token nToken) {
		this->Type.initializeAsTokenType(nToken.getType());
	};
	Union(UnionType nType, AbstractSyntaxTree nValue) :Type(nType), Value(nValue) {};
	Union(TokenType nType, AbstractSyntaxTree nValue) :Type(nType), Value(nValue) {};
	Union(NonterminalType nType, AbstractSyntaxTree nValue) :Type(nType), Value(nValue) {};

	//Destructor
	~Union() {};

	//getter
	UnionType getType();
	AbstractSyntaxTree getValue();
	//setter
	void setType(UnionType sType);
	void setValue(AbstractSyntaxTree sValue);

	//print
	friend std::ostream& operator<<(std::ostream& os, const Union& obj);
private:
	UnionType Type;
	AbstractSyntaxTree Value;
};

