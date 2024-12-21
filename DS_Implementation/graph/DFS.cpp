#include<iostream>
using namespace std;

vector<int> dfs(vector<vector<int>> &adj, int s) {
    vector<int> res;
    vector<bool> visited(adj.size(), false);
    stack<int> st;
    st.push(s);
    visited[s] = true;

    while(!st.empty()) {
        int v = st.top();
        res.push_back(v);
        st.pop();

        for(int i = 0; i < adj[v].size(); i++ ) {
            if(!visited[adj[v][i]]) {
                visited[adj[v][i]] = true;
                st.push(adj[v][i]);
            }
        }
    }
return res;
}
void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
}

int main() {
     int V = 5;
     vector<vector<int>> adj(V);

     addEdge(adj, 1, 0);
     addEdge(adj, 0, 2);
     addEdge(adj, 2, 1);
     addEdge(adj, 0, 3);
     addEdge(adj, 1, 4);

    cout << "DFS starting from 0 : \n";
    vector<int> res = dfs(adj, 0);
    for(int i = 0; i < res.size(); i++) {
        cout<<' '<<res[i]<<' ';
    }
    return 0;
}