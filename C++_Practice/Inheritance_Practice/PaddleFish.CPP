#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <ctime>

std::vector<int> twoSum(std::vector<int> &vector, int target)
{
    std::vector<int> rVector = {};
    std::unordered_map<int, int> numsMap;

    int i = 0;
    for (; i < vector.size(); i++)
    {
        numsMap[vector[i]] = i;
    }

    int j = 0;
    for (; j < vector.size(); j++)
    {
        int diff = target - vector[j];
        if (numsMap.contains(diff) && (numsMap.at(diff) != j))
        {
            rVector.push_back(j);
            rVector.push_back(numsMap.at(diff));
            return rVector;
        }
    }

    return rVector;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

int main()
{
    // Paddle.CPP
    std::cout << "PaddleFish.CPP" << std::endl;

    std::vector<int> twoSumVector1 = {2, 7, 11, 15};
    int twoSumTarget1 = 9;

    std::vector<int> twoSumVector2 = {3, 2, 4};
    int twoSumTarget2 = 6;

    std::vector<int> twoSumVector3 = {3, 3};
    int twoSumTarget3 = 6;

    std::vector<int> twoSumReturn1 = twoSum(twoSumVector1, twoSumTarget1);
    std::vector<int> twoSumReturn2 = twoSum(twoSumVector2, twoSumTarget2);
    std::vector<int> twoSumReturn3 = twoSum(twoSumVector3, twoSumTarget3);

    int i_1 = 0;
    for (; i_1 < twoSumReturn1.size(); i_1++)
    {
        std::cout << twoSumReturn1[i_1] << ",\n";
    }

    std::cout << "-------------------------------------" << std::endl;

    int i_2 = 0;
    for (; i_2 < twoSumReturn2.size(); i_2++)
    {
        std::cout << twoSumReturn2[i_2] << ",\n";
    }

    std::cout << "-------------------------------------" << std::endl;

    int i_3 = 0;
    for (; i_3 < twoSumReturn3.size(); i_3++)
    {
        std::cout << twoSumReturn3[i_3] << ",\n";
    }

    return 37;
}