#include "UnionReduction.h"

bool operator==(const UnionReduction& obj1, const UnionReduction& obj2) {
	if (obj1.ReductionRule.size() == obj2.ReductionRule.size()) {
		auto CompareSize = obj1.ReductionRule.size();
		bool res = true;
		for (auto i = 0; i < CompareSize; i++) {
			auto u1 = obj1.ReductionRule[i];
			auto u2 = obj2.ReductionRule[i];
			res &= (u1.getType() == u2.getType());
		}
		return res;
	}
	else {
		return false;
	}
}