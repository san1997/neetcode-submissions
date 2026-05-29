class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = (matrix.size() + 1) /2;

        for (int i=0; i< (m%2 == 1 ? n-1 : n); i++) {
            for (int j=0; j<n; j++) {
                cout << i << " " << j << endl;
                int x1 = i;
                int y1 = j;

                int x2 = j;
                int y2 = m-1-i;

                int x3 = m -i -1;
                int y3 = m-1-j;

                int x4 = m-j-1;
                int y4 = i;

                int tmp = matrix[x1][y1];
                matrix[x1][y1] = matrix[x4][y4];
                matrix[x4][y4] = matrix[x3][y3];
                matrix[x3][y3] = matrix[x2][y2];
                matrix[x2][y2] = tmp;
            }
        }
    }
};
