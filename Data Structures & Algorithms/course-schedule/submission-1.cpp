class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> vec(numCourses+1);

        for (int i=0; i<prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            vec[a].push_back(b);
        }

        vector<bool> vis(numCourses + 1, false);

        for (int i=0; i<numCourses; i++) {
                if (hasCycle(i, vec, vis)) {
                    return false;
                }
        }

        return true;
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
