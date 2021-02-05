#pragma once
#include "TokenType.h"
#include "NonterminalType.h"
union UnionType_raw
{
	TokenType tt;
	NonterminalType nt;
};

class UnionType {
public:
	UnionType() :type({ TokenType::BEGIN }), isTerminal(true) {};
	UnionType(TokenType ntt) {
		initializeAsTokenType(ntt);
	};
	UnionType(NonterminalType nnt) {
		initializeAsNonterminalType(nnt);
	};

	~UnionType() {};

	void initializeAsTokenType(TokenType);
	void initializeAsNonterminalType(NonterminalType);

	void getType(UnionType_raw& gtype, bool& isTerminal);

	friend std::ostream& operator<<(std::ostream& os, UnionType& obj);
private:
	union UnionType_raw type;
	bool isTerminal;
};

