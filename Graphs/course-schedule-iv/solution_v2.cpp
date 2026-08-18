class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }

        vector<set<int>> reach(numCourses);

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();

            for (int neighbor : adj[node]) {
                reach[neighbor].insert(node);
                reach[neighbor].insert(reach[node].begin(), reach[node].end());

                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        vector<bool> ans;
        for (auto& query : queries) {
            ans.push_back(reach[query[1]].count(query[0]) > 0);
        }
        return ans;
    }
};