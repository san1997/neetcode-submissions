class Solution {
public:
    bool isPalindrome(string s) {
        string ns = "";

        for (int i=0; i<s.size(); i++) {
            if (isalnum(s[i])) {
                ns += tolower(s[i]);
            }
        }

        return isStringPalindrome(ns);
    }

    bool isStringPalindrome(string s) {
        int i=0; 
        int j=s.size() -1;

        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};
