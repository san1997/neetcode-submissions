class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        int x = target[0], y=target[1], z = target[2];
        vector<vector<int>> final;

        for (int i=0; i<triplets.size(); i++) {

            if (x == triplets[i][0]) {
                if (y >= triplets[i][1] && z >= triplets[i][2]) {
                    final.push_back(triplets[i]);
                }
            }

            if (y == triplets[i][1]) {
                if (x >= triplets[i][0] && z >= triplets[i][2]) {
                    final.push_back(triplets[i]);
                }
            }

            if (z == triplets[i][2]) {
                if (x >= triplets[i][0] && y >= triplets[i][1]) {
                    final.push_back(triplets[i]);
                }
            }
        }

        // for (int i=0; i<final.size(); i++) {
        //     cout << final[i][0] << " " << final[i][1] << " " << final[i][2] << endl;
        // }

        int a=0, b=0, c=0;

        for (int i=0; i<final.size(); i++) {
            a = max(a, final[i][0]);
            b = max(b, final[i][1]);
            c = max(c, final[i][2]);
        }

        return a == x && b == y && c == z;
    }
};
