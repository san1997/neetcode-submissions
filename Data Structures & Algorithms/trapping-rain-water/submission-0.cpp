class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxl(n), maxr(n);
        int ans = 0;

        maxl[0] = height[0];
        maxr[n-1] = height[n-1];
        for (int i=1; i<n; i++ ) {
            maxl[i] = max(height[i], maxl[i-1]);
        }

        for (int i=n-2; i>=0;i--) {
            maxr[i] = max(height[i], maxr[i+1]);
        }

        for (int i=1;i<n-1;i++) {
            ans += max(0, min(maxr[i+1], maxl[i-1]) - height[i]);
        }

        return ans;
    }
};
