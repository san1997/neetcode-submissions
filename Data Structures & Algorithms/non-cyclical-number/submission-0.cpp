class Solution {
public:
    bool isHappy(int n) {
        bool vis[1004] = {false};

        int  i = 0;
        int x = n;

        while (i < n) {
            if (x == 1) {
                return true;
            }

            if (vis[x]) {
                return false;
            }

            x = newx(x);
            i++;
        }

        return false;
    }

    int newx(int n) {
        int ans = 0;

        while (n > 0) {
            int v = n%10;
            ans += (v*v);

            n /= 10;
        }

        return ans;
    }
};
