#include "Rules.h"

std::map<TokenType, std::regex> regex_map(std::vector<std::regex> regex) {
	std::map<TokenType, std::regex> res;
	int count = 0;
	for (auto i = TokenType::BEGIN; i != TokenType::LAST; ++i) {
		res.insert({ i, regex[count++] });
	}
	return res;
}

std::multimap<UnionType, UnionReduction> ReduceMap(std::vector<std::pair<UnionType, UnionReduction>> rules) {
	std::multimap<UnionType, UnionReduction> res;
	for (auto i : rules) {
		res.insert(i);
	}
	return res;
}

std::multimap<UnionType, MarkedReduction> ReduceMapToMarkedMap(std::multimap<UnionType, UnionReduction> reducemap) {
	std::multimap<UnionType, MarkedReduction> res;
	std::queue<UnionType> UnionQueue;
	std::vector<UnionType> prescaned;

	auto Whole = reducemap.find(NonterminalType::BEGIN);
	auto Reduction = (*Whole).second;
	res.insert({ (*Whole).first, MarkedReduction(Reduction, 0) });
	UnionQueue.push(Reduction.ReductionRules[0]);
	prescaned.push_back(NonterminalType::BEGIN);

	while (!UnionQueue.empty()) {
		auto token = UnionQueue.front();
		UnionQueue.pop();
		if (std::find(prescaned.begin(), prescaned.end(), token) == prescaned.end()) {
			prescaned.push_back(token);
			for (auto Rules = reducemap.lower_bound(token); Rules != reducemap.upper_bound(token); Rules++) {
				res.insert({ (*Rules).first, {(*Rules).second, 0} });
				UnionQueue.push((*Rules).second.ReductionRules[0]);
			}
		}
	}
	return res;
}

std::multimap<UnionType, MarkedReduction> ReduceMapToMarkedMap(std::multimap<UnionType, UnionReduction> reducemap, UnionType token) {
	std::multimap<UnionType, MarkedReduction> res;
	std::queue<UnionType> UnionQueue;
	std::vector<UnionType> prescaned;

	auto Whole = reducemap.find(token);
	//if (Whole != reducemap.end()) {
	//	auto Reduction = (*Whole).second;
	//	res.insert({ (*Whole).first, MarkedReduction(Reduction, 0) });
	//	UnionQueue.push(Reduction.ReductionRules[0]);
	//}

	for (auto i = reducemap.lower_bound(token); i != reducemap.upper_bound(token); i++) {
		auto Reduction = (*i).second;
		res.insert({ (*i).first, MarkedReduction(Reduction, 0) });
		UnionQueue.push(Reduction.ReductionRules[0]);
	}

	while (!UnionQueue.empty()) {
		auto token = UnionQueue.front();
		UnionQueue.pop();
		if (std::find(prescaned.begin(), prescaned.end(), token) == prescaned.end()) {
			prescaned.push_back(token);
			for (auto Rules = reducemap.lower_bound(token); Rules != reducemap.upper_bound(token); Rules++) {
				res.insert({ (*Rules).first, {(*Rules).second, 0} });
				UnionQueue.push((*Rules).second.ReductionRules[0]);
			}
		}
	}
	return res;
}

std::vector<std::pair<UnionType, UnionReduction>> ReduceMapToRules(std::multimap<UnionType, UnionReduction> reducemap) {
	std::vector<std::pair<UnionType, UnionReduction>> res(0);

	for (auto i : reducemap) {
		res.push_back(i);
	}
	return res;
}

std::vector<UnionType> Follow(std::multimap<UnionType, MarkedReduction> markedmap) {
	std::vector<UnionType> res(0);
	for (auto i = markedmap.begin(); i != markedmap.end(); i++) {
		auto rule = (*i).second.first.ReductionRules;
		auto pos = (*i).second.second;
		if (rule.size() > pos && std::find(res.begin(), res.end(), rule[pos]) == res.end()) {
			res.push_back(rule[pos]);
		}
	}
	return res;
}

std::vector<UnionType> NextToken(std::multimap<UnionType, UnionReduction> reducemap, UnionType token) {
	std::vector<UnionType> res(0);
	std::vector<UnionType> prescaned(0);
	std::vector<UnionType> firstPrescaned(0);
	std::queue<UnionType> TokenQueue;
	std::queue<bool> isFirstQueue;
	TokenQueue.push(token);
	isFirstQueue.push(false);

	while (!TokenQueue.empty()) {
		auto cToken = TokenQueue.front();
		auto first = isFirstQueue.front();
		TokenQueue.pop();
		isFirstQueue.pop();

		if (cToken == NonterminalType::BEGIN) {
			res.push_back(TokenType::LAST);
		}
		else if (first) {
			for (auto i = reducemap.lower_bound(cToken); i != reducemap.upper_bound(cToken); i++) {
				auto rules = (*i).second.ReductionRules;
				if (rules[0].getIsTerminal()) {
					res.push_back(rules[0]);
				}
				else if (std::find(firstPrescaned.begin(), firstPrescaned.end(), rules[0]) == firstPrescaned.end()) {
					TokenQueue.push(rules[0]);
					isFirstQueue.push(true);
					firstPrescaned.push_back(rules[0]);
				}
			}
		}
		else {
			for (auto i = reducemap.begin(); i != reducemap.end(); i++) {
				auto rule = (*i).second.ReductionRules;
				auto tokenIter = std::find(rule.begin(), rule.end(), cToken);

				if (rule.size() > tokenIter - rule.begin() + 1 && std::find(res.begin(), res.end(), *(tokenIter + 1)) == res.end()) {
					auto t = *(tokenIter + 1);
					if (t.getIsTerminal()) {
						res.push_back(t);
					}
					else if(std::find(firstPrescaned.begin(), firstPrescaned.end(), t) == firstPrescaned.end()){
						//Nonterminal First
						firstPrescaned.push_back(t);
						TokenQueue.push(t);
						isFirstQueue.push(true);
					}
				}
				else if(rule.size() == tokenIter - rule.begin() + 1){
					auto upper = (*i).first;
					if (std::find(prescaned.begin(), prescaned.end(), upper) == prescaned.end()) {
						prescaned.push_back(upper);
						TokenQueue.push(upper);
						isFirstQueue.push(false);
					}
				}
			}
		}
	}
	return res;
}

std::vector<UnionType> NextToken(std::multimap<UnionType, UnionReduction> reducemap, std::multimap<UnionType, MarkedReduction> markedmap) {
	std::vector<UnionType> res(0);
	std::vector<UnionType> NonterminalList(0);

	for (auto i = markedmap.begin(); i != markedmap.end(); i++) {
		auto rule = (*i).second.first.ReductionRules;
		auto mark = (*i).second.second;
		if (mark == rule.size() && std::find(NonterminalList.begin(), NonterminalList.end(), (*i).first) == NonterminalList.end()) {
			NonterminalList.push_back((*i).first);
		}
	}

	for (auto i : NonterminalList) {
		auto nToken = NextToken(reducemap, i);
		for (auto j : nToken) {
			if (std::find(res.begin(), res.end(), j) == res.end()) {
				res.push_back(j);
			}
		}
	}

	return res;
}
std::multimap<UnionType, MarkedReduction> NextState(std::multimap<UnionType, UnionReduction> reducemap, std::multimap<UnionType, MarkedReduction> markedmap, UnionType token) {
	std::multimap<UnionType, MarkedReduction> resfirst;
	std::multimap<UnionType, MarkedReduction> res;
	std::vector<UnionType> prescaned(0);
	//from Markedmap
	for (auto i = markedmap.begin(); i != markedmap.end(); i++) {
		auto rule = (*i).second.first.ReductionRules;
		auto mark = (*i).second.second;
		if (rule.size() > mark) {
			if (rule[mark] == token) {
				MarkedReduction mr = { {rule, nullptr}, mark + 1 };
				res.insert({ (*i).first, mr });
			}
		}
	}

	for (auto i = res.begin(); i != res.end(); i++) {
		auto rule = (*i).second.first.ReductionRules;
		auto pos = (*i).second.second;

		if (rule.size() > pos && std::find(prescaned.begin(), prescaned.end(), rule[pos]) == prescaned.end()) {
			auto rmap = ReduceMapToMarkedMap(reducemap, rule[pos]);
			prescaned.push_back(rule[pos]);
			for (auto j = rmap.begin(); j != rmap.end(); j++) {
				if (std::find(resfirst.begin(), resfirst.end(), *j) == resfirst.end()) {
					resfirst.insert(*j);
				}
			}
		}
	}

	for (auto i = resfirst.begin(); i != resfirst.end(); i++) {
		if (std::find(res.begin(), res.end(), *i) == res.end()) {
			res.insert(*i);
		}
	}
	return res;
}

std::vector<int> ReduceIndex(std::vector<std::pair<UnionType, UnionReduction>> reducemap, std::multimap<UnionType, MarkedReduction> markedmap) {
	std::vector<int> res(0);
	for (auto i = markedmap.begin(); i != markedmap.end(); i++) {
		auto rule = (*i).second.first.ReductionRules;
		auto mark = (*i).second.second;

		if (rule.size() == mark) {
			std::pair<UnionType, UnionReduction> x = { (*i).first, (*i).second.first };
			auto ind = std::find(reducemap.begin(), reducemap.end(), x) - reducemap.begin();
			res.push_back(ind);
		}
	}

	return res;
}

std::vector<std::map<UnionType, PushdownCommand>> PushdownStateTransition(std::multimap<UnionType, UnionReduction> reducemap) {
	std::vector<std::map<UnionType, PushdownCommand>> res(0);
	auto initial_state = ReduceMapToMarkedMap(reducemap);
	std::vector<std::multimap<UnionType, MarkedReduction>> states = { initial_state };
	std::queue<int> StateQueue;
	int index = 1;
	StateQueue.push(0);

	while (!StateQueue.empty()) {
		auto cState = states[StateQueue.front()];
		std::map<UnionType, PushdownCommand> transition;
		StateQueue.pop();

		auto follow = Follow(cState);
		auto nToken = NextToken(reducemap, cState);

		//SHIFT, GOTO
		for (auto i : follow) {
			auto nState = NextState(reducemap, cState, i);
			auto nStateIter = std::find(states.begin(), states.end(), nState);
			auto cmd = (i.getIsTerminal()) ? Command::SHIFT : Command::GOTO;
			if (nStateIter == states.end()) {
				states.push_back(nState);
				transition.insert({ i, {cmd, index} });
				StateQueue.push(index++);
			}
			else {
				auto state_ind = nStateIter - states.begin();
				transition.insert({ i, {cmd, state_ind} });
			}
		}

		auto rules = ReduceMapToRules(reducemap);
		//REDUCE
		for (auto i : nToken) {
			if (std::find(follow.begin(), follow.end(), i) == follow.end()) {
				auto nIndex = ReduceIndex(rules, cState);
				transition.insert({ i, {Command::REDUCE, nIndex[0]} });
			}
		}
		res.push_back(transition);
	}

	return res;
}

std::vector<std::map<UnionType, PushdownCommand>> PushdownStateTransition(std::vector<std::pair<UnionType, UnionReduction>> rules) {
	std::vector<std::map<UnionType, PushdownCommand>> res(0);
	auto reducemap = ReduceMap(rules);
	auto initial_state = ReduceMapToMarkedMap(reducemap);
	std::vector<std::multimap<UnionType, MarkedReduction>> states = { initial_state };
	std::queue<int> StateQueue;
	int index = 1;
	StateQueue.push(0);

	while (!StateQueue.empty()) {
		auto cState = states[StateQueue.front()];
		std::map<UnionType, PushdownCommand> transition;
		StateQueue.pop();

		auto follow = Follow(cState);
		auto nToken = NextToken(reducemap, cState);

		//SHIFT, GOTO
		for (auto i : follow) {
			auto nState = NextState(reducemap, cState, i);
			auto nStateIter = std::find(states.begin(), states.end(), nState);
			auto cmd = (i.getIsTerminal()) ? Command::SHIFT : Command::GOTO;
			if (nStateIter == states.end()) {
				states.push_back(nState);
				transition.insert({ i, {cmd, index} });
				StateQueue.push(index++);
			}
			else {
				auto state_ind = nStateIter - states.begin();
				transition.insert({ i, {cmd, state_ind} });
			}
		}

		//REDUCE
		for (auto i : nToken) {
			if (std::find(follow.begin(), follow.end(), i) == follow.end()) {
				auto nIndex = ReduceIndex(rules, cState);
				transition.insert({ i, {Command::REDUCE, nIndex[0]} });
			}
		}
		res.push_back(transition);
	}

	return res;
}

bool operator==(const std::pair<UnionType, MarkedReduction>& obj1, const std::pair<UnionType, MarkedReduction>& obj2) {
	return (obj1.first == obj2.first) && (obj1.second == obj2.second);
}

bool operator==(const ReductionState& obj1, const ReductionState& obj2) {
	if (obj1.size() != obj2.size()) {
		return false;
	}
	else {
		bool isSame = true;
		for (auto i = obj1.begin(); i != obj1.end(); i++) {
			isSame &= (find(obj2.begin(), obj2.end(), *i) != obj2.end());
		}
		return isSame;
	}
}