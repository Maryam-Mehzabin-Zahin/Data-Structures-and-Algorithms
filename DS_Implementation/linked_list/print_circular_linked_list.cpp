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

void printList(Node *node) {
    if (node == NULL){
        cout << "List is Empty";
        return;
    }
    Node* head = node->next;
    Node* temp = head;
    while(true) {
        cout<<head->val<<" ";
        head = head->next;
        if(head == temp) {
            break;
        }

    }
}

int main() {
    Node* first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);

    Node* last = first->next->next;
    last->next = first;

    cout << "Original list: ";
    printList(last);

    return 0;
}