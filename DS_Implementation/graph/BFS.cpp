#include<iostream>
using namespace std;


vector<int> bfs(vector< vector <int> > &adj, int s) {
    vector<int> res;
    vector<bool> visited(adj.size(), false);
    queue<int> Queue;
    visited[s] = true;
    Queue.push(s);

    while(!Queue.empty()) {
        int v = Queue.front();
        Queue.pop();
        res.push_back(v);

        for(int i = 0; i < adj[v].size(); i++) {
            if(!visited[adj[v][i]]) {
                visited[adj[v][i]] = true;
                Queue.push(adj[v][i]);
            }
        }
        
    }

    return res;
}


void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 5;

    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    cout << "BFS starting from 0 : \n";
   vector<int> res = bfs(adj, 0);
   for(int i = 0; i < res.size(); i++) {
    cout<<' '<<res[i]<<' ';
   }
   return 0;
}

