class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 0;
        int i = digits.size() - 1;
        int n =1;

        while (i >= 0) {
            int sum = digits[i] + c + n;
            c = (sum) / 10;
            digits[i] = (sum) % 10;
            i--;
            n = 0;
        }

        if (c) {
            digits.insert(digits.begin(), c);
        }

        return digits;
    }
};
