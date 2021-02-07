#include "AST.h"

//Getter
Token AST::getValue() {
	return this->Value;
}
AST* AST::getLeft() {
	return Left;
}
AST* AST::getRight() {
	return Right;
}

//Setter
void AST::setValue(Token Value) {
	this->Value = Value;
}
void AST::setBranches(AST* Left, AST* Right) {
	this->Left = Left;
	this->Right = Right;
}