class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        bool pacific[101][101] = {false};
        bool atlantic[101][101] = {false};

        int m = heights.size();
        int n = heights[0].size();

        queue<pair<int, int>> q;
        for (int i=0; i<m; i++) {
            q.push({i, 0});
            pacific[i][0] = true;
        }

        for (int i=1; i<n; i++) {
            q.push({0, i});
            pacific[0][i] = true;
        }

        while(q.size()) {
            queue<pair<int, int>> tmp;

            while (q.size()) {
                auto front = q.front();
                q.pop();

                int x = front.first;
                int y = front.second;


                if (x-1 >= 0 && !pacific[x-1][y] &&heights[x-1][y] >= heights[x][y]) {
                    pacific[x-1][y] = true;
                    tmp.push({x-1, y});
                }

                if (x+1 < m && !pacific[x+1][y] &&heights[x+1][y] >= heights[x][y]) {
                    pacific[x+1][y] = true;
                    tmp.push({x+1, y});
                }

                if (y-1 >= 0 && !pacific[x][y-1] &&heights[x][y-1] >= heights[x][y]) {
                    pacific[x][y-1] = true;
                    tmp.push({x, y-1});
                }

                if (y+1 < n && !pacific[x][y+1] &&heights[x][y+1] >= heights[x][y]) {
                    pacific[x][y+1] = true;
                    tmp.push({x, y+1});
                }
            }

            q = tmp;
        }


        // atlantic
        for (int i=0; i<m; i++) {
            q.push({i, n-1});
            atlantic[i][n-1] = true;
        }

        for (int i=0; i<n-1; i++) {
            q.push({m-1, i});
            atlantic[m-1][i] = true;
        }

        while(q.size()) {
            queue<pair<int, int>> tmp;

            while (q.size()) {
                auto front = q.front();
                q.pop();

                int x = front.first;
                int y = front.second;

                if (x-1 >= 0 && !atlantic[x-1][y] &&heights[x-1][y] >= heights[x][y]) {
                    atlantic[x-1][y] = true;
                    tmp.push({x-1, y});
                }

                if (x+1 < m && !atlantic[x+1][y] &&heights[x+1][y] >= heights[x][y]) {
                    atlantic[x+1][y] = true;
                    tmp.push({x+1, y});
                }

                if (y-1 >= 0 && !atlantic[x][y-1] &&heights[x][y-1] >= heights[x][y]) {
                    atlantic[x][y-1] = true;
                    tmp.push({x, y-1});
                }

                if (y+1 < n && !atlantic[x][y+1] &&heights[x][y+1] >= heights[x][y]) {
                    atlantic[x][y+1] = true;
                    tmp.push({x, y+1});
                }
            }

            q = tmp;
        }



        vector<vector<int>> ans;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (atlantic[i][j] && pacific[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;

    }
};
