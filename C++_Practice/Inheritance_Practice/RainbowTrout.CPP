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
    return 37;
}