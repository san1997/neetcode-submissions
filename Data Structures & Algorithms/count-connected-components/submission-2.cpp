class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n+1, 0);

        for (int i=0; i<n; i++) {
            par[i] = i;            
        }

        int ans = n; 

        for (int i=0; i<edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            int pa = find(a, par);
            int pb = find(b, par);

            if (pa != pb) {
                ans--;
            }

            par[pa] = pb;
        }

        return ans;
    }

    int find(int n, vector<int>& par) {
        while (n != par[n]) {
            n = par[n];
        }

        return n;
    } 
};
