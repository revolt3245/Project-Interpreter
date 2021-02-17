#include "Initialize.h"

void Initialize(std::vector<std::regex>& regex_vec, std::vector<std::pair<UnionType, UnionReduction>>& ruleVector) {
	regex_vec = std::vector<std::regex>(0);
	regex_vec.push_back(std::regex("^[+]"));
	regex_vec.push_back(std::regex("^[-]"));
	regex_vec.push_back(std::regex("^[*]"));
	regex_vec.push_back(std::regex("^[/]"));
	regex_vec.push_back(std::regex("^[(]"));
	regex_vec.push_back(std::regex("^[)]"));
	regex_vec.push_back(std::regex("^[=]"));
	regex_vec.push_back(std::regex("^[;]"));
	regex_vec.push_back(std::regex("^[:]"));
	regex_vec.push_back(std::regex("^int"));
	regex_vec.push_back(std::regex("^double"));
	regex_vec.push_back(std::regex("^char"));
	regex_vec.push_back(std::regex("^var"));
	regex_vec.push_back(std::regex("^[0-9]+"));
	regex_vec.push_back(std::regex("^[A-Za-z_][A-Za-z0-9_]*"));

	std::vector <ra> actionVector(0);

	actionVector.push_back(
		[&](std::vector<UnionToken> args) {
		return UnionToken(NonterminalType::BEGIN); 
		}
	);//BEGIN->PROGRAM

	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			return UnionToken(NonterminalType::PROGRAM); 
		}
	);//PROGRAM->PROGRAM EXE
	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			return UnionToken(NonterminalType::PROGRAM); 
		}
	);//PROGRAM->EXE

	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			return UnionToken(NonterminalType::EXE); 
		}
	);//EXE->EXPR;

	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			auto key = args[0].getValue();
			Hashmap[key] = Stack.back();
			Stack.pop_back();
			return UnionToken(NonterminalType::EXPR); 
		}
	);//EXPR->DECLARE
	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			auto key = args[0].getValue();
			Hashmap[key] = Stack.back();
			Stack.pop_back();
			return UnionToken(NonterminalType::EXPR); 
		}
	);//EXPR->DECLARE = E
	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			auto key = args[0].getValue();
			Hashmap[key] = Stack.back();
			Stack.pop_back();
			return UnionToken(NonterminalType::EXPR); 
		}
	);//EXPR->VAR = E
	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			std::string o_buffer;
			ss << Stack.back() << std::endl;
			ss >> o_buffer;
			OutputBuffer.push_back(o_buffer);
			Stack.pop_back();
			return UnionToken(NonterminalType::EXPR); 
		}
	);//EXPR->E

	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			auto key = args[1].getValue();
			ValueContainer value;
			if (args[3].getValue() == "int") value.setValueType(ValueType::INT);
			else if (args[3].getValue() == "double") value.setValueType(ValueType::DOUBLE);
			else if (args[3].getValue() == "char") value.setValueType(ValueType::CHAR);

			Hashmap.insert({ key, value });
			return UnionToken(NonterminalType::DECLARE, key); 
		}
	);//DECLARE -> var VAR:TYPES

	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			return UnionToken(NonterminalType::TYPES, "int"); 
		}
	);//TYPES->int
	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			return UnionToken(NonterminalType::TYPES, "double"); 
		}
	);//TYPES->double
	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			return UnionToken(NonterminalType::TYPES, "char"); 
		}
	);//TYPES->char

	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			auto x = Stack.back();
			Stack.pop_back();
			x = x + Stack.back();
			Stack.pop_back();
			Stack.push_back(x);
			return UnionToken(NonterminalType::E); 
		}
	);//E->E+T
	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			auto x = Stack.back();
			Stack.pop_back();
			x = x - Stack.back();
			Stack.pop_back();
			Stack.push_back(x);
			return UnionToken(NonterminalType::E);
		}
	);//E->E-T
	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			return UnionToken(NonterminalType::E); 
		}
	);//E->T

	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			auto x = Stack.back();
			Stack.pop_back();
			x = x * Stack.back();
			Stack.pop_back();
			Stack.push_back(x);
			return UnionToken(NonterminalType::T); 
		}
	);//T->T*F
	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			auto x = Stack.back();
			Stack.pop_back();
			x = x / Stack.back();
			Stack.pop_back();
			Stack.push_back(x);
			return UnionToken(NonterminalType::T); 
		}
	);//T->T/F
	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			return UnionToken(NonterminalType::T); 
		}
	);//T->F

	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			return UnionToken(NonterminalType::F); 
		}
	);//F->(E)
	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			auto value = std::stoi(args[0].getValue());
			ValueContainer V(value);
			Stack.push_back(V);
			return UnionToken(NonterminalType::F); 
		}
	);//F->NUM
	actionVector.push_back(
		[](std::vector<UnionToken> args) {
			Stack.push_back(Hashmap[args[0].getValue()]);
			return UnionToken(NonterminalType::F); 
		}
	);//F->VAR

	auto actionData = actionVector.data();

	ruleVector = std::vector<std::pair<UnionType, UnionReduction>>(0);
	ruleVector.push_back({ NonterminalType::BEGIN, {{NonterminalType::PROGRAM}, (*actionData++)} });

	ruleVector.push_back({ NonterminalType::PROGRAM, {{NonterminalType::PROGRAM, NonterminalType::EXE}, (*actionData++)} });
	ruleVector.push_back({ NonterminalType::PROGRAM, {{NonterminalType::EXE}, (*actionData++)} });

	ruleVector.push_back({ NonterminalType::EXE, {{NonterminalType::EXPR, TokenType::SEMICOLON}, (*actionData++)} });

	ruleVector.push_back({ NonterminalType::EXPR, {{NonterminalType::DECLARE}, (*actionData++)} });
	ruleVector.push_back({ NonterminalType::EXPR, {{NonterminalType::DECLARE, TokenType::EQUAL, NonterminalType::E}, (*actionData++)} });
	ruleVector.push_back({ NonterminalType::EXPR, {{TokenType::VAR, TokenType::EQUAL, NonterminalType::E}, (*actionData++)} });
	ruleVector.push_back({ NonterminalType::EXPR, {{NonterminalType::E}, (*actionData++)} });

	ruleVector.push_back({ NonterminalType::DECLARE, {{TokenType::T_VAR, TokenType::VAR, TokenType::COLON, NonterminalType::TYPES}, (*actionData++)} });

	ruleVector.push_back({ NonterminalType::TYPES, {{TokenType::T_INT}, (*actionData++)} });
	ruleVector.push_back({ NonterminalType::TYPES, {{TokenType::T_DOUBLE}, (*actionData++)} });
	ruleVector.push_back({ NonterminalType::TYPES, {{TokenType::T_CHAR}, (*actionData++)} });

	ruleVector.push_back({ NonterminalType::E , { {NonterminalType::E, TokenType::PLUS, NonterminalType::T}, (*actionData++) } });
	ruleVector.push_back({ NonterminalType::E , { {NonterminalType::E, TokenType::MINUS, NonterminalType::T}, (*actionData++) } });
	ruleVector.push_back({ NonterminalType::E , { {NonterminalType::T}, (*actionData++) } });

	ruleVector.push_back({ NonterminalType::T , { {NonterminalType::T, TokenType::MULT, NonterminalType::F}, (*actionData++) } });
	ruleVector.push_back({ NonterminalType::T , { {NonterminalType::T, TokenType::DIV, NonterminalType::F}, (*actionData++) } });
	ruleVector.push_back({ NonterminalType::T , { {NonterminalType::F}, (*actionData++) } });

	ruleVector.push_back({ NonterminalType::F , { {TokenType::LPAREN, NonterminalType::E, TokenType::RPAREN}, (*actionData++) } });
	ruleVector.push_back({ NonterminalType::F , { {TokenType::NUM}, (*actionData++) } });
	ruleVector.push_back({ NonterminalType::F , { {TokenType::VAR}, (*actionData++) } });
}