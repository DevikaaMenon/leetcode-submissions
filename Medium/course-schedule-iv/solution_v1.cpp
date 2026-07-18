class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        // Build adjacency list and in-degree array
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }

        // reach[i] = set of all nodes that i can reach (i.e. i is prerequisite of)
        vector<set<int>> reach(numCourses);

        // Kahn's BFS-based topological sort
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();

            for (int neighbor : adj[node]) {
                // node is a direct prerequisite of neighbor
                // so neighbor can reach everything node can reach, plus node itself
                reach[neighbor].insert(node);
                reach[neighbor].insert(reach[node].begin(), reach[node].end());

                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Answer queries: is u a prerequisite of v?
        vector<bool> ans;
        for (auto& query : queries) {
            ans.push_back(reach[query[1]].count(query[0]) > 0);
        }
        return ans;
    }
};