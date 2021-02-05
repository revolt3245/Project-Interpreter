#pragma once
#include <iostream>

enum class NonterminalType
{
	BEGIN,
	E,
	T,
	F,
	LAST
};

NonterminalType operator++(NonterminalType& obj);
NonterminalType operator*(NonterminalType obj);

std::ostream& operator<<(std::ostream& os, const NonterminalType& obj);

int NonterminalTypesize();

const int NTCOUNT = NonterminalTypesize();