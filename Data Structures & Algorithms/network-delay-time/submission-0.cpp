class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        vector<bool> vis(n+1, false);

        for (int i=0; i<times.size(); i++) {
            int a = times[i][0];
            int b = times[i][1];
            int t = times[i][2];

            adj[a].push_back({b, t});
        }

        priority_queue<pair<int, int> > q;
        vector<int> timetaken(n+1, -1);
        q.push({0, k});

        while (q.size()) {
            auto top = q.top();
            q.pop();

            int t = -1* top.first;
            int u = top.second;

            cout << u << " " << t << endl; 

            if (vis[u]) {
                continue;
            }

            vis[u] = true;
            timetaken[u] = t;

            for (int i=0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int d = adj[u][i].second;

                if (!vis[v]) {
                    q.push({-1 * (t + d), v});
                }
            }

        }

        int minm = 0;
        for (int i=1; i<=n; i++) {
            if (timetaken[i] == -1) {
                return -1;
            }
            minm = max(minm, timetaken[i]);
        }

        return minm;
    }
};
