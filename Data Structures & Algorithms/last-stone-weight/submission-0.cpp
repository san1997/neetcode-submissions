class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;

        for (int i=0; i<stones.size(); i++) {
            heap.push(stones[i]);
        }

        while (heap.size() > 1) {
            int one = heap.top();
            heap.pop();
            int two = heap.top();
            heap.pop();

            int newstone = one - two;

            if (newstone) {
                heap.push(newstone);
            }
        }

        if (heap.size()) {
            return heap.top();
        }

        return 0;
    }
};
