class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        priority_queue<int> heap;
        map<int, int> mmap;

        for (int i=0 ;i<nums.size(); i++) {
            if (!mmap[nums[i]]) {
                heap.push(nums[i]);
            }
            mmap[nums[i]]++;
        }

        int ans = 1;
        int len = 1;
        int last = heap.top();
        heap.pop();

        while(heap.size()) {

            int top = heap.top();

            if (top == last - 1) {
                len++;
            } else {
                len = 1;
            }
            cout << top << " " << ans << endl; 
            ans = max(ans, len);
            last = top;
            heap.pop();
        }

        return ans;
    }
};
