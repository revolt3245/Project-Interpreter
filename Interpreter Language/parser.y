%{
	#include <iostream>
	#include <string>
	
	#define YY_NEVER_INTERACTIVE
	using namespace std;

	extern int yylex();

	void yyerror(const char*);
%}

%error-verbose

%token ID

%%
E:	E '+' T|
	T;
T:	T '*' F|
	F;
F:	'(' E ')'|
	ID;

%%
int parse_main(int argc, char**argv){
	if(yyparse() == 0){
		cout << "Parse Complete!";
	}
	else{
		cout << "Syntax Error!";
	}

	return 0;
}

void yyerror(const char* s){
	string errmsg(s);
	cout << errmsg << endl;
}