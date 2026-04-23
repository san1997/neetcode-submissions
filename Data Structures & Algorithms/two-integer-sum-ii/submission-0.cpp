class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        for (int i=0; i<numbers.size(); i++) {
            for (int j=0; j< i; j++) {
                if (numbers[j] + numbers[i] == target) {
                    return {j+1, i+1};
                }
            }
        }
    }
};
