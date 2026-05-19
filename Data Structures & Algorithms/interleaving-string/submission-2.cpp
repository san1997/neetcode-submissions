class Solution {
public:
    int dp[104][104] = {-1};
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        cout << dp[0][0] << endl;
        int val = dfs(0, 0, s1, s2, s3);
        return val == 1 ? true : false;
    }

    int dfs(int i, int j, string& s1, string& s2, string& s3) {
        if ( dp[i][j] &&  dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == s1.size() && j == s2.size()) {
            return dp[i][j] = getValue(true);
        }

        if (i == s1.size()) {
            return dp[i][j] = getValue(s2[j] == s3[i+j] && dfs(i, j+1, s1, s2, s3));
        }

        if (j == s2.size()) {
            return dp[i][j] = getValue(s1[i] == s3[i+j] && dfs(i+1, j, s1, s2, s3));
        }

        return dp[i][j] = getValue((s1[i] == s3[i+j] && dfs(i+1, j, s1, s2, s3)) || (s2[j] == s3[i+j] && dfs(i, j+1, s1, s2, s3)));
    }

    int getValue(bool x) {
        return x ? 1 : 0;
    }
};
