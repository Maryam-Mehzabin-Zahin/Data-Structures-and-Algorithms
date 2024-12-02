#include <iostream>
using namespace std;

class Stack
{
private:
    int top = -1;
    int arr[100];
public:
    
    int peek() {
        if(top == -1) {
            cout<<"no element found";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void push (int x) {
        if(top >= 99) {
            cout<<"stack overflow";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if(top == -1) {
            cout<<"stack underflow"<<endl;
            return;
        }
        top--;
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
    return 0;
}

