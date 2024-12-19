#include<iostream>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node* root) {
    if(root == nullptr) {
        return -1;
    }
    return max(height(root->left), height(root->right)) + 1;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<height(root);

}