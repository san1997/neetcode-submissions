class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1);

        for (int i=1; i<=n; i++) {
            par[i] = i;
        }

        for (int i=0; i<n; i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            int pa = find(a, par);
            int pb = find(b, par);

            if (pa == pb) {
                return edges[i];
            }

            par[pa] = pb;
        }
    }

    int find(int n, vector<int>& par) {

        while (n != par[n]) {
            n = par[n];
        }

        return n;
    }
};
