#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <ctime>
#include <print>

struct Node
{
    std::string data;
    struct Node *next;
};

struct DoubleNode
{
    int id;
    std::string data;
    struct DoubleNode *next;
    struct DoubleNode *prev;
};

// using reference for parameter keeps it from being copied
int squared(int &num)
{
    return num * num;
}

int factorial(int num)
{
    int rValue = num;
    for (; num >= 1; num--)
    {
        if (num > 1)
        {
            rValue = rValue * (num - 1);
        }
    }

    return rValue;
}

bool palindrome(std::string &str)
{
    int i = 0;
    int j = str.length() - 1;
    for (; i < j; i++, j--)
    {
        if (str.at(i) != str.at(j))
        {
            return false;
        }
    }
    return true;
}

std::string firstDuplicate(std::vector<std::string> array)
{
    std::unordered_map<std::string, int> duplicates;
    int i = 0;
    for (; i < array.size(); i++)
    {
        if (duplicates[array[i]] == 1)
        {
            return array[i];
        }
        duplicates[array[i]] = 1;
    }
    return "No Duplicates";
}

int greatestNumber(std::vector<int> nums)
{
    int greatestNum = 0;
    int i = 0;

    for (; i < nums.size(); i++)
    {
        if (i == 0)
        {
            greatestNum = nums[i];
        }
        if (nums[i] > greatestNum)
        {
            greatestNum = nums[i];
        }
    }
    return greatestNum;
}

std::vector<std::string> reverseOrder(std::vector<std::string> array)
{
    int i = 0;
    int j = array.size() - 1;
    for (; i < j; i++, j--)
    {
        std::string temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }

    return array;
}

int mathDotRound(float num)
{
    int integer = num / 1;
    float remainder = num - integer;
    int rValue = remainder >= 0.5 ? integer + 1 : integer;
    return rValue;
}

bool isPrimeNumber(int num)
{
    int i = 2;
    for (; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

// using reference so nums vector is not copied
int majorityElement(std::vector<int> &nums)
{
    std::unordered_map<int, int> mapNums;

    int i = 0;
    for (; i < nums.size(); i++)
    {
        if (mapNums.contains(nums[i]))
        {
            int val = mapNums[nums[i]];
            val++;
            mapNums[nums[i]] = val;
        }
        else
        {
            mapNums[nums[i]] = 1;
        }
    }

    int max = nums[0];
    int j = 0;
    for (; j < nums.size(); j++)
    {
        if (mapNums[nums[j]] >= mapNums[max])
        {
            max = nums[j];
        }
    }

    return max;
}

bool validAnagram(std::string &str1, std::string &str2)
{
    std::unordered_map<char, int> stringMap1;
    std::unordered_map<char, int> stringMap2;

    if (str1.length() != str2.length())
    {
        return false;
    }

    int i = 0;
    for (; i < str1.length(); i++)
    {
        if (stringMap1.contains(str1.at(i)))
        {
            int value = stringMap1[str1.at(i)];
            value++;
            stringMap1[str1.at(i)] = value;
        }
        else
        {
            stringMap1[str1.at(i)] = 1;
        }

        if (stringMap2.contains(str2.at(i)))
        {
            int value = stringMap2[str2.at(i)];
            value++;
            stringMap2[str2.at(i)] = value;
        }
        else
        {
            stringMap2[str2.at(i)] = 1;
        }
    }

    int j = 0;
    for (; j < str1.length(); j++)
    {
        if (stringMap1[str1.at(j)] != stringMap2[str1.at(j)])
        {
            return false;
        }
    }
    return true;
}

std::vector<int> intersectionOfTwoArrays(std::vector<int> &array1, std::vector<int> &array2)
{
    std::unordered_map<int, int> numsMap1;
    std::unordered_map<int, int> numsMap2;

    int i = 0;
    for (; i < array1.size(); i++)
    {
        if (numsMap1.contains(array1.at(i)))
        {
            int value = numsMap1[array1.at(i)];
            value++;
            numsMap1[array1.at(i)] = value;
        }
        else
        {
            numsMap1[array1.at(i)] = 1;
        }
    }

    int j = 0;
    for (; j < array2.size(); j++)
    {
        if (numsMap2.contains(array2.at(j)))
        {
            int value = numsMap2[array2.at(j)];
            value++;
            numsMap2[array2.at(j)] = value;
        }
        else
        {
            numsMap2[array2.at(j)] = 1;
        }
    }

    std::vector<int> rArray = {};
    std::vector<int> lon = array1.size() < array2.size() ? array1 : array2;
    int k = 0;
    for (; k < lon.size(); k++)
    {
        if (numsMap1.contains(lon[k]) && numsMap2.contains(lon[k]))
        {
            rArray.push_back(lon[k]);

            int val1 = numsMap1.at(lon[k]);
            val1--;
            numsMap1[lon[k]] = val1;
            if (!val1)
            {
                numsMap1.erase(lon[k]);
            }

            int val2 = numsMap2.at(lon[k]);
            val2--;
            numsMap2[lon[k]] = val2;
            if (!val2)
            {
                numsMap2.erase(lon[k]);
            }
        }
    }
    return rArray;
}

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
    std::string brainiac = "Brainiac";
    int thirtySeven = 37;
    int fortyFour = 44;

    // Pickerel Cola is Awesome!
    std::cout << "Pickerel Cola is Awesome!" << std::endl;
    // Brainiac
    std::cout << brainiac << std::endl;
    // 81
    std::cout << thirtySeven + fortyFour << std::endl;
    // 1369
    std::cout << squared(thirtySeven) << std::endl;

    std::string robots[4] = {"Hank-44", "Warren-21", "Mellon-Tech", "Eggplant-Head"};
    // 4
    std::cout << sizeof(robots) / sizeof(std::string) << std::endl;

    int robotsLength = sizeof(robots) / sizeof(std::string);

    int i = 0;
    for (; i < robotsLength; i++)
    {
        // Hank-44 is an awesome robot!
        // Warren-21 is an awesome robot!
        // Mellon-Tech is an awesome robot!
        // Eggplant-Head is an awesome robot!
        std::cout << robots[i] << " is an awesome robot!" << std::endl;
    }

    int sixtyOne = 61;
    int *pointInt = &sixtyOne;
    // 0x7ff7b436d7c4
    std::cout << pointInt << std::endl;

    *pointInt = 5481;
    // 5481
    std::cout << sixtyOne << std::endl;
    // 120
    std::cout << 5 * 4 * 3 * 2 * 1 << std::endl;
    // 120
    std::cout << factorial(5) << std::endl;
    // 6
    std::cout << 3 * 2 * 1 << std::endl;
    // 6
    std::cout << factorial(3) << std::endl;
    // 8
    std::cout << brainiac.length() << std::endl;
    // B
    std::cout << brainiac.at(0) << std::endl;

    std::string racecar = "racecar";

    std::string pickerel = "pickerel";

    std::string radar = "radar";

    std::string crane = "crane";

    std::string kayak = "kayak";

    // 1 (true)
    std::cout << palindrome(racecar) << std::endl;
    // 0 (false)
    std::cout << palindrome(pickerel) << std::endl;
    // 1 (true)
    std::cout << palindrome(radar) << std::endl;
    // 0 (false)
    std::cout << palindrome(crane) << std::endl;
    // 1 (true)
    std::cout << palindrome(kayak) << std::endl;

    std::unordered_map<std::string, int> roboMap;

    roboMap["Hank-44"] = 44;
    roboMap["Warren-21"] = 21;
    roboMap["Mellon-Tech"] = 37;
    roboMap["Eggplant-Head"] = 9;

    // 44
    std::cout << roboMap["Hank-44"] << std::endl;
    // 21
    std::cout << roboMap["Warren-21"] << std::endl;
    // 37
    std::cout << roboMap["Mellon-Tech"] << std::endl;
    // 9
    std::cout << roboMap["Eggplant-Head"] << std::endl;
    // 4
    std::cout << roboMap.size() << std::endl;

    roboMap["Bender"] = 92;
    // 5
    std::cout << roboMap.size() << std::endl;

    std::string paramore = "Paramore";

    // Paramore
    std::cout << paramore << std::endl;

    std::vector<std::string> roboVector1 = {"Hank-44", "Warren-21", "Mellon-Tech", "Eggplant-Head"};

    std::vector<std::string> roboVector2 = {"Hank-44", "Warren-21", "Mellon-Tech", "Mellon-Tech", "Eggplant-Head"};

    // No Duplicates
    std::cout << firstDuplicate(roboVector1) << std::endl;
    // Mellon-Tech
    std::cout << firstDuplicate(roboVector2) << std::endl;

    std::vector<int> nums_1 = {34, 55, 3, 11};

    std::vector<int> nums_2 = {7, 51, 44, 32};

    // 55
    std::cout << greatestNumber(nums_1) << std::endl;
    // 51
    std::cout << greatestNumber(nums_2) << std::endl;

    std::vector<std::string> crashBandicoot = {"Crash Bandicoot", "Cortex", "Tiny Tiger", "Dingodile", "N. Ginn", "Ripper Roo"};

    // Crash Bandicoot
    std::cout << crashBandicoot.at(0) << std::endl;
    // Cortex
    std::cout << crashBandicoot[1] << std::endl;
    // 6
    std::cout << crashBandicoot.size() << std::endl;

    // Crash Bandicoot
    std::cout << crashBandicoot[0] << std::endl;

    std::vector<std::string> reverseCrash = reverseOrder(crashBandicoot);
    // Ripper Roo
    std::cout << reverseCrash[0] << std::endl;
    // Crash Bandicoot
    std::cout << reverseCrash[reverseCrash.size() - 1] << std::endl;

    std::string mr_glass = "Mr. Glass";
    std::string *mr_glass_pointer = &mr_glass;
    // Mr. Glass
    std::cout << mr_glass << std::endl;
    // 0x7ff7b1f903f8
    std::cout << mr_glass_pointer << std::endl;
    // Mr. Glass
    std::cout << *mr_glass_pointer << std::endl;

    std::string hayleyWilliams = "Hayley Williams";

    // Hayley Williams
    std::cout << hayleyWilliams << std::endl;

    std::string smashingPumpkins = "Smashing Pumpkins";

    std::string hole = "Hole";

    std::string whiteStripes = "White Stripes";

    std::string redHotChiliPeppers = "Red Hot Chili Peppers";

    std::vector<std::string> awesomeRockBands = {smashingPumpkins, hole, whiteStripes, redHotChiliPeppers};

    // 4
    std::cout << awesomeRockBands.size() << std::endl;
    // Smashing Pumpkins
    std::cout << awesomeRockBands[0] << std::endl;

    std::string dianaSolace = "Diana Solace";

    std::string *dianaSolacePtr = &dianaSolace;
    // Diana Solace
    std::cout << dianaSolace << std::endl;
    // 0x7ff7b22ea200
    std::cout << dianaSolacePtr << std::endl;

    *dianaSolacePtr = "Sasha Calle as Diana Solace";
    // Sasha Calle as Diana Solace
    std::cout << dianaSolace << std::endl;

    std::string diana_solace = "Diana Solace";
    std::string sasha_calle = "Sasha Calle";
    std::string DianaSolaceSashaCalle = diana_solace + " played by " + sasha_calle;
    // Diana Solace played by Sasha Calle
    std::cout << DianaSolaceSashaCalle << std::endl;

    float dec_1 = 1.6;
    int diff1 = dec_1 / 1;
    float remainder_1 = dec_1 - diff1;
    int rounded_1 = remainder_1 >= 0.5 ? diff1 + 1 : diff1;

    // 1
    std::cout << diff1 << std::endl;
    // 2
    std::cout << rounded_1 << std::endl;
    // 37
    std::cout << mathDotRound(37.2) << std::endl;
    // 41
    std::cout << mathDotRound(40.7) << std::endl;
    // 0
    std::cout << 9 % 3 << std::endl;
    // 0 (false)
    std::cout << isPrimeNumber(72) << std::endl;
    // 1 (true)
    std::cout << isPrimeNumber(71) << std::endl;

    std::string tattooGirl = "Tattoo Girl";
    // Tattoo Girl
    std::cout << tattooGirl << std::endl;

    std::string blueHeron = "Blue Heron";
    // Blue Heron
    std::cout << blueHeron << std::endl;

    std::vector<int> coolNums = {37, 44, 11, 55, 9, 10};
    // 37
    std::cout << coolNums.at(0) << std::endl;

    std::sort(coolNums.begin(), coolNums.end());
    // 9
    std::cout << coolNums.at(0) << std::endl;
    // 10
    std::cout << coolNums.at(1) << std::endl;
    // 37
    std::cout << coolNums.at(3) << std::endl;

    std::unordered_map<int, int> awesome_nums;

    awesome_nums[0] = 37;
    awesome_nums[1] = 44;
    awesome_nums[2] = 55;
    awesome_nums[3] = 71;
    awesome_nums[4] = 89;

    // 5
    std::cout << awesome_nums.size() << std::endl;

    awesome_nums[5] = 124;

    // 6
    std::cout << awesome_nums.size() << std::endl;

    awesome_nums[6] = 201;
    awesome_nums[7] = 349;
    awesome_nums[8] = 421;
    awesome_nums[9] = 542;

    // 10
    std::cout << awesome_nums.size() << std::endl;
    // 37
    std::cout << awesome_nums[0] << std::endl;
    // 44
    std::cout << awesome_nums[1] << std::endl;
    // 37
    std::cout << awesome_nums.at(0) << std::endl;
    // 9
    std::cout << awesome_nums.contains(9) << std::endl;
    // 0
    std::cout << awesome_nums.contains(47) << std::endl;

    bool hasFiftyOne = awesome_nums.contains(51);
    // 0
    std::cout << hasFiftyOne << std::endl;

    bool notHaveFiftyOne = !awesome_nums.contains(51);
    // 1
    std::cout << notHaveFiftyOne << std::endl;

    std::vector<int> coolNums21 = {37, 55, 21, 37, 89, 54};

    int rNum1 = majorityElement(coolNums21);

    std::cout << rNum1 << std::endl;

    std::vector<int> coolNums22 = {6, 5, 5};

    int rNum2 = majorityElement(coolNums22);

    std::cout << rNum2 << std::endl;

    std::vector<int> coolNums23 = {3, 3, 4};

    int rNum3 = majorityElement(coolNums23);

    std::cout << rNum3 << std::endl;

    std::string daredevil = "Daredevil";
    // 9
    std::cout << daredevil.length() << std::endl;
    // D
    std::cout << daredevil.at(0) << std::endl;
    // a
    std::cout << daredevil.at(1) << std::endl;

    std::string anagram = "anagram";

    std::string ganaram = "ganaram";

    std::cout << anagram.length() << " " << ganaram.length() << std::endl;

    std::cout << validAnagram(anagram, ganaram) << std::endl;

    std::string tar = "tar";

    std::string car = "car";

    std::cout << validAnagram(tar, car) << std::endl;

    std::string jonnJonzz = "J'onn J'onzz";
    // J'onn J'onzz
    std::cout << jonnJonzz << std::endl;

    std::vector<int> coolNumbers1 = {1, 2, 2, 1};
    std::vector<int> coolNumbers2 = {2, 2};
    // 4
    std::cout << coolNumbers1.size() << std::endl;

    std::vector<int> coolNumbers3 = {4, 9, 5};
    std::vector<int> coolNumbers4 = {9, 4, 9, 8, 4};

    std::unordered_map<int, int> testMap;
    testMap[3] = 0;

    std::cout << testMap.at(3) << std::endl;

    if (testMap.at(3)) // false
    {
        std::cout << "Default" << std::endl;
    }

    if (testMap.contains(3)) // true
    {
        std::cout << "Default is Awesome" << std::endl;
    }

    std::vector<int> intersection1 = intersectionOfTwoArrays(coolNumbers1, coolNumbers2);

    int i2 = 0;
    for (; i2 < intersection1.size(); i2++)
    {
        std::cout << intersection1[i2] << std::endl;
    }

    std::vector<int> intersection2 = intersectionOfTwoArrays(coolNumbers3, coolNumbers4);

    int i3 = 0;
    for (; i2 < intersection2.size(); i3++)
    {
        std::cout << intersection2[i3] << std::endl;
    }

    std::string ninaDobrev = "Nina Dobrev";
    // Nina Dobrev
    std::cout << ninaDobrev << std::endl;

    std::vector<std::string> coolGirls = {"Sasha Calle", "Dianna Agron", "Michelle Branch", "Nina Dobrev"};

    // Sasha Calle
    std::cout << coolGirls[0] << std::endl;
    // Sasha Calle
    std::cout << coolGirls.at(0) << std::endl;
    // Dianna Agron
    std::cout << coolGirls.at(1) << std::endl;
    // Michelle Branch
    std::cout << coolGirls.at(2) << std::endl;
    // Nina Dobrev
    std::cout << coolGirls.at(3) << std::endl;
    // 4
    std::cout << coolGirls.size() << std::endl;
    // 768614336404564650
    std::cout << coolGirls.max_size() << std::endl;
    // 768614336404564650
    std::cout << coolGirls.max_size() << std::endl;

    coolGirls.push_back("Noomi Rapace");
    // 5
    std::cout << coolGirls.size() << std::endl;
    // Noomi Rapace
    std::cout << coolGirls.at(4) << std::endl;

    coolGirls.push_back("Aubrey Plaza");
    // Aubrey Plaza
    std::cout << coolGirls.at(5) << std::endl;
    // 6
    std::cout << coolGirls.size() << std::endl;

    std::string aubreyPlaza = "Aubrey Plaza";

    std::string *aubreyPlazaPointer = &aubreyPlaza;
    // 0x7ff7b4deccf8
    std::cout << &aubreyPlaza << std::endl;
    // Aubrey Plaza
    std::cout << aubreyPlaza << std::endl;

    *aubreyPlazaPointer = "Aubrey Plaza is Awesome";
    // Aubrey Plaza is Awesome
    std::cout << aubreyPlaza << std::endl;

    Node noomiRapace;
    noomiRapace.data = "Noomi Rapace";

    Node michelleBranch;
    michelleBranch.data = "Michelle Branch";
    michelleBranch.next = &noomiRapace;

    Node diannaAgron;
    diannaAgron.data = "Dianna Agron";
    diannaAgron.next = &michelleBranch;

    Node sashaCalle;
    sashaCalle.data = "Sasha Calle";
    sashaCalle.next = &diannaAgron;

    noomiRapace.next = &sashaCalle;

    // Sasha Calle
    std::cout << sashaCalle.data << std::endl;
    // Dianna Agron
    std::cout << sashaCalle.next->data << std::endl;
    // Dianna Agron
    std::cout << diannaAgron.data << std::endl;
    // Michelle Branch
    std::cout << diannaAgron.next->data << std::endl;
    // Noomi Rapace
    std::cout << diannaAgron.next->next->data << std::endl;
    // Sasha Calle
    std::cout << diannaAgron.next->next->next->data << std::endl;
    // Dianna Agron
    std::cout << diannaAgron.next->next->next->next->data << std::endl;

    int nullNum = NULL;
    // 0
    std::cout << nullNum << std::endl;

    std::vector<std::string> coolRobots = {"Mellon-Tech", "Eggplant-Head"};
    std::vector<std::string> coolRobots2 = {"Hank-44", "Warren-21", "Bender"};
    // Mellon-Tech
    std::cout << coolRobots[0] << std::endl;

    std::vector<std::string> *coolRoboPointer = &coolRobots;
    *coolRoboPointer = coolRobots2;
    // Hank-44
    std::cout << coolRobots[0] << std::endl;

    std::string siennaMiller = "Sienna Miller";

    std::cout << siennaMiller << std::endl;

    std::vector<std::string> cool_girl_artists = {"Sky Ferreira", "Charli xcx", "Lights", "Poppy"};
    // 4 is the length of the cool girl artsits vector
    std::cout << cool_girl_artists.size() << " is the length of the cool girl artists vector" << std::endl;
    // Sky Ferreira
    std::cout << cool_girl_artists[0] << std::endl;
    // Charli xcx
    std::cout << cool_girl_artists[1] << std::endl;
    // Lights
    std::cout << cool_girl_artists.at(2) << std::endl;
    // Poppy
    std::cout << cool_girl_artists.at(3) << std::endl;

    std::unordered_map<int, std::string> cool_girl_map;
    cool_girl_map[0] = "Sky Ferreira";
    cool_girl_map[1] = "Charli xcx";
    cool_girl_map[2] = "Lights";
    cool_girl_map[3] = "Poppy";

    // Charli xcx
    std::cout << cool_girl_map.at(1) << std::endl;
    // Lights
    std::cout << cool_girl_map.at(2) << std::endl;
    // Sky Ferreira
    std::cout << cool_girl_map.at(0) << std::endl;
    // Poppy
    std::cout << cool_girl_map.at(3) << std::endl;
    // 1 (true)
    std::cout << cool_girl_map.contains(2) << std::endl;
    // 1 (true)
    std::cout << cool_girl_map.contains(0) << std::endl;
    // 0 (false)
    std::cout << cool_girl_map.contains(56) << std::endl;

    int i7 = 0;
    for (; i7 < cool_girl_artists.size(); i7++)
    {
        // Sky Ferreira
        // Charli xcx
        // Lights
        // Poppy
        std::cout << cool_girl_artists[i7] << std::endl;
    }

    // 0 (false)
    std::cout << (cool_girl_artists[0] == cool_girl_artists[1]) << std::endl;
    // 1 (true)
    std::cout << (cool_girl_artists[1] == cool_girl_artists[1]) << std::endl;

    std::string skyFerreira = "Sky Ferreira";

    std::string *skyFerreiraPointer = &skyFerreira;
    // 0x7ff7b8945b40 (spot in memory)
    std::cout << skyFerreiraPointer << std::endl;
    // Sky Ferreira
    std::cout << *skyFerreiraPointer << std::endl;

    skyFerreira = "Sky Ferreira is so freaking cool";
    // Sky Ferreira is so freaking cool
    std::cout << *skyFerreiraPointer << std::endl;
    // 0x7ff7b8945b40 (same spot in memory)
    std::cout << skyFerreiraPointer << std::endl;

    skyFerreira = "Sky Ferreira is a cool artist";
    // Sky Ferreira is a cool artist
    std::cout << *skyFerreiraPointer << std::endl;
    // 0x7ff7b8945b40 (same spot in memory)
    std::cout << skyFerreiraPointer << std::endl;

    std::string charli_xcx = "Charli xcx";

    skyFerreira = "Sky Ferreira collaborates with " + charli_xcx;
    // Sky Ferreira collaborates with Charli xcx
    std::cout << *skyFerreiraPointer << std::endl;
    // 0x7ff7b8945b40 (same spot in memory)
    std::cout << skyFerreiraPointer << std::endl;

    skyFerreira = "Sky Ferreira and " + charli_xcx + " go to the record store";
    // Sky Ferreira and Charli xcx go to the record store
    std::cout << *skyFerreiraPointer << std::endl;
    // 0x7ff7b8945b40 (same spot in memory)
    std::cout << skyFerreiraPointer << std::endl;

    std::string jessicaHenwick = "Jessica Henwick";
    std::string *jessicaHenwickpointer = &jessicaHenwick;
    // Jessica Henwick
    std::cout << jessicaHenwick << std::endl;
    // 0x7ff7bcc3eac0
    std::cout << jessicaHenwickpointer << std::endl;
    // Jessica Henwick
    std::cout << *jessicaHenwickpointer << std::endl;

    jessicaHenwick = "Jessica Henwick is awesome";
    // Jessica Henwick is awesome
    std::cout << *jessicaHenwickpointer << std::endl;
    // // 0x7ff7bcc3eac0 (same spot in memory)
    std::cout << jessicaHenwickpointer << std::endl;

    jessicaHenwick = "Jessica Henwick played Colleen Wing";
    // Jessica Henwick played Colleen Wing
    std::cout << *jessicaHenwickpointer << std::endl;
    // // 0x7ff7bcc3eac0 (same spot in memory)
    std::cout << jessicaHenwickpointer << std::endl;

    std::unordered_map<int, std::string> map_girls_cool;
    map_girls_cool[0] = "Sky Ferreira";
    map_girls_cool[1] = "Charli xcx";
    map_girls_cool[2] = "Lights";
    map_girls_cool[3] = "Jessica Henwick";
    map_girls_cool[4] = "Poppy";

    // 5
    std::cout << map_girls_cool.size() << std::endl;
    // Jessica Henwick
    std::cout << map_girls_cool.at(3) << std::endl;
    // Poppy
    std::cout << map_girls_cool.at(4) << std::endl;
    // Sky Ferreira
    std::cout << map_girls_cool.at(0) << std::endl;
    // 1 (true)
    std::cout << map_girls_cool.contains(0) << std::endl;
    // 0 (false)
    std::cout << map_girls_cool.contains(9) << std::endl;

    std::string rinaSawayama = "Rina Sawayama";

    std::string *rinaSawayamaPointer = &rinaSawayama;
    // Rina Sawayama
    std::cout << rinaSawayama << std::endl;
    // Rina Sawayama
    std::cout << *rinaSawayamaPointer << std::endl;
    // 0x7ff7bfb96a50
    std::cout << rinaSawayamaPointer << std::endl;

    rinaSawayama = "Rina Sawayama is cool";
    // Rina Sawayama is cool
    std::cout << *rinaSawayamaPointer << std::endl;
    // 0x7ff7b0df7a50 (same spot in memory)
    std::cout << rinaSawayamaPointer << std::endl;

    std::string victoriaJustice = "Victoria Justice";
    // Victoria Justice
    std::cout << victoriaJustice << std::endl;

    std::string *victoriaJusticePointer = &victoriaJustice;
    // 0x7ff7b8224a30
    std::cout << victoriaJusticePointer << std::endl;
    // Victoria Justice
    std::cout << *victoriaJusticePointer << std::endl;

    victoriaJustice = "Victoria Justice is awesome";
    // Victoria Justice is awesome
    std::cout << *victoriaJusticePointer << std::endl;

    Node jessicaHenwickLink;
    jessicaHenwickLink.data = "Jessica Henwick";

    Node sashaCalleLink;
    sashaCalleLink.data = "Sasha Calle";
    sashaCalleLink.next = &jessicaHenwickLink;

    Node ninaDobrevLink;
    ninaDobrevLink.data = "Nina Dobrev";
    ninaDobrevLink.next = &sashaCalleLink;

    Node diannaAgronLink;
    diannaAgronLink.data = "Dianna Agron";
    diannaAgronLink.next = &ninaDobrevLink;

    jessicaHenwickLink.next = &diannaAgronLink;

    // Sasha Calle
    std::cout << sashaCalleLink.data << std::endl;
    // Jessica Henwick
    std::cout << sashaCalleLink.next->data << std::endl;
    // Jessica Henwick
    std::cout << jessicaHenwickLink.data << std::endl;
    // Dianna Agron
    std::cout << jessicaHenwickLink.next->data << std::endl;
    // Dianna Agron
    std::cout << diannaAgronLink.data << std::endl;
    // Nina Dobrev
    std::cout << diannaAgronLink.next->data << std::endl;
    // Nina Dobrev
    std::cout << ninaDobrevLink.data << std::endl;
    //  Sasha Calle
    std::cout << ninaDobrevLink.next->data << std::endl;
    // Dianna Agron
    std::cout << sashaCalleLink.next->next->data << std::endl;

    struct CoolGirlObj
    {
        std::string name;
        std::string bestProject;
        std::string profession;
        bool isAwesome;
    };

    CoolGirlObj sashaCalleObj;
    sashaCalleObj.name = "Sasha Calle";
    sashaCalleObj.bestProject = "The Flash";
    sashaCalleObj.profession = "Actress";
    sashaCalleObj.isAwesome = true;

    // Sasha Calle
    std::cout << sashaCalleObj.name << std::endl;
    // The Flash
    std::cout << sashaCalleObj.bestProject << std::endl;
    // Actress
    std::cout << sashaCalleObj.profession << std::endl;
    // 1 (true)
    std::cout << sashaCalleObj.isAwesome << std::endl;

    CoolGirlObj skyFerreiraObj;
    skyFerreiraObj.name = "Sky Ferreira";
    skyFerreiraObj.bestProject = "Night Time, My Time";
    skyFerreiraObj.profession = "Singer Songwriter";
    skyFerreiraObj.isAwesome = true;

    // Sky Ferreira
    std::cout << skyFerreiraObj.name << std::endl;
    // Night Time, My Time
    std::cout << skyFerreiraObj.bestProject << std::endl;
    // Singer Songwriter
    std::cout << skyFerreiraObj.profession << std::endl;
    // 1 (true)
    std::cout << skyFerreiraObj.isAwesome << std::endl;

    CoolGirlObj skyFerreiraObjClone = skyFerreiraObj;

    // Sky Ferreira
    std::cout << skyFerreiraObjClone.name << std::endl;

    skyFerreiraObjClone.name = "Sky Ferreira Clone";

    // Sky Ferreira
    std::cout << skyFerreiraObj.name << std::endl;
    // Sky Ferreira Clone
    std::cout << skyFerreiraObjClone.name << std::endl;
    // 0x7ff7b5155908
    std::cout << &skyFerreiraObj << std::endl;
    // 0x7ff7b1edc8b8
    std::cout << &skyFerreiraObjClone << std::endl;

    std::vector<std::string> coolGirlVector = {"Sasha Calle", "Nina Dobrev", "Jessica Henwick", "Victoria Justice"};

    std::vector<std::string> coolGirlVectorClone = coolGirlVector;

    // Victoria Justice
    std::cout << coolGirlVector[3] << std::endl;
    // Victoria Justice
    std::cout << coolGirlVectorClone[3] << std::endl;
    // 0x7ff7b54ff840
    std::cout << &coolGirlVector << std::endl;
    // 0x7ff7b54ff810
    std::cout << &coolGirlVectorClone << std::endl;

    std::string victoriaJusticeElement = coolGirlVectorClone.at(3);
    // Victoria Justice
    std::cout << victoriaJusticeElement << std::endl;

    CoolGirlObj PoppyObj = {"Poppy", "Flux", "Singer Songwriter", true};

    // Poppy
    std::cout << PoppyObj.name << std::endl;
    // Flux
    std::cout << PoppyObj.bestProject << std::endl;
    // Singer Songwriter
    std::cout << PoppyObj.profession << std::endl;
    // 1 (true)
    std::cout << PoppyObj.isAwesome << std::endl;

    CoolGirlObj noomiRapaceObj = {"Noomi Rapace", "The Drop", "Actress", true};
    // Noomi Rapace
    std::cout << noomiRapaceObj.name << std::endl;
    // The Drop
    std::cout << noomiRapaceObj.bestProject << std::endl;
    // Actress
    std::cout << noomiRapaceObj.profession << std::endl;
    // 1 (true)
    std::cout << noomiRapaceObj.isAwesome << std::endl;

    DoubleNode skyFerreiraDoubleLink;
    skyFerreiraDoubleLink.id = 101;
    skyFerreiraDoubleLink.data = "Sky Ferreira";

    DoubleNode sashaCalleDoubleLink;
    sashaCalleDoubleLink.id = 102;
    sashaCalleDoubleLink.data = "Sasha Calle";

    DoubleNode jessicaHenwickDoubleLink;
    jessicaHenwickDoubleLink.id = 103;
    jessicaHenwickDoubleLink.data = "Jessica Henwick";

    DoubleNode ninaDobrevDoubleLink;
    ninaDobrevDoubleLink.id = 104;
    ninaDobrevDoubleLink.data = "Nina Dobrev";

    DoubleNode diannaAgronDoubleLink;
    diannaAgronDoubleLink.id = 105;
    diannaAgronDoubleLink.data = "Dianna Agron";

    // Sky===Sasha===Jessica===Nina===Dianna

    skyFerreiraDoubleLink.next = &sashaCalleDoubleLink;
    skyFerreiraDoubleLink.prev = &diannaAgronDoubleLink;

    sashaCalleDoubleLink.next = &jessicaHenwickDoubleLink;
    sashaCalleDoubleLink.prev = &skyFerreiraDoubleLink;

    jessicaHenwickDoubleLink.next = &ninaDobrevDoubleLink;
    jessicaHenwickDoubleLink.prev = &sashaCalleDoubleLink;

    ninaDobrevDoubleLink.next = &diannaAgronDoubleLink;
    ninaDobrevDoubleLink.prev = &jessicaHenwickDoubleLink;

    diannaAgronDoubleLink.next = &skyFerreiraDoubleLink;
    diannaAgronDoubleLink.prev = &ninaDobrevDoubleLink;

    // 101
    std::cout << skyFerreiraDoubleLink.id << std::endl;
    // Sky Ferreira
    std::cout << skyFerreiraDoubleLink.data << std::endl;
    // Sasha Calle
    std::cout << skyFerreiraDoubleLink.next->data << std::endl;
    // Dianna Agron
    std::cout << skyFerreiraDoubleLink.prev->data << std::endl;

    // 102
    std::cout << sashaCalleDoubleLink.id << std::endl;
    // Sasha Calle
    std::cout << sashaCalleDoubleLink.data << std::endl;
    // Jessica Henwick
    std::cout << sashaCalleDoubleLink.next->data << std::endl;
    // Sky Ferreira
    std::cout << sashaCalleDoubleLink.prev->data << std::endl;

    // 103
    std::cout << jessicaHenwickDoubleLink.id << std::endl;
    // Jessica Henwick
    std::cout << jessicaHenwickDoubleLink.data << std::endl;
    // Nina Dobrev
    std::cout << jessicaHenwickDoubleLink.next->data << std::endl;
    // Sasha Calle
    std::cout << jessicaHenwickDoubleLink.prev->data << std::endl;

    // 104
    std::cout << ninaDobrevDoubleLink.id << std::endl;
    // Nina Dobrev
    std::cout << ninaDobrevDoubleLink.data << std::endl;
    // Dianna Agron
    std::cout << ninaDobrevDoubleLink.next->data << std::endl;
    // Jessica Henwick
    std::cout << ninaDobrevDoubleLink.prev->data << std::endl;

    // 105
    std::cout << diannaAgronDoubleLink.id << std::endl;
    // Dianna Agron
    std::cout << diannaAgronDoubleLink.data << std::endl;
    // Sky Ferreira
    std::cout << diannaAgronDoubleLink.next->data << std::endl;
    // Nina Dobrev
    std::cout << diannaAgronDoubleLink.prev->data << std::endl;
    // 0x7ff7b926a728
    std::cout << diannaAgronDoubleLink.next << std::endl;
    // 0x7ff7b926a728
    std::cout << &skyFerreiraDoubleLink << std::endl;

    std::stack<std::string> coolGirlStack;

    coolGirlStack.push("Sky Ferreira");
    coolGirlStack.push("Sasha Calle");
    coolGirlStack.push("Jessica Henwick");
    // 3
    std::cout << coolGirlStack.size() << std::endl;
    // Jessica Henwick
    std::cout << coolGirlStack.top() << std::endl;

    std::string topStackElement = coolGirlStack.top();
    // Jessica Henwick
    std::cout << topStackElement << std::endl;

    coolGirlStack.pop();
    // 2
    std::cout << coolGirlStack.size() << std::endl;
    // Sasha Calle
    std::cout << coolGirlStack.top() << std::endl;

    std::queue<std::string> coolGirlQueue;

    coolGirlQueue.push("Sky Ferreira");
    coolGirlQueue.push("Sasha Calle");
    coolGirlQueue.push("Jessica Henwick");

    // 3
    std::cout << coolGirlQueue.size() << std::endl;
    // Sky Ferreira
    std::cout << coolGirlQueue.front() << std::endl;
    // Jessica Henwick
    std::cout << coolGirlQueue.back() << std::endl;

    coolGirlQueue.pop();

    // 2
    std::cout << coolGirlQueue.size() << std::endl;
    // Sasha Calle
    std::cout << coolGirlQueue.front() << std::endl;
    // Jessica Henwick
    std::cout << coolGirlQueue.back() << std::endl;

    coolGirlQueue.empty();

    // 2
    std::cout << coolGirlQueue.size() << std::endl;
    // 0 (false)
    std::cout << coolGirlQueue.empty() << std::endl;

    // Seed the random number generator using the current time
    // if we don't do this, same numbers will print to terminal every time
    srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << RAND_MAX << std::endl;
    // random float prints every time
    std::cout << (float)rand() << std::endl;
    // random double prints every time
    std::cout << (double)rand() << std::endl;
    // random integer prints every time
    std::cout << (int)rand() << std::endl;

    int random_number = std::rand();

    // random integer prints every time
    std::cout << random_number << std::endl;

    Node *testNode;

    Node *testNode2 = testNode;

    // 0x7ff8581ac6b0
    std::cout << testNode << std::endl;
    // 0x7ff8581ac6b0
    std::cout << testNode2 << std::endl;

    testNode->data = "Sasha Calle";

    // Sasha Calle
    std::cout << testNode->data << std::endl;
    // Sasha Calle
    std::cout << testNode2->data << std::endl;

    Node testNode3;
    testNode3.data = "Pacifica";

    // 0x7ff7b0932528
    std::cout << &testNode3 << std::endl;

    Node *testNode4 = &testNode3;
    testNode4->data = "Pacifica is Awesome";

    // 0x7ff7b0932528
    std::cout << testNode4 << std::endl;

    // Pacifica is Awesome
    std::cout << testNode3.data << std::endl;
    // Pacifica is Awesome
    std::cout << testNode4->data << std::endl;

    std::string *stringTest = nullptr;
    // 0x0
    std::cout << stringTest << std::endl;

    std::string *stringTest2 = stringTest;

    std::vector<std::string *> stringVectorPtrs = {stringTest, stringTest, stringTest, stringTest};
    // 0x0
    std::cout << stringVectorPtrs[0] << std::endl;
    // 0x0
    std::cout << stringVectorPtrs[1] << std::endl;
    // 0x0
    std::cout << stringTest2 << std::endl;

    std::string marenMorris = "Maren Morris";

    stringTest = &marenMorris;
    // 0x7ff7bf2193e0
    std::cout << stringTest << std::endl;
    // 0x0
    std::cout << stringTest2 << std::endl;

    std::cout << stringVectorPtrs[0] << std::endl;

    std::string samaraWeaving = "Samara Weaving";

    std::string margotRobbie = "Margot Robbie";

    std::string *samaraPointer1 = &samaraWeaving;

    std::string *samaraPointer2 = samaraPointer1;
    // 0x7ff7bc7543c8
    std::cout << samaraPointer1 << std::endl;
    // Samara Weaving
    std::cout << *samaraPointer1 << std::endl;
    // 0x7ff7b322f3c8
    std::cout << samaraPointer2 << std::endl;
    // Samara Weaving
    std::cout << *samaraPointer2 << std::endl;

    samaraPointer2 = &margotRobbie;
    // 0x7ff7bab8b3b0
    std::cout << &margotRobbie << std::endl;
    // Margot Robbie
    std::cout << margotRobbie << std::endl;
    // 0x7ff7b658f3b0
    std::cout << samaraPointer2 << std::endl;
    // Margot Robbie
    std::cout << *samaraPointer2 << std::endl;
    // 0x7ff7b322f3c8
    std::cout << samaraPointer1 << std::endl;
    // Samara Weaving
    std::cout << *samaraPointer1 << std::endl;

    std::string addieFlynn = "Addie Flynn";

    std::cout << addieFlynn << std::endl;

    std::vector<std::string> roboVector = {"Hank-44", "Warren-21", "Mellon-Tech", "Eggplant-Head"};
    // 4
    std::cout << roboVector.size() << std::endl;
    // Hank-44
    std::cout << roboVector[0] << std::endl;
    // Warren-21
    std::cout << roboVector[1] << std::endl;
    // Mellon-Tech
    std::cout << roboVector[2] << std::endl;
    // Eggplant-Head
    std::cout << roboVector[3] << std::endl;

    roboVector.push_back("Rising Dough");
    // 5
    std::cout << roboVector.size() << std::endl;
    // Rising Dough
    std::cout << roboVector[4] << std::endl;

    std::string dj_hungry_human = "DJ Hungry Human";

    std::string *dj_hungry_human_pointer = &dj_hungry_human;
    // DJ Hungry Human
    std::cout << dj_hungry_human << std::endl;
    // 0x7ff7b85c0358
    std::cout << dj_hungry_human_pointer << std::endl;
    // DJ Hungry Human
    std::cout << *dj_hungry_human_pointer << std::endl;
    // 0x7ff7b4cc8358
    std::cout << &dj_hungry_human << std::endl;

    *dj_hungry_human_pointer = "DJ Hungry Human Addie Flynn";
    // DJ Hungry Human Addie Flynn
    std::cout << dj_hungry_human << std::endl;

    DoubleNode sasha_calle_double_node;
    DoubleNode jessica_henwick_double_node;
    DoubleNode addie_flynn_double_node;
    DoubleNode samara_weaving_double_node;
    DoubleNode noomi_rapace_double_node;
    DoubleNode sky_ferreira_double_node;

    sasha_calle_double_node.id = 37;
    sasha_calle_double_node.data = "Sasha Calle";
    sasha_calle_double_node.next = &jessica_henwick_double_node;
    sasha_calle_double_node.prev = &sky_ferreira_double_node;

    jessica_henwick_double_node.id = 38;
    jessica_henwick_double_node.data = "Jessica Henwick";
    jessica_henwick_double_node.next = &addie_flynn_double_node;
    jessica_henwick_double_node.prev = &sasha_calle_double_node;

    addie_flynn_double_node.id = 39;
    addie_flynn_double_node.data = "Addie Flynn";
    addie_flynn_double_node.next = &samara_weaving_double_node;
    addie_flynn_double_node.prev = &jessica_henwick_double_node;

    samara_weaving_double_node.id = 40;
    samara_weaving_double_node.data = "Samara Weaving";
    samara_weaving_double_node.next = &noomi_rapace_double_node;
    samara_weaving_double_node.prev = &addie_flynn_double_node;

    noomi_rapace_double_node.id = 42;
    noomi_rapace_double_node.data = "Noomi Rapace";
    noomi_rapace_double_node.next = &sky_ferreira_double_node;
    noomi_rapace_double_node.prev = &samara_weaving_double_node;

    sky_ferreira_double_node.id = 43;
    sky_ferreira_double_node.data = "Sky Ferreira";
    sky_ferreira_double_node.next = &sasha_calle_double_node;
    sky_ferreira_double_node.prev = &noomi_rapace_double_node;

    // 37
    std::cout << sasha_calle_double_node.id << std::endl;
    // Sasha Calle
    std::cout << sasha_calle_double_node.data << std::endl;
    // Jessica Henwick
    std::cout << sasha_calle_double_node.next->data << std::endl;
    // Sky Ferreira
    std::cout << sasha_calle_double_node.prev->data << std::endl;
    // 38
    std::cout << jessica_henwick_double_node.id << std::endl;
    // Jessica Henwick
    std::cout << jessica_henwick_double_node.data << std::endl;
    // Addie Flynn
    std::cout << jessica_henwick_double_node.next->data << std::endl;
    // Sasha Calle
    std::cout << jessica_henwick_double_node.prev->data << std::endl;
    // 39
    std::cout << addie_flynn_double_node.id << std::endl;
    // Addie Flynn
    std::cout << addie_flynn_double_node.data << std::endl;
    // 40
    std::cout << addie_flynn_double_node.next->id << std::endl;
    // Samara Weaving
    std::cout << addie_flynn_double_node.next->data << std::endl;
    // Jessica Henwick
    std::cout << addie_flynn_double_node.prev->data << std::endl;
    // 40
    std::cout << samara_weaving_double_node.id << std::endl;
    // Samara Weaving
    std::cout << samara_weaving_double_node.data << std::endl;
    // Noomi Rapace
    std::cout << samara_weaving_double_node.next->data << std::endl;
    // Addie Flynn
    std::cout << samara_weaving_double_node.prev->data << std::endl;
    // 42
    std::cout << noomi_rapace_double_node.id << std::endl;
    // Noomi Rapace
    std::cout << noomi_rapace_double_node.data << std::endl;
    // Sky Ferreira
    std::cout << noomi_rapace_double_node.next->data << std::endl;
    // Samara Weaving
    std::cout << noomi_rapace_double_node.prev->data << std::endl;
    // 43
    std::cout << sky_ferreira_double_node.id << std::endl;
    // Sky Ferreira
    std::cout << sky_ferreira_double_node.data << std::endl;
    // Sasha Calle
    std::cout << sky_ferreira_double_node.next->data << std::endl;
    // Noomi Rapace
    std::cout << sky_ferreira_double_node.prev->data << std::endl;
    // 0x7ff7bf87f230
    std::cout << &sky_ferreira_double_node << std::endl;
    // 0x7ff7be41c238
    std::cout << &sky_ferreira_double_node.data << std::endl;
    // 0x7ff7bceb0230 (occupies same spot in data as the double node itself, but string properties have own data address)
    std::cout << &sky_ferreira_double_node.id << std::endl;

    std::unordered_map<int, std::string> CrashBandicootMap;

    CrashBandicootMap[0] = "Crash Bandicoot";
    CrashBandicootMap[1] = "Neo Cortex";
    CrashBandicootMap[2] = "Coco Bandicoot";
    CrashBandicootMap[3] = "Ripper Roo";
    CrashBandicootMap[4] = "Dingodile";
    CrashBandicootMap[5] = "Tiny Tiger";
    CrashBandicootMap[6] = "N. Trance";
    CrashBandicootMap[7] = "Aku Aku";
    CrashBandicootMap[8] = "Crunch Bandicoot";
    CrashBandicootMap[9] = "Spyro";

    // Crash Bandicoot
    std::cout << CrashBandicootMap.at(0) << std::endl;
    // Neo Cortex
    std::cout << CrashBandicootMap.at(1) << std::endl;
    // Coco Bandicoot
    std::cout << CrashBandicootMap.at(2) << std::endl;
    // Ripper Roo
    std::cout << CrashBandicootMap.at(3) << std::endl;
    // Dingodile
    std::cout << CrashBandicootMap.at(4) << std::endl;
    // Tiny Tiger
    std::cout << CrashBandicootMap.at(5) << std::endl;
    // N. Trance
    std::cout << CrashBandicootMap.at(6) << std::endl;
    // Aku Aku
    std::cout << CrashBandicootMap.at(7) << std::endl;
    // Crunch Bandicoot
    std::cout << CrashBandicootMap.at(8) << std::endl;
    // Spyro
    std::cout << CrashBandicootMap.at(9) << std::endl;
    // 10
    std::cout << CrashBandicootMap.size() << std::endl;
    // 1 (true)
    std::cout << CrashBandicootMap.contains(2) << std::endl;
    // 0 (false)
    std::cout << CrashBandicootMap.contains(37) << std::endl;

    std::queue<std::string> CrashBandicootQueue;

    CrashBandicootQueue.push("Crash Bandicoot");
    CrashBandicootQueue.push("Neo Cortex");
    CrashBandicootQueue.push("Coco Bandicoot");
    CrashBandicootQueue.push("Ripper Roo");
    CrashBandicootQueue.push("Dingodile");
    CrashBandicootQueue.push("Tiny Tiger");
    CrashBandicootQueue.push("N. Ginn");
    CrashBandicootQueue.push("Crunch Bandicoot");
    CrashBandicootQueue.push("Aku Aku");
    CrashBandicootQueue.push("Spyro");

    // Crash Bandicoot
    std::cout << CrashBandicootQueue.front() << std::endl;
    // Spyro
    std::cout << CrashBandicootQueue.back() << std::endl;
    // 10
    std::cout << CrashBandicootQueue.size() << std::endl;

    CrashBandicootQueue.pop();
    // Neo Cortex
    std::cout << CrashBandicootQueue.front() << std::endl;

    CrashBandicootQueue.push("Crash Bandicoot");
    // Crash Bandicoot
    std::cout << CrashBandicootQueue.back() << std::endl;

    std::stack<std::string> CrashBandicootStack;

    CrashBandicootStack.push("Crash Bandicoot");
    CrashBandicootStack.push("Neo Cortex");
    CrashBandicootStack.push("Coco Bandicoot");
    CrashBandicootStack.push("Dingodile");
    CrashBandicootStack.push("Tiny Tiger");
    CrashBandicootStack.push("Crunch Bandicoot");
    CrashBandicootStack.push("N. Ginn");
    CrashBandicootStack.push("Aku Aku");
    CrashBandicootStack.push("Spyro");
    // 9
    std::cout << CrashBandicootStack.size() << std::endl;
    // Spyro
    std::cout << CrashBandicootStack.top() << std::endl;

    CrashBandicootStack.pop();
    // Aku Aku
    std::cout << CrashBandicootStack.top() << std::endl;
    // 8
    std::cout << CrashBandicootStack.size() << std::endl;

    CrashBandicootStack.push("Spyro");
    CrashBandicootStack.push("Ripper Roo");

    // Ripper Roo
    std::cout << CrashBandicootStack.top() << std::endl;
    // 10
    std::cout << CrashBandicootStack.size() << std::endl;

    std::stack<std::string> CrashBandicootStackClone;

    CrashBandicootStackClone.push("Crash Bandicoot Clone");
    CrashBandicootStackClone.push("Neo Cortex Clone");
    CrashBandicootStackClone.push("Coco Bandicoot Clone");
    CrashBandicootStackClone.push("Dingodile Clone");
    CrashBandicootStackClone.push("Tiny Tiger Clone");
    CrashBandicootStackClone.push("Crunch Bandicoot Clone");
    CrashBandicootStackClone.push("Aku Aku Clone");
    CrashBandicootStackClone.push("Spyro Clone");
    CrashBandicootStackClone.push("Ripper Roo Clone");

    // Ripper Roo Clone
    std::cout << CrashBandicootStackClone.top() << std::endl;
    // 9
    std::cout << CrashBandicootStackClone.size() << std::endl;

    CrashBandicootStack.swap(CrashBandicootStackClone);
    // Ripper Roo Clone
    std::cout << CrashBandicootStack.top() << std::endl;
    // Ripper Roo
    std::cout << CrashBandicootStackClone.top() << std::endl;

    std::vector<std::string> CoolGirlVector = {"Sasha Calle", "Victoria Justice", "Sky Ferreira", "Jessica Henwick"};

    // std::print("{}\n", CoolGirlVector);

    std::cout << __cplusplus << std::endl;

    int test_num_1 = 3744;

    std::string test_num_str_1 = std::to_string(test_num_1);

    std::string num_string = "3744";

    int num_parsed_1 = std::stoi(num_string);

    // NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE (string)
    std::cout << typeid(test_num_str_1).name() << std::endl;
    // i (integer)
    std::cout << typeid(num_parsed_1).name() << std::endl;
    // i (integer)
    std::cout << typeid(3744).name() << std::endl;
    // A18_c (17 characters in string)
    std::cout << typeid("Jennifer Morrison").name() << std::endl;
    // A15_c (14 characters in string)
    std::cout << typeid("Perri Nemiroff").name() << std::endl;
    // A6_c (5 characters in string)
    std::cout << typeid("56890").name() << std::endl;

    ListNode L1_A;
    ListNode L1_B;
    ListNode L1_C;
    ListNode L1_D;

    L1_A.val = 3;
    L1_A.next = &L1_B;

    L1_B.val = 7;
    L1_B.next = &L1_C;

    L1_C.val = 4;
    L1_C.next = &L1_D;

    L1_D.val = 9;

    std::cout << L1_D.next << std::endl;

    std::string concat_string_1 = "";

    ListNode current = L1_A;

    while (current.next != nullptr)
    {
        concat_string_1 = concat_string_1.append(std::to_string(current.val));
        current = *current.next;
        if (current.next == nullptr)
        {
            concat_string_1 = concat_string_1.append(std::to_string(current.val));
        }
    }

    // 3749
    std::cout << concat_string_1 << std::endl;
    // 4
    std::cout << concat_string_1.size() << std::endl;
    // 9
    std::cout << concat_string_1.at(3) << std::endl;

    std::string test_1 = std::to_string(concat_string_1.at(3));

    std::cout << test_1 << std::endl;

    std::string reverse_concat_string = "";

    int j37 = concat_string_1.size() - 1;
    for (; j37 >= 0; j37--)
    {
        reverse_concat_string.push_back(concat_string_1.at(j37));
    }
    // 9473
    std::cout << reverse_concat_string << std::endl;
    // 3749
    std::cout << concat_string_1 << std::endl;

    ListNode R_1;
    ListNode R_2;
    ListNode R_3;
    ListNode R_4;

    R_1.val = 2;
    R_1.next = &R_2;

    R_2.val = 7;
    R_2.next = &R_3;

    R_3.val = 6;
    R_3.next = &R_4;

    R_4.val = 5;

    ListNode current_2 = R_1;
    std::string concat_string_2 = "";

    while (current_2.next != nullptr)
    {
        concat_string_2 = concat_string_2.append(std::to_string(current_2.val));
        current_2 = *current_2.next;
        if (current_2.next == nullptr)
        {
            concat_string_2 = concat_string_2.append(std::to_string(current_2.val));
        }
    }

    std::cout << concat_string_2 << std::endl;

    int total_sum = std::stoi(concat_string_1) + std::stoi(concat_string_2);
    // 6514
    std::cout << total_sum << std::endl;

    std::string sum_string = std::to_string(total_sum);
    // 6514
    std::cout << sum_string << std::endl;

    std::string reverse_sum_string = "";

    int t_1 = sum_string.size() - 1;
    for (; t_1 >= 0; t_1--)
    {
        reverse_sum_string.push_back(sum_string.at(t_1));
    }

    // 4156
    std::cout << reverse_sum_string << std::endl;

    ListNode *tail = nullptr;
    ListNode *head = nullptr;

    int t_2 = 0;
    for (; t_2 < reverse_sum_string.size(); t_2++)
    {
        int node_val = reverse_sum_string[t_2] - '0';
        ListNode *new_node = new ListNode(node_val);

        if (t_2 == 0)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = tail->next;
        }
    }

    // 4
    std::cout << head->val << std::endl;
    // 1
    std::cout << head->next->val << std::endl;

    std::cout << "----------------------------------------------" << std::endl;

    ListNode G_1(7);
    ListNode G_2(9);
    ListNode G_3(4);
    ListNode G_4(2);
    ListNode G_5(3);

    G_1.next = &G_2;
    G_2.next = &G_3;
    G_3.next = &G_4;

    ListNode *screw_head = &G_1;

    G_4.next = &G_1;

    G_4.next = &G_5;

    std::cout << screw_head->val << std::endl;

    return 37;
}