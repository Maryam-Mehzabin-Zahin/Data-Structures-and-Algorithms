#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int value) {
        val = value;
        next = nullptr;
    }
};

class MyHashSet {
private:
    Node* head;

public:
    MyHashSet() {
        head = nullptr;
    }

    void add(int key) {
        if (contains(key)) return; // Avoid duplicates
        Node* newNode = new Node(key);
        newNode->next = head;
        head = newNode;
    }

    void remove(int key) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->val == key) {
                if (prev == nullptr) {
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    bool contains(int key) {
        Node* currs = head;
        while (currs != nullptr) {
            if (currs->val == key) {
                return true;
            }
            currs = currs->next;
        }
        return false;
    }
};


int main() {
    MyHashSet obj;
    obj.add(1);
    obj.add(2);
    cout<<"hi"<<endl;
    cout<<obj.contains(1)<<endl;
    cout<<obj.contains(3)<<endl;
    obj.add(2);
    cout<<obj.contains(2)<<endl; 
    obj.remove(2);   
    cout<<obj.contains(2)<<endl;
    return 0;
}