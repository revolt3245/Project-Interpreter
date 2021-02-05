#pragma once

#include "UnionType.h"
#include "Token.h"
class Union
{
public:
	//Constructor
	Union() :Type(), Value("") {};
	Union(Token nToken) {
		this->Type.initializeAsTokenType(nToken.getType());
	};
	Union(UnionType nType, std::string nValue = "") :Type(nType), Value(nValue) {};
	Union(TokenType nType, std::string nValue = "") :Type(nType), Value(nValue) {};
	Union(NonterminalType nType, std::string nValue = "") :Type(nType), Value(nValue) {};

	//Destructor
	~Union() {};

	//getter
	UnionType getType();
	std::string getValue();
	//setter
	void setType(UnionType sType);
	void setValue(std::string sValue);

	//print
	friend std::ostream& operator<<(std::ostream& os, const Union& obj);
private:
	UnionType Type;
	std::string Value;
};

