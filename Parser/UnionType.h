#pragma once
#include <iostream>

#include "Token.h"
#include "Nonterminal.h"

class UnionType
{
public:
	//Constructor
	UnionType() { setType(TokenType::LAST); };
	UnionType(TokenType tt) { setType(tt); };
	UnionType(NonterminalType nt) { setType(nt); };

	//Destructor
	~UnionType();

	//Getter
	TokenType getTypeAsTerminal();
	NonterminalType getTypeAsNonterminal();
	bool getIsTerminal();
	//Setter
	void setType(TokenType tt);
	void setType(NonterminalType nt);

	//Disp
	friend std::ostream operator<<(std::ostream& os, const UnionType& obj);

	//Operator
	friend UnionType operator++(const UnionType& obj);

	friend bool operator<(const UnionType& obj1, const UnionType& obj2);
	friend bool operator>(const UnionType& obj1, const UnionType& obj2);
	friend bool operator<=(const UnionType& obj1, const UnionType& obj2);
	friend bool operator>=(const UnionType& obj1, const UnionType& obj2);

	UnionType& operator=(const TokenType& tt);
	UnionType& operator=(const NonterminalType& nt);
	UnionType& operator=(const UnionType& ut);
private:
	bool isTerminal;
	union ut {
		TokenType tt;
		NonterminalType nt;
	} Type;
};

