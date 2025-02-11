class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);  
        vector<int> visited(numCourses, 0);  
        for (auto& pre : prerequisites) {
            int course = pre[0], prerequisite = pre[1];
            adj[prerequisite].push_back(course);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) { 
                if (dfs(adj, visited, i)) {
                    return false;  
                }
            }
        }
        return true;  

private:
    bool dfs(vector<vector<int>>& adj, vector<int>& visited, int node) {
        if (visited[node] == 1) return true;   
        if (visited[node] == 2) return false;  

        visited[node] = 1;  
        for (int neighbor : adj[node]) {
            if (dfs(adj, visited, neighbor)) {
                return true;  
            }
        }
        visited[node] = 2;  
        return false;
    }
};
