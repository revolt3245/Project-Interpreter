#pragma once
#include <iostream>

enum class TokenType {
	BEGIN,
	PLUS = BEGIN,
	MULTIPLY,
	NUM,
	VAR,
	eof
};

TokenType operator++(TokenType& obj);
TokenType operator*(TokenType obj);

std::ostream& operator<<(std::ostream& os, const TokenType& obj);

int TokenTypesize();

const int TOKENCOUNT = TokenTypesize();