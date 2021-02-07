#pragma once
#include <string>
#include <iostream>
enum class TokenType {
	BEGIN,
	PLUS = BEGIN,
	MULT,
	LPAREN,
	RPAREN,
	NUM,
	VAR,
	LAST
};

TokenType operator++(const TokenType& token);
bool operator>(const TokenType& token1, const TokenType& token2);
bool operator<(const TokenType& token1, const TokenType& token2);
bool operator>=(const TokenType& token1, const TokenType& token2);
bool operator<=(const TokenType& token1, const TokenType& token2);

std::ostream& operator<<(std::ostream& os, const TokenType& tokentype);

class Token
{
public:
	//Constructor
	Token() :Type(TokenType::LAST), Value("") {};
	Token(TokenType nType, std::string nValue) :Type(nType), Value(nValue) {};

	//Destructor
	~Token() {};

	//Getter
	TokenType getType();
	std::string getValue();

	//Setter
	void setType(TokenType sType);
	void setValue(std::string sValue);

	//Disp
	friend std::ostream& operator<<(std::ostream& os, const Token& obj);

	Token& operator=(const Token& obj);
private:
	TokenType Type;
	std::string Value;
};

