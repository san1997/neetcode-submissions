class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i=0; i < 9; i++) {
            map<char, int> freq; 
            for (int j=0; j<9; j++){
                if (board[i][j] != '.') {
                    freq[board[i][j]]++;

                    if (freq[board[i][j]]  > 1) {
                        return false;
                    }
                }
            }
        }

        for (int j=0; j < 9; j++) {
            map<char, int> freq; 
            for (int i=0; i<9; i++){
                if (board[i][j] != '.') {
                    freq[board[i][j]]++;

                    if (freq[board[i][j]]  > 1) {
                        return false;
                    }
                }
            }
        }

        for (int i=0; i< 9; i +=3) {
            for (int j=0; j<9; j+=3) {
                map<char, int> freq;

                for (int x=0;x<3;x++) {
                    for (int y=0; y<3; y++) {
                        if (board[i+x][j+y] != '.') {
                            freq[board[i+x][j+y]]++;

                            if (freq[board[i+x][j+y]] > 1) {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;

    }
};
