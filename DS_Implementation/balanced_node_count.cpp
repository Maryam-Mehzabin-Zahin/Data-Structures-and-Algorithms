#include <cstddef>
#include <iostream>
using namespace std;
struct  Node
{
    Node *left;
    Node *right;
    int val;
    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};
int c = 0;
int balanced_node_count(Node *root, int &c)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL) {
        c++;
        return 1;
    }
    int left = balanced_node_count(root->left, c) ;
    int right = balanced_node_count(root->right, c) ;
    if(left == right)
        c++;
    else if(left == 0 || right == 0) {
        c++;

    }
    return left + right + 1;
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(1);
    root->right->right = new Node(1);
    int c = 0;
    balanced_node_count(root, c);
    cout<<c<<endl;
    return 0;
}
