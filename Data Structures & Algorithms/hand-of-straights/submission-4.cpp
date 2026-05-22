class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0) {
            return false;
        }

        map<int, int> fre;

        for (int i=0; i < n; i++) {
            fre[hand[i]]++;
        }

        for (auto it=fre.begin(); it != fre.end(); it++) {
            int i = it->first;
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
