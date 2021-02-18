#include "Global Memory.h"

std::queue<UnionToken> GlobalQueue;
std::vector<UnionToken> GlobalTokenStack;
std::vector<int> GlobalStateStack(1);

bool ParseComplete = false;
bool LexComplete = false;
bool recvFlag = false;
bool sendFlag = true;