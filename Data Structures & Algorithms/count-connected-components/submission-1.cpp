class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n+1, 0);

        for (int i=0; i<n; i++) {
            par[i] = i;            
        }

        for (int i=0; i<edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            int pa = find(a, par);
            int pb = find(b, par);

            par[pa] = pb;
        }

        for(int i=0; i<n; i++) {
            par[i] = find(i, par);
        }

        set<int> dis;
        for (int i=0; i<n ;i++) {
            dis.insert(par[i]);
        }

        return dis.size();
    }

    int find(int n, vector<int>& par) {
        while (n != par[n]) {
            n = par[n];
        }

        return n;
    } 
};
