#include <iostream>
using namespace std;

class Queue {

    private:
        int front;
        int rear;
        int arr[100];

    public: 
        Queue() {
            front = -1;
            rear = -1;
        }

        bool isEmpty() {
            return (rear == -1);
        }

        int size() {
            return (rear + 1);
        }

        void enqueue(int val) {
            if(front == -1) {
                front++;
            }
            arr[++rear] = val;
        }

        int dequeue() {
            if(isEmpty()) return -1;
            int val = arr[0];
            for(int i = 1; i <= rear; i++) {
                arr[i - 1] = arr[i];
            }
            rear--;
            return val;
        }

        int peek() {
            if(isEmpty()) return -1;
            return arr[front];
        }

};

int main () {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);

    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<q.dequeue();

    cout<<q.isEmpty();
    cout<<"size = " <<q.size()<<endl;
    cout<<q.peek();
    return 0;
}
