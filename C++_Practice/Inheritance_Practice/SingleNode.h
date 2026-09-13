#include <iostream>
#include <climits>

const int maxNumberOfLevel = 5;

class SingleNode
{
public:
    int numParam;
    std::vector<SingleNode *> next;
    // arguments for forward are are vector size, then vector element
    SingleNode(int numParam, int level) : numParam(numParam), next(level + 1, nullptr) {};
};