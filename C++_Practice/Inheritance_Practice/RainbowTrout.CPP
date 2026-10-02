#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <ctime>
#include <print>
#include <set>

struct OneWayNode
{
    int data;
    OneWayNode *next;
    OneWayNode() : data(0), next(nullptr) {};
    OneWayNode(int data) : data(data), next(nullptr) {};
    OneWayNode(int data, OneWayNode *next) : data(data), next(next) {};
};

struct TwoWayNode
{
    int id = 0;
    std::string name;
    TwoWayNode *next;
    TwoWayNode *prev;
    TwoWayNode() : id(id++), name("no name yet"), next(nullptr), prev(nullptr) {};
    TwoWayNode(std::string name) : id(id++), name(name), next(nullptr), prev(nullptr) {};
    TwoWayNode(std::string name, TwoWayNode *next) : id(id++), name(name), next(next), prev(nullptr) {};
    TwoWayNode(std::string name, TwoWayNode *next, TwoWayNode *prev) : id(id++), name(name), prev(prev), next(next) {};
};

void printNumbersRecursion(int num)
{
    if (num == 0)
    {
        return;
    }

    std::cout << num << std::endl;

    printNumbersRecursion(num - 1);
};

int main()
{

    std::string rainbow_trout_cpp = "RainbowTrout.CPP";

    // RainbowTrout.CPP
    std::cout << rainbow_trout_cpp << std::endl;

    std::string rainbow_trout = "Rainbow Trout";
    std::string brown_trout = "Brown Trout";
    std::string goldeye = "Goldeye";
    std::string sucker = "Sucker";
    std::string paddlefish = "Paddlefish";
    std::string whitefish = "Whitefish";

    /*
        the '[6]' at the end essentially makes this a C-style array
        and a pointer, so it's functions and elements need to be
        accessed like a reference rather than a direct object,
        so we use the '->' instead of the '.' for access
    */
    std::vector<std::string> bighornRiver[6] = {};

    // '.' used for direct object
    // '->' used for pointer to object
    // also noting that in this case it is pushing into the 
    // first vector element of the array since we aren't specifying
    // that can be tricky, so just noting that
    bighornRiver->push_back(rainbow_trout);
    bighornRiver->push_back(brown_trout);
    bighornRiver->push_back(goldeye);
    bighornRiver->push_back(sucker);
    bighornRiver->push_back(paddlefish);
    bighornRiver->push_back(whitefish);
    bighornRiver->push_back("Otter");

    // 7
    std::cout << bighornRiver->size() << std::endl;
    // Rainbow Trout
    std::cout << bighornRiver->at(0) << std::endl;

    std::vector<std::string> bighornRiver2 = {};
    bighornRiver2.push_back(rainbow_trout);
    bighornRiver2.push_back(brown_trout);
    bighornRiver2.push_back(goldeye);

    /*
        5
        4
        3
        2
        1
    */
    printNumbersRecursion(5);

    return 37;
}