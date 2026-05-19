class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        return dfs(0, 0, s1, s2, s3);
    }

    bool dfs(int i, int j, string& s1, string& s2, string& s3) {
        if (i == s1.size() && j == s2.size()) {
            return true;
        }

        if (i == s1.size()) {
            return s2[j] == s3[i+j] && dfs(i, j+1, s1, s2, s3);
        }

        if (j == s2.size()) {
            return s1[i] == s3[i+j] && dfs(i+1, j, s1, s2, s3);
        }

        return (s1[i] == s3[i+j] && dfs(i+1, j, s1, s2, s3)) || (s2[j] == s3[i+j] && dfs(i, j+1, s1, s2, s3));
    }
};
