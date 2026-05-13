class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> adj;

        for (int i=0; i<tickets.size(); i++) {
            if (adj.find(tickets[i][0]) == adj.end()) {
                adj[tickets[i][0]] = {};
            }

            if (adj.find(tickets[i][1]) == adj.end()) {
                adj[tickets[i][1]] = {};
            }

            adj[tickets[i][0]].push_back( tickets[i][1] );
        }

        for(auto it = adj.begin(); it != adj.end(); it++) {
            sort(it->second.begin(), it->second.end());

            cout << it->first<< endl;
            for (int i=0; i<it->second.size(); i++) {
                cout << it->second[i] << " ";
            }
            cout << endl;
        }

        vector<string> ans;

        string curr = "JFK";

        dfs(curr, adj, ans);

        reverse(ans.begin(), ans.end());

        return ans;
    }

    void dfs(string cur, map<string, vector<string>>& adj, vector<string>& ans) {

        while (adj[cur].size() > 0) {
            string next = adj[cur][0];
            adj[cur].erase(adj[cur].begin());
            dfs(next, adj, ans);
        }
        ans.push_back(cur);
    }
};
