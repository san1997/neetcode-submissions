class Solution {
public:

    double myPow(double x, int n) {
        if (n < 0) {
            return 1 / helper(x, -n);
        } 
        return helper(x, n);
    }

    double helper(double x, int n) {
        if (x == 0) {
            return 0;
        }

        if (n == 0) {
            return 1;
        }

        if (n%2 == 1) {
            return x * helper(x, n/2) * helper(x, n/2);
        } else {
            return helper(x, n/2) * helper(x, n/2);
        }

    }
};
