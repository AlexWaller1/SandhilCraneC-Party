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

int main()
{
    return 37;
}