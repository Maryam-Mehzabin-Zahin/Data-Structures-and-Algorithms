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

void printList(Node* node) {
    while(node != nullptr) {
        cout<<node->val<<" ";
        node = node->next;
    }
}

Node* reverseList(Node* head) {
    Node *curr = head, *prev = nullptr, *temp = nullptr;
    while(curr != nullptr) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    } 
    return prev;

}


int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Given Linked list : ";
    printList(head);

    cout << "\nReversed Linked list : ";
    Node* prev = reverseList(head);
    printList(prev);

    return 0;

}