#include <SingleNode.h>

class SkipList
{
private:
    SingleNode *head;
    int Level;

public:
    SkipList();

    void insert(int numParam); // to insert the value
    void remove(int numParam); // to delete the value
    bool search(int numParam); // to search for a value
    void display();        // Function to display a skip list
};