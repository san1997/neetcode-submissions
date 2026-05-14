class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, vector<int>>> q;

        for (int i=0; i<points.size(); i++) {
            for (int j=i+1; j<points.size(); j++) {
                int dis = abs(points[i][0] - points[j][0])  + abs(points[i][1] - points[j][1]); 

                q.push({-dis, {i, j} });

            }
        }

        int ans = 0;
        map<int ,map<int, bool>> vis;
        vector<int> par(n+1);

        for (int i=1; i<=n; i++) {
            par[i] = i;
        }

        // bool vis[1003][1004];
        while (q.size()) {
            auto top = q.top();
            q.pop();

            int dis = -top.first;
            int i = top.second[0];
            int j = top.second[1];

            int pa = find(i, par);
            int pb = find(j, par);
            
            if (pa != pb) {
                ans += dis;
                par[pa] = pb;
            }

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
