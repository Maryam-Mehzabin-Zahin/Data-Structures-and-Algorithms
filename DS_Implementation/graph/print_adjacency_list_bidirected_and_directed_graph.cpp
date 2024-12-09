#include<iostream>

using namespace std;

void addEdge(vector<int> adj[],int node1, int node2, int isDirected) {
    adj[node1].push_back(node2);
    if(!isDirected){
        adj[node2].push_back(node1);
    }
}

void printGraph(vector<int> adj[], int V) {
    for(int i = 0; i < V; i++) {
            cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " -> ";
        }
        cout << "NULL"<<endl;
    }
}
void initGraph(int V, int edges[3][2], int noOfEdges, int isDirected) {

    vector<int> adj[V];

    for (int i = 0; i < noOfEdges; i++)
    {
        int node1 = edges[i][0];
        int node2 = edges[i][1];
        addEdge(adj, node1, node2, isDirected);
    }

    printGraph(adj, V);
    

}

int main() {
    int ans;
    cout << "directed or undirected? Press 1 for directed, 0 for undirected: " << endl;
    cin >> ans;

    if (ans != 1 && ans != 0) {
        cout << "Invalid input! Defaulting to directed graph (1)." << endl;
        ans = 1;
    }

    int V = 3;
    int edges[3][2] = {{0, 1}, {1, 2}, {2, 0}};
    int noOfEdges = 3;
    initGraph(V, edges, noOfEdges, ans);

    return 0;
}