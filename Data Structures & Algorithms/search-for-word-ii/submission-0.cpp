class Solution {
public:
    bool visited[15][15] = {false};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        
        for (int i=0; i<words.size(); i++) {
            if (exist(board, words[i])) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i=0; i< n; i++) {
            for (int j=0; j<m; j++) {
                if (pathCheck(board, i, j, word)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool pathCheck(vector<vector<char>>& board, int x, int y, string s) {
        if (s.size() == 0) {
            return true;
        }

        if (s[0] != board[x][y]) {
            return false;
        }

        int n = board.size();
        int m = board[0].size();

        string news = s.substr(1, s.size() - 1);
        bool hasPath = false;
        visited[x][y] = true;

        if (news.size() == 0) {
            hasPath |= true;
        }

        if (!visited[x+1][y] && x+1 < n) {
            hasPath |= pathCheck(board, x+1, y, news); 
        }

        if (!visited[x-1][y] && x-1 >= 0) {
            hasPath |= pathCheck(board, x-1, y, news); 
        }

        if (!visited[x][y-1] && y-1 >= 0) {
            hasPath |= pathCheck(board, x, y-1, news); 
        }

        if (!visited[x][y+1] && y+1 < m) {
            hasPath |= pathCheck(board, x, y+1, news); 
        }

        visited[x][y] = false;
        return hasPath;

    }
};
