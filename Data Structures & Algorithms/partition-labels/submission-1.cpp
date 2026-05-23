class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> vec;
        bool vis[26] = {false};
        int ind[26] = {-1};

        for (int i=0; i<s.size(); i++) {
            int x = s[i] - 'a';

            ind[x] = i;
        }

        for (int i=0; i<s.size(); i++) {
            int x = s[i] - 'a';
            if (!vis[x]) {
                vec.push_back({i, ind[x]});
                vis[x] = true;
            }
        }

        for (int i=0; i<vec.size()- 1;) {
            if (vec[i].second >= vec[i+1].second) {
                vec.erase(vec.begin() + i +1);
            } else if (vec[i].second >= vec[i+1].first) {
                vec[i].second = vec[i+1].second;
                vec.erase(vec.begin() + i + 1);
            } else {
                i++;
            }
        }

        vector<int> ans;

        for (int i=0; i<vec.size(); i++) {
            ans.push_back(vec[i].second - vec[i].first + 1);
        }

        return ans;

    }
};
