#include <iostream>
#include <thread>
#include <vector>
#include <queue>

std::queue<int> GlobalQueue;
std::vector<int> GlobalVector;
bool finishFlag = false;

void function1() {
	for (int i = 0; i < 10; i++) {
		//GlobalQueue.push(i);
		GlobalVector.push_back(i);
	}
	finishFlag = true;
}

void function2() {
	while (!finishFlag || !GlobalVector.empty()) {
		if (!GlobalVector.empty()) {
			std::cout << GlobalVector[0] << std::endl;
			GlobalVector.erase(GlobalVector.begin());
		}
	}
}

int main() {
	std::thread t1(function1);
	std::thread t2(function2);

	t1.join();
	t2.join();

	return 0;
}