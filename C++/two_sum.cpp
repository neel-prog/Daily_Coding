#include <iostream>
using namespace std;

class TwoSum
{
private:
    static const int Size = 10007;

public:
    struct Node
    {
        int value;
        int index;
        Node *next;

        Node(int v, int i)
        {
            value = v;
            index = i;
            next = nullptr;
        }
    };

    int n = Size;

    int hash(int);
    Node *search(Node *[], int);
    void insert(Node *[], int, int);
};

int main()
{
    TwoSum obj;

    int nums[5];
    int target;
    int result[2];

    cout << "Enter the input array:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> nums[i];
    }

    TwoSum::Node *hashmap[obj.n] = {nullptr};

    cout << "Enter the target value:" << endl;
    cin >> target;

    bool foundPair = false;

    for (int i = 0; i < 5; i++)
    {
        int need = target - nums[i];

        TwoSum::Node *found = obj.search(hashmap, need);

        if (found != nullptr)
        {
            result[0] = found->index;
            result[1] = i;
            foundPair = true;
            break;
        }

        obj.insert(hashmap, nums[i], i);
    }

    if (foundPair)
    {
        cout << "Indices are: ";
        cout << result[0] << " " << result[1] << endl;

        cout << "Values are: ";
        cout << nums[result[0]] << " " << nums[result[1]] << endl;
    }
    else
    {
        cout << "No Two Sum pair found." << endl;
    }

    return 0;
}

int TwoSum::hash(int key)
{
    if (key < 0)
    {
        key = -key;
    }

    return key % Size;
}

TwoSum::Node *TwoSum::search(Node *Hashmap[], int value)
{
    int bucket = hash(value);

    Node *current = Hashmap[bucket];

    while (current != nullptr)
    {
        if (current->value == value)
        {
            return current;
        }

        current = current->next;
    }

    return nullptr;
}

void TwoSum::insert(Node *Hashmap[], int value, int index)
{
    int bucket = hash(value);

    Node *newnode = new Node(value, index);

    newnode->next = Hashmap[bucket];

    Hashmap[bucket] = newnode;
}