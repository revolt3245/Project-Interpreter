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
	regex_vec.push_back(std::regex("^halt"));
	regex_vec.push_back(std::regex("^[0-9]+"));
	regex_vec.push_back(std::regex("^[A-Za-z_][A-Za-z0-9_]*"));

	std::vector <ra> actionVector(0);

	actionVector.push_back(FuncR0);
	actionVector.push_back(FuncR1);
	actionVector.push_back(FuncR2);
	actionVector.push_back(FuncR3);
	actionVector.push_back(FuncR4);
	actionVector.push_back(FuncR5);
	actionVector.push_back(FuncR6);
	actionVector.push_back(FuncR7);
	actionVector.push_back(FuncR8);
	actionVector.push_back(FuncR9);
	actionVector.push_back(FuncR10);
	actionVector.push_back(FuncR11);
	actionVector.push_back(FuncR12);
	actionVector.push_back(FuncR13);
	actionVector.push_back(FuncR14);
	actionVector.push_back(FuncR15);
	actionVector.push_back(FuncR16);
	actionVector.push_back(FuncR17);
	actionVector.push_back(FuncR18);
	actionVector.push_back(FuncR19);
	actionVector.push_back(FuncR20);

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