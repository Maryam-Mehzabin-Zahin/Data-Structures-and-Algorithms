class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        createGraph(prerequisites, adj, indegree);
        return createOrder(adj, indegree, numCourses);
    }

private: 

    vector<int> createOrder(vector<vector<int>>& adj, vector<int>& indegree, int n) {
        queue<int> q;
        int count = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int course = q.front();
            res.push_back(course);
            q.pop();
            count++;

            for(int i = 0; i < adj[course].size(); i++) {
                indegree[adj[course][i]]--;
                if (indegree[adj[course][i]] == 0) {
                    q.push(adj[course][i]);
                }
            }
        }  
        if(count == n) return res;
        return {};
    }

    void createGraph(vector<vector<int>>& prerequisites, vector<vector<int>>& adj, vector<int>& indegree) {
        for(int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0], pre = prerequisites[i][1];
            adj[pre].push_back(course);
            indegree[course]++;
        }
    }
};