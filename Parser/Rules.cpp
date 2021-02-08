#include "Rules.h"

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
	if (Whole != reducemap.end()) {
		auto Reduction = (*Whole).second;
		res.insert({ (*Whole).first, MarkedReduction(Reduction, 0) });
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
std::multimap<UnionType, MarkedReduction> NextState(std::multimap<UnionType, UnionReduction> reducemap, std::multimap<UnionType, MarkedReduction> markedmap, UnionType token) {
	std::multimap<UnionType, MarkedReduction> resfirst;
	std::multimap<UnionType, MarkedReduction> res;
	std::vector<UnionType> prescaned(0);
	//from Markedmap
	for (auto i = markedmap.begin(); i != markedmap.end(); i++) {
		auto rule = (*i).second.first.ReductionRules;
		auto mark = (*i).second.second;
		if (rule[mark] == token) {
			MarkedReduction mr = { {rule, nullptr}, mark + 1 };
			res.insert({ (*i).first, mr });
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

//std::vector<std::map<UnionType, PushdownCommand>> PushdownStateTransition(std::multimap<UnionType, UnionReduction> reducemap) {
//
//}

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