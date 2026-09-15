#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <ctime>
#include <print>

struct OneWayNode
{
    int val;
    OneWayNode *next;
    OneWayNode() : val(0), next(nullptr) {};
    OneWayNode(int val) : val(val), next(nullptr) {};
    OneWayNode(int val, OneWayNode *next) : val(val), next(next) {};
};

struct TwoWayNode
{
    std::string name;
    TwoWayNode *next;
    TwoWayNode *prev;
    TwoWayNode() : name("No Name"), next(nullptr), prev(nullptr) {};
    TwoWayNode(std::string name) : name(name), next(nullptr), prev(nullptr) {};
    TwoWayNode(std::string name, TwoWayNode *next) : name(name), next(next), prev(nullptr) {};
    TwoWayNode(std::string name, TwoWayNode *next, TwoWayNode *prev) : name(name), next(next), prev(prev) {};
};

OneWayNode *AddTwoNumbers(OneWayNode *l1, OneWayNode *l2)
{
    OneWayNode *head = nullptr;
    OneWayNode *tail = nullptr;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int sum = carry;

        if (l1 != nullptr)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        OneWayNode *new_node = new OneWayNode(sum % 10);

        if (head == nullptr)
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
    return head;
};

int main()
{
    // Muskellunge.cpp
    std::cout << "Muskellunge.cpp" << std::endl;

    std::string sky_ferreira = "Sky Ferreira";
    // Sky Ferreira
    std::cout << sky_ferreira << std::endl;

    std::string sasha_calle = "Sasha Calle";

    std::string victoria_justice = "Victoria Justice";

    std::string jessica_henwick = "Jessica Henwick";

    std::string noomi_rapace = "Noomi Rapace";

    std::string katee_sackhoff = "Katee Sackhoff";

    std::vector<std::string> cool_girl_vector = {sasha_calle, sky_ferreira, victoria_justice, jessica_henwick, noomi_rapace, katee_sackhoff};
    // Sasha Calle
    std::cout << cool_girl_vector[0] << std::endl;
    // Sky Ferreira
    std::cout << cool_girl_vector[1] << std::endl;
    // Victoria Justice
    std::cout << cool_girl_vector[2] << std::endl;
    // Jessica Henwick
    std::cout << cool_girl_vector[3] << std::endl;
    // Noomi Rapace
    std::cout << cool_girl_vector[4] << std::endl;
    // 6
    std::cout << cool_girl_vector.size() << std::endl;

    TwoWayNode *SashaNode = new TwoWayNode(sasha_calle);
    TwoWayNode *SkyNode = new TwoWayNode(sky_ferreira);
    TwoWayNode *VictoriaNode = new TwoWayNode(victoria_justice);
    TwoWayNode *JessicaNode = new TwoWayNode(jessica_henwick);
    TwoWayNode *NoomiNode = new TwoWayNode(noomi_rapace);
    TwoWayNode *KateeNode = new TwoWayNode(katee_sackhoff);

    SashaNode->next = SkyNode;
    SashaNode->prev = KateeNode;

    SkyNode->next = VictoriaNode;
    SkyNode->prev = SashaNode;

    VictoriaNode->next = JessicaNode;
    VictoriaNode->prev = SkyNode;

    JessicaNode->next = NoomiNode;
    JessicaNode->prev = VictoriaNode;

    NoomiNode->next = KateeNode;
    NoomiNode->prev = JessicaNode;

    KateeNode->next = SashaNode;
    KateeNode->prev = NoomiNode;

    // Sasha Calle
    std::cout << SashaNode->name << std::endl;
    // Sky Ferreira
    std::cout << SashaNode->next->name << std::endl;
    // Katee Sackhoff
    std::cout << SashaNode->prev->name << std::endl;
    // Sky Ferreira
    std::cout << SkyNode->name << std::endl;
    // Victoria Justice
    std::cout << SkyNode->next->name << std::endl;
    // Sasha Calle
    std::cout << SkyNode->prev->name << std::endl;
    // Victoria Justice
    std::cout << VictoriaNode->name << std::endl;
    // Jessica Henwick
    std::cout << VictoriaNode->next->name << std::endl;
    // Sky Ferreira
    std::cout << VictoriaNode->prev->name << std::endl;
    // Jessica Henwick
    std::cout << JessicaNode->name << std::endl;
    // Noomi Rapace
    std::cout << JessicaNode->next->name << std::endl;
    // Victoria Justice
    std::cout << JessicaNode->prev->name << std::endl;
    // Noomi Rapace
    std::cout << NoomiNode->name << std::endl;
    // Katee Sackhoff
    std::cout << NoomiNode->next->name << std::endl;
    // Jessica Henwick
    std::cout << NoomiNode->prev->name << std::endl;
    // Katee Sackhoff
    std::cout << KateeNode->name << std::endl;
    // Sasha Calle
    std::cout << KateeNode->next->name << std::endl;
    // Noomi Rapace
    std::cout << KateeNode->prev->name << std::endl;

    std::string test_string_1 = "";
    test_string_1 = test_string_1.append("a");

    // a
    std::cout << test_string_1 << std::endl;

    TwoWayNode *sky_1 = new TwoWayNode("S");
    TwoWayNode *sky_2 = new TwoWayNode("k");
    TwoWayNode *sky_3 = new TwoWayNode("y");
    TwoWayNode *sky_4 = new TwoWayNode(" ");
    TwoWayNode *sky_5 = new TwoWayNode("F");
    TwoWayNode *sky_6 = new TwoWayNode("e");
    TwoWayNode *sky_7 = new TwoWayNode("r");
    TwoWayNode *sky_8 = new TwoWayNode("r");
    TwoWayNode *sky_9 = new TwoWayNode("e");
    TwoWayNode *sky_10 = new TwoWayNode("i");
    TwoWayNode *sky_11 = new TwoWayNode("r");
    TwoWayNode *sky_12 = new TwoWayNode("a");

    sky_1->next = sky_2;
    sky_2->next = sky_3;
    sky_3->next = sky_4;
    sky_4->next = sky_5;
    sky_5->next = sky_6;
    sky_6->next = sky_7;
    sky_7->next = sky_8;
    sky_8->next = sky_9;
    sky_9->next = sky_10;
    sky_10->next = sky_11;
    sky_11->next = sky_12;

    std::string sky_ferreira_string = "";
    TwoWayNode *current_sky = sky_1;

    while (current_sky->next != nullptr)
    {
        sky_ferreira_string = sky_ferreira_string.append(current_sky->name);
        current_sky = current_sky->next;

        if (current_sky->next == nullptr)
        {
            sky_ferreira_string = sky_ferreira_string.append(current_sky->name);
        }
    }

    // Sky Ferreira
    std::cout << sky_ferreira_string << std::endl;

    TwoWayNode *sky_head = nullptr;
    TwoWayNode *sky_tail = nullptr;

    int i_sky = sky_ferreira_string.size() - 1;
    for (; i_sky >= 0; i_sky--)
    {
        std::string str_data = std::string(1, sky_ferreira_string.at(i_sky));
        TwoWayNode *new_node = new TwoWayNode(str_data);

        if (sky_head == nullptr)
        {
            sky_head = new_node;
            sky_tail = new_node;
        }
        else
        {
            sky_tail->next = new_node;
            sky_tail = sky_tail->next;
        }
    }

    /*
        NOTE: using to_string() from std library will not work because the function does not
        contain an overload for char data types. Instead it returns an integer because char data type
        are essentially saved in data as a 1 byte integer. So you'll get a return like 97 instead.

        instead, instantiate a string instance with the first argument being a length of 1,
        and the second argument being the char you want to convert to a string
    */

    // a
    std::cout << sky_head->name << std::endl;
    // r
    std::cout << sky_head->next->name << std::endl;
    // i
    std::cout << sky_head->next->next->name << std::endl;
    // 9213 so we want 3129
    std::cout << 3794 + 5419 << std::endl;

    // stored in reverse order 3794
    OneWayNode *L1 = new OneWayNode(4);
    OneWayNode *L2 = new OneWayNode(9);
    OneWayNode *L3 = new OneWayNode(7);
    OneWayNode *L4 = new OneWayNode(3);

    L1->next = L2;
    L2->next = L3;
    L3->next = L4;

    // stored in reverse order 5419
    OneWayNode *R1 = new OneWayNode(9);
    OneWayNode *R2 = new OneWayNode(1);
    OneWayNode *R3 = new OneWayNode(4);
    OneWayNode *R4 = new OneWayNode(5);

    R1->next = R2;
    R2->next = R3;
    R3->next = R4;

    OneWayNode *r_node_1 = AddTwoNumbers(L1, R1);
    // 3
    std::cout << r_node_1->val << std::endl;
    // 1
    std::cout << r_node_1->next->val << std::endl;
    // 2
    std::cout << r_node_1->next->next->val << std::endl;
    // 9
    std::cout << r_node_1->next->next->next->val << std::endl;
    // 7
    std::cout << 7 % 10 << std::endl;
    // 0
    std::cout << 70 % 10 << std::endl;
    // 2
    std::cout << 72 % 10 << std::endl;
    // 0
    std::cout << 7 / 10 << std::endl;
    // 1
    std::cout << 12 / 10 << std::endl;

    std::unordered_map<int, std::string> CrashBandicootMap;
    CrashBandicootMap[0] = "Crash Bandicoot";
    CrashBandicootMap[1] = "Neo Cortex";
    CrashBandicootMap[2] = "Coco Bandicoot";
    CrashBandicootMap[3] = "Dingodile";
    CrashBandicootMap[4] = "Tiny Tiger";
    CrashBandicootMap[5] = "Ripper Roo";
    CrashBandicootMap[6] = "N. Ginn";
    CrashBandicootMap[7] = "Crunch Bandicoot";
    CrashBandicootMap[8] = "N. Trance";
    CrashBandicootMap[9] = "Spyro";

    // Crash Bandicoot
    std::cout << CrashBandicootMap.at(0) << std::endl;
    // Neo Cortex
    std::cout << CrashBandicootMap.at(1) << std::endl;
    // Coco Bandicoot
    std::cout << CrashBandicootMap.at(2) << std::endl;
    // Dingodile
    std::cout << CrashBandicootMap.at(3) << std::endl;
    // Tiny Tiger
    std::cout << CrashBandicootMap.at(4) << std::endl;

    return 37;
}