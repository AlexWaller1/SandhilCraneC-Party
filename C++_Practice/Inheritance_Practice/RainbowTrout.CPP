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
    static int counter;
    int id;
    std::string name;
    TwoWayNode *next;
    TwoWayNode *prev;
    TwoWayNode() : name("no name yet"), next(nullptr), prev(nullptr) {
        counter++;
        this->id = counter;
    };
    TwoWayNode(std::string name) : name(name), next(nullptr), prev(nullptr) {
        counter++;
        this->id = counter;
    };
    TwoWayNode(std::string name, TwoWayNode *next) : name(name), next(next), prev(nullptr) {
        counter++;
        this->id = counter;
    };
    TwoWayNode(std::string name, TwoWayNode *next, TwoWayNode *prev) :  name(name), prev(prev), next(next) {
        counter++;
        this->id = counter;
    };
};

int TwoWayNode::counter = 0;

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
    // instantiated on the stack
    std::string lisbeth_salander = "Lisbeth Salander";

    std::cout << lisbeth_salander << std::endl;

    // instantiated on the heap
    TwoWayNode *sasha_calle = new TwoWayNode("Sasha Calle");

    TwoWayNode *sky_ferreira = new TwoWayNode("Sky Ferreira");
    
    // '->' is used to access attribute when we are accessing a reference
    // 1
    std::cout << sasha_calle->id << std::endl;
    // Sasha Calle
    std::cout << sasha_calle->name << std::endl;
    // 2
    std::cout << sky_ferreira->id << std::endl;
    // Sky Ferreira
    std::cout << sky_ferreira->name << std::endl;


    
    // make sure heap data is deleted so there is no data leak
    delete sasha_calle;
    // make sure heap data is deleted so there is no data leak
    delete sky_ferreira;

    return 37;
}