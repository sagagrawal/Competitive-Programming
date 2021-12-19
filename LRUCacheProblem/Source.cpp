#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : public Cache
{
public:
    LRUCache(int capacity)
    {
        tail = head = NULL;
        this->cp = capacity;
    }
    void set(int k, int v) override
    {
        /*
        1. Empty Cache
        2. Non-Empty and Not Full
        3. Full
        */
        if (mp.empty())
        {
            Node* tmp = new Node(k, v);
            head = tail = tmp;
            mp.insert(std::pair<int, Node*>(k, tmp));
        }
        else
        {
            if (mp.count(k))
            {
                mp.at(k)->value = v;
                return;
            }
            if (mp.size() == cp)
            {
                mp.erase(tail->key);
                Node* newTail = (tail->prev);
                newTail->next = NULL;
                delete tail;
                tail = newTail;
            }

            Node* tmp = new Node(NULL, head, k, v);
            head->prev = tmp;
            head = tmp;
            mp.insert(std::pair<int, Node*>(k, tmp));
        }
    }

    int get(int keyToCheck) override
    {
        int result = -1;

        if (mp.count(keyToCheck))
        {
            //Hit
            result = mp.at(keyToCheck)->value;

            /*
            //reorder the linkedlist

                1. Identify/reach to the Node which is a Hit
                2. Grab the hitNode
                3. (hitNode->prev)->next = hitNode->next
                4. (hitNode->next)->prev = hitNode->prev
                5. head->prev = hitNode
                6. hitNode->next = head
                7. head = hitNode
            */

            Node* hitNode = head;
            while (hitNode->key != keyToCheck)
                hitNode = hitNode->next;

            if (hitNode != head)
            {
                if (hitNode != tail)
                    (hitNode->next)->prev = hitNode->prev;
                else
                    tail = hitNode->prev;

                (hitNode->prev)->next = hitNode->next;
                head->prev = hitNode;
                hitNode->prev = NULL;
                hitNode->next = head;
                head = hitNode;
            }
        }

        return result;
    }
};

int main() {
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
