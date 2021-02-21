#include "UnionReduction.h"

std::ostream& operator<<(std::ostream& os, const UnionReduction& obj){
	for (auto i : obj.ReductionRules) {
		os << i << " ";
	}
	return os;
}

bool operator==(const UnionReduction& obj1, const UnionReduction& obj2) {
	auto r1 = obj1.ReductionRules;
	auto r2 = obj2.ReductionRules;
	if (r1.size() != r2.size()) {
		return false;
	}
	else {
		bool isSame = true;
		for (auto i = 0; i < r1.size(); i++) {
			isSame &= (r1[i] == r2[i]);
		}
		return isSame;
	}
}

std::ostream& operator<<(std::ostream& os, const MarkedReduction& obj) {
	int count = 0;
	bool isMarked = false;
	for (auto i : obj.first.ReductionRules) {
		if (count++ == obj.second) {
			os << "\\";
			isMarked = true;
		}
		os << i << " ";
	}
	if (!isMarked) {
		os << "\\";
	}
	return os;
}

bool operator==(const MarkedReduction& obj1, const MarkedReduction& obj2) {
	return (obj1.first == obj2.first) && (obj1.second == obj2.second);
}