#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;

    Node(int value) {
        val = value;
    }
};

class Queue {

    private: 
        Node *front;
        Node *rear;

    public:
        Queue() {
            front = nullptr;
            rear = nullptr;
        }

        void enqueue(int val) {
            Node *newNode = new Node(val);
            if(rear == nullptr) {
                rear = newNode;
                front = newNode;
                return;
            }
            rear->next = newNode;
            rear = newNode;
        }

        void dequeue() {
            if(front == nullptr) return;
            Node *temp = front;
            front = front->next;
            delete temp;
        }

        bool isEmpty() {
            return (front == nullptr);
        }

        int peek() {
            if(front == nullptr) {
                return -1;
            }
            return front->val;
        }

};

int main () {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);


    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.isEmpty();
    cout<<q.peek();
    return 0;
}
