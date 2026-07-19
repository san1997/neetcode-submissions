class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isAlphaNumeric = str => /^[a-z0-9A-Z]+$/i.test(str);

    isPalindrome(s) {
        let news = "";

        for (let c of s) {
            if (this.isAlphaNumeric(c)) {
                news += c;
            }
        }

        news = news.toLowerCase();
        console.log(news);

        for (let i=0 ; i<news.length / 2; i++) {
            const l = news.length - i -1;

            if (news[i] !== news[l]) return false;
        }

        return true;
    }
}
