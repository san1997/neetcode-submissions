class Solution {
public:
    int reverse(int x) {
        long long int n = 0;

        while (x) {
            n = 10*n + x%10;

            if (n > INT_MAX || n < INT_MIN) {
                return 0;
            }
            x = x / 10;
        }

        return n;
    }
};
