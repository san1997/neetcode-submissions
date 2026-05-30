class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (int i=0; i<prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            indegree[a]++;
            adj[b].push_back(a);
        }

        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int n = q.front();
            q.pop();
            order.push_back(n);

            for (int i=0; i<adj[n].size(); i++) {
                indegree[adj[n][i]]--;

                if (indegree[adj[n][i]] == 0) {
                    q.push(adj[n][i]);
                }
            }
        }

        if (order.size() == numCourses) {
            return order;
        } else {
            return {};
        }
    }
};
