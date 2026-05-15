class CountSquares {
public:
    vector<int> points[1003];
    int exists[1004][1004] = {0};

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        points[y].push_back(x);
        exists[y][x]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int c = 0;
        for (int i=0; i<points[y].size(); i++) {
            int x1 = points[y][i];
            int dis = abs(x1 - x);
            int c1 = 0;

            if (dis == 0) {
                continue;
            }
            cout << x1 << "," << y  << " - ";

            cout << x << "," << y+dis  << " - ";
            cout << x1 << "," << y+dis  << " - ";
            cout << endl;

            if (y + dis >=0  && exists[y + dis][x] && exists[y+ dis][x1] ) {
                c1 += exists[y + dis][x]*exists[y+ dis][x1];
            }

            if (y - dis >=0  && exists[y - dis][x] && exists[y - dis][x1] ) {
                c1 += exists[y - dis][x]*exists[y - dis][x1];
            }

            c+= c1;
        }

        return c;
    }
};
