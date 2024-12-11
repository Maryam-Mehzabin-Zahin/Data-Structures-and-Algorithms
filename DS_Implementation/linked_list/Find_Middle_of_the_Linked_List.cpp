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

int getMidLength(Node* head) {
    int c = 0;
    Node* temp = head;
    while (temp != nullptr)
    {
        c++;
        temp = temp->next;
    }

    if(c % 2 == 0) {
        return (c / 2) + 1;
    }

    return ceil(c / 2);
    
}

int getMiddle(Node* head) {
    if(head == nullptr) {
        return -1;
    }

    int mid = getMidLength(head);

    Node * temp = head;

    for(int i = 0; i < mid - 1; i++) {
        temp = temp->next;
    }
    return temp->val;

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
