#pragma once
#include <string>
#include <iostream>
enum class TokenType {
	BEGIN,
	PLUS = BEGIN,
	MINUS,
	MULT,
	DIV,
	LPAREN,
	RPAREN,
	EQUAL,
	SEMICOLON,
	COLON,
	T_INT,
	T_DOUBLE,
	T_CHAR,
	T_VAR,
	HALT,
	NUM,
	VAR,
	LAST
};

TokenType operator++(TokenType& token);

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

