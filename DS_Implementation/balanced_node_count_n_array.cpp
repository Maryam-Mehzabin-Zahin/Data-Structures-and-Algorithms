#include <vector>
#include <iostream>
using namespace std;

struct Node
{
    vector<Node*> children;
};

int balanced_node_count(Node *root, int &c) {
    if (root == NULL)
        return 0;
    if (root->children.size() == 0) {
        c++;
        return 1;
    }
    vector<int> subtreeSize;
    for (int i = 0; i < root->children.size(); i++) {
        subtreeSize.push_back(balanced_node_count(root->children[i], c));
    }
    bool isBalanced = true;
    for (int i = 0; i < subtreeSize.size(); i++) {
        if (subtreeSize[i] != subtreeSize[0]) {
            isBalanced = false;
            break;
        }
    }
    if (isBalanced) {
        c++;
    }
    int total = 1;
    for (int i = 0; i < subtreeSize.size(); i++) {
        total += subtreeSize[i];
    }
    return total;
}
int main()
{
    Node *root = new Node();
    root->children.push_back(new Node());
    root->children.push_back(new Node());
    root->children[0]->children.push_back(new Node());
    root->children[0]->children.push_back(new Node());
    root->children[1]->children.push_back(new Node());
    int count = 0;
    balanced_node_count(root, count);  
    cout << count << endl;
}