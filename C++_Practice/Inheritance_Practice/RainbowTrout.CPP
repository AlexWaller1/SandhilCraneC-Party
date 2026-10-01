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

    std::vector<std::string> bighornRiver[6] = {};

    // '.' used for direct object
    // '->' used for pointer to object
    bighornRiver->push_back(rainbow_trout);
    bighornRiver->push_back(brown_trout);
    bighornRiver->push_back(goldeye);
    bighornRiver->push_back(sucker);
    bighornRiver->push_back(paddlefish);
    bighornRiver->push_back(whitefish);

    return 37;
}