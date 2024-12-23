#include<iostream>
using namespace std;

void createSet(vector<int> &parent, vector<int> &rank) {
    for(int i = 0; i < parent.size(); i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x, vector<int> &parent) {
    if(parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

bool checkCycle(int first, int second, vector<int> &parent, vector<int> &rank) {
    int rootFirst = find(first, parent);
    int rootSecond = find(second, parent);
    if(rootFirst == rootSecond) {
        return true;
    }
    if(rank[first] == rank[second]) {
        parent[second] = first;
        rank[first]++;
    }
    //other 2 cases will be added with a different graph. this scenario only uses this
    return false;

}

bool isCycle(vector<pair<int, int>> &edges, vector<int> &parent, vector<int> &rank) {
    for(auto edge: edges) {
        if(checkCycle(edge.first, edge.second, parent, rank)) {
            return true;
        }
    }
    return false;
}


int main() {
    int n = 3; 
    vector<int> parent(n);
    vector<int> rank(n);
    createSet(parent, rank);
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {0, 2}};

    if (isCycle(edges, parent, rank)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}