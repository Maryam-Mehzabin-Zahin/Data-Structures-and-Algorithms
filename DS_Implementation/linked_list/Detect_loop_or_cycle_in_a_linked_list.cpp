#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int value) {
        val = value;
        next = nullptr;
    }
};
bool detectLoop(Node *node) {
    unordered_set <Node*> st;
    while(node != nullptr) {

        if(st.find(node) != st.end()) {
            return true;
        }

        st.insert(node);
        node = node->next;
    }
    return false;
}

int main() {

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
/* head->next->next->next = head; */  

    if (detectLoop(head))
        cout << "true";
    else
        cout << "false";

    return 0;

}