class Solution {
public:
    vector<vector<int>> adj;
    bool vis[101] = {false};

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) {
            return false;
        }
        
        for (int i=0; i<n ;i++) {
            adj.push_back({});
        }
        for (int i=0; i<edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i=0; i<n ;i++) {
            if (!vis[i]) {
                if (hascycle(i, -1)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool hascycle(int n, int p) {

        vis[n] = true;

        for (int i=0; i<adj[n].size(); i++) {
            int c = adj[n][i];

            if (c != p) {
                if (vis[c]) {
                    return true;
                } else {
                    hascycle(c, n);
                }
            }
        }

        return false;
    }
};
