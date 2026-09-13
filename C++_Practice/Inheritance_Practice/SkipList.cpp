#include "SkipList.h"

// constructor
SkipList::SkipList()
{

    head = new SingleNode(0, maxNumberOfLevel);

    Level = 0;
}

void SkipList::insert(int numParam)
{
    int newLevel;

    while (newLevel < maxNumberOfLevel and (rand() % 2) == 1) 
    {
        newLevel++;
    }

    if (Level < newLevel)
    {
        head->next.resize(newLevel + 1, nullptr);

        Level = newLevel;
    }

    SingleNode *current = head; 

    std::vector<SingleNode *> Update(Level + 1, nullptr);

    for (int i = Level; i >= 0; i--)
    {

        while (current->next[i] and current->next[i]->numParam < numParam)
        {
            current = current->next[i];
        }

        Update[i] = current;
    }

    current = current->next[0]; 

    if (current == nullptr or current->numParam != numParam)
    {
        SingleNode *newNode = new SingleNode(numParam, Level);

        for (int i = 0; i <= newLevel; i++)
        {
            newNode->next[i] = Update[i]->next[i];

            Update[i]->next[i] = newNode; // To insert the value at each level
        }

        std::cout << "Element " << numParam << " inserted successfully.\n";
    }
    else
    {
        std::cout << "Element " << numParam << " already exists.\n"; // In case value already exists
    }
}
