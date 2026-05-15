class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        vector<int> v1, v2;
        vector<int> ans = {0};
        for (int i=0; i<num1.size(); i++) {
            v1.push_back((num1[i] - '0'));
        }

        for (int i=0; i<num2.size(); i++) {
            v2.push_back((num2[i]) - '0');
        }

        for (int j=num2.size() -1;  j>=0 ;j--) {
            vector<int> tmp;
            int b = (num2[j] - '0');

            for (int i=0; i<num2.size() - 1 -j; i++) {
                tmp.push_back(0);
            }
            int c = 0;
            for (int i= num1.size() - 1; i>=0; i--) {
                int a = (num1[i] - '0');
                int v = (a*b + c) %10;
                tmp.push_back(v);
                c = (a*b + c) /10;
            }

            if (c) {
                tmp.push_back(c);
            }

            addvector(ans, tmp);
        }

        reverse(ans.begin(), ans.end());
        string s = "";
        for (int i=0; i<ans.size(); i++) {
            cout << ans[i];
            s += (char)(ans[i] + '0');
        }

        return s;
    }

    void addvector(vector<int>& ans, vector<int> & vec) {
        int n1 = ans.size();
        int n2 = vec.size();

        printvec(ans);
        printvec(vec);

        int i = 0;
        int c = 0;
        while (i <n1 || i < n2) {
            if (i < n1 && i < n2) {
                int v = (ans[i] + vec[i] + c)%10;
                c = (ans[i] + vec[i] + c)/10;
                ans[i] = v;
            } else if (i < n1) {
                int v = (ans[i] + c)%10;
                c = (ans[i] + c)/10;
                ans[i] = v;
            } else if (i < n2) {
                int v = ( vec[i] + c)%10;
                c = (vec[i] + c)/10;

                ans.push_back(v);
            }
            i++;
        }

        if (c) {
            ans.push_back(c);
        }
    }

    void printvec(vector<int>& vec) {
        for (int i=0; i<vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    } 
};
