class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses+1);
        vector<int> indegree(numCourses + 1, 0);

        for (int i=0; i<prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            indegree[b]++;
            adj[a].push_back(b);
        }

        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int finish = 0;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            finish++;
            cout << n << endl;

            for (int i=0; i<adj[n].size(); i++) {
                indegree[adj[n][i]]--;

                if (indegree[adj[n][i]] == 0) {
                    q.push(adj[n][i]);
                }
            }
        }

        return finish == numCourses;
    }

    bool hasCycle(int n, vector<vector<int>>& vec, vector<bool>& vis) {
        if (vis[n]) {
            return true;
        }

        vis[n] = true;
        bool containsCycle = false;
        for (int i=0; i<vec[n].size(); i++) {
            containsCycle |= hasCycle(vec[n][i], vec, vis);
        }

        vis[n] = false;
        return containsCycle;
    }
};
