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

int getMiddle(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr ) {
        slow = slow -> next;
        fast = fast->next->next;
    }
    
    return slow->val;
}

int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    cout << getMiddle(head);

    return 0;
}
