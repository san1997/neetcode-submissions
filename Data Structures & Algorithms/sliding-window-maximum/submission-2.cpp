class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mset;

        for (int i=0; i<k; i++) {
            mset.insert(-1 * nums[i]);
        }

        vector<int> ans;
        ans.push_back( -1 * (*mset.begin()));

        for (int i=1;i+k <= nums.size(); i++) {
            auto it = mset.find(-1 * nums[i-1]); 
            if (it != mset.end()) {
                mset.erase(it);
            }
            
            mset.insert(-1 * nums[i+k-1]);
            ans.push_back( -1 * *mset.begin());
        }

        return ans;
    }

    void printset(multiset<int> mset) {
        for (auto it = mset.begin(); it != mset.end(); it++) {
            cout << *it<< " " ;
        }
        cout << endl;
    }
};
