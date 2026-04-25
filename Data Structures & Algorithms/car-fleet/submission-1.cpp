class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> cars;

        for (int i=0; i<position.size(); i++) {
            float time = (float)(target - position[i]) / speed[i];

            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end());

        for (int i=0;i<cars.size(); i++) {
            cout << cars[i].first << " " << cars[i].second << endl;
        }

        int fleets = 0;
        int i = cars.size() - 1;
        while ( i >= 0) {
            cout << i << endl;
            float t = cars[i].second;
            fleets++;
            while (i-1 >= 0 && cars[i-1].second <= t) {
                i--;
            }
            i--;
        }

        return fleets;
    }
};
