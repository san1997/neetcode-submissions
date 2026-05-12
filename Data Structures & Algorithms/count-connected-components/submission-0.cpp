class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for (int i=0; i<edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int ans = 0;
        for (int i=0; i<n; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis);
                ans++;
            }
        }

        return ans;
    }

    void dfs(int n, int p, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[n] = true;

        for (int i=0; i<adj[n].size(); i++) {
            int c = adj[n][i];

            if (c != p) {
                if (!vis[c]) {
                    dfs(c, n, adj, vis);
                }
            }
        }
    }
};
