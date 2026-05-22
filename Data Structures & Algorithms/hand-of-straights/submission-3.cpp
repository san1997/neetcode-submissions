class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0) {
            return false;
        }

        vector<int> fre(1004, 0);

        for (int i=0; i < n; i++) {
            fre[hand[i]]++;
        }

        for (int i=0; i<= 1000; i++) {
            while (fre[i]) {

                for (int j=i; j < i+groupSize; j++) {
                    if (!fre[j]) {
                        return false;
                    }

                    fre[j]--;
                }
            }
        }

        return true;
    }
};
