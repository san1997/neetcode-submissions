class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;

        int l=0; int r=heights.size()-1;

        while (l < r) {
            int area = (r-l) * min(heights[r], heights[l]);
            ans = max(ans, area);
            
            if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }

        return ans;
        

    }
};
