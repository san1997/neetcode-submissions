class Solution {
public:
    vector<string> ans;
    map<char, vector<char>> mmap;
    

    vector<string> letterCombinations(string digits) {

        mmap['2'] = {'a', 'b', 'c'};
        mmap['3'] = {'d', 'e', 'f'};
        mmap['4'] = {'g', 'h', 'i'};
        mmap['5'] = {'j', 'k', 'l'};
        mmap['6'] = {'m', 'n', 'o'};
        mmap['7'] = {'p', 'q', 'r', 's'};
        mmap['8'] = {'t', 'u', 'v'};
        mmap['9'] = {'w', 'x', 'y', 'z'};

        dfs(digits, 0, "");
        return ans;
    }

    void dfs(string digits, int ind, string s) {
        if (digits.size() == 0) {
            return ;
        }
        
        if (ind == digits.size()) {
            ans.push_back(s);
            return ;
        }

        for (int i=0; i<mmap[digits[ind]].size(); i++) {
            dfs(digits, ind+1, s + mmap[digits[ind]][i]);
        }
    }
};
