#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int value) {
        val = value;
        next = nullptr;
    }
};

int countKey(Node *head, int key) {
    int c = 0;
    while(head != nullptr) {
        if(head->val == key) {
            c++;
        }
        head =  head->next;
    }
    return c;
}

int main() {

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(1);
    
    int key = 1;

    cout << countKey(head, 1);
    return 0;

}