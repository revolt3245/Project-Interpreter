#pragma once

#include <iostream>

enum class NonterminalType {
	BEGIN,
	E,
	T,
	F,
	LAST
};

NonterminalType operator++(const NonterminalType& token);

bool operator>(const NonterminalType& token1, const NonterminalType& token2);
bool operator<(const NonterminalType& token1, const NonterminalType& token2);
bool operator>=(const NonterminalType& token1, const NonterminalType& token2);
bool operator<=(const NonterminalType& token1, const NonterminalType& token2);

std::ostream& operator<<(std::ostream& os, const NonterminalType& token);