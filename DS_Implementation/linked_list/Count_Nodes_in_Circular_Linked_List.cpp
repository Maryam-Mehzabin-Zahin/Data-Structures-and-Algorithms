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

int totalNodes(Node *head) {
    if (!head) 
        return 0;

    Node *curr = head;
    int c = 0;
    while (curr != nullptr) {
        curr = curr->next;
        c++;
        
        if (curr == head) {    
            return c;
        }
    }
    return c; 
}


int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    cout<<totalNodes(head)<<endl;
    return 0;
}