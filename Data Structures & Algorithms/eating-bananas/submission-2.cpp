class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxval = 0;
        for (int i=0; i<piles.size(); i++) {
            maxval = max(maxval, piles[i]);
        }


        int l=1, r = maxval, mid;
        while (l <= r) {
            cout << l << " " << r << endl;
            mid = (l+r) / 2;

            if (l == r) break;

            if (canFinish(piles, mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return mid;
    }

    bool canFinish(vector<int>& piles, int speed, int h) {
        long long int time = 0;
        for (int i=0; i<piles.size(); i++) {
            time += ceil((double)piles[i] / speed);
        }
        cout << speed << " " << time << endl;
        return time <= h;
    }
};
