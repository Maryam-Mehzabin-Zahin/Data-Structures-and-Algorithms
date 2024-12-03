#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int value) {
        val = value;
        next = nullptr;
    }
};

class Stack {

    private:
        Node* top;

    public:

        Stack() { 
            top = nullptr; 
        }

        bool isEmpty() {
           return top == nullptr; 
        }

        int peek() {
            if(top == nullptr) {
                cout<<"no element found";
                return -1;
            }
            return top->val;
        }

        void push(int value) {
            Node *newNode = new Node(value);
            newNode->next = top;
            top = newNode;
        }

        void pop() {
            if (isEmpty()) {
                cout << "Stack underflow" << endl;
                return;
            }
            Node *temp = top;
            top = top->next;
            delete temp;
        }
           
};

int main () {
    Stack st;
    st.push(5);
    st.pop();
    cout<<"top = "<<st.peek()<<endl;
    st.pop();
    cout<<"is stack empty? = "<<st.isEmpty()<<endl;
    st.pop(); 
    for(int i = 0; i <=100; i++) {
        st.push(i);
    }
    return 0;
}