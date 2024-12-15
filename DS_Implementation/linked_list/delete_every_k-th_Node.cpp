#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = nullptr;
    }
};

void printList(Node* head) {
  
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
}

Node* deleteK(Node* head, int k) {
    if (head == nullptr || k <= 0) {
        return head;
    }

    Node* curr = head;
    Node* prev = nullptr;
    int count = 0;

    while(curr != nullptr) {
        count++;
        if(count % k == 0){
            if(prev == nullptr) {
                head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
        }
        else{
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

int main() {
  

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    int k = 3;
    head = deleteK(head, k);
    printList(head);

    return 0;
}