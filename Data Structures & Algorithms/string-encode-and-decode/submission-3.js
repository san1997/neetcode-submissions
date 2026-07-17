class Solution {
    /**
     * @param {string[]} strs
     * @returns {string}
     */
    encode(strs) {
        let lengthstr = "";
        let textstr = "";

        for (const str of strs) {
            lengthstr += str.length + '+';
            textstr += str;
        }

        const finalstr = lengthstr + '|' + textstr;
        console.log(finalstr);
        return finalstr;


    }

    /**
     * @param {string} str
     * @returns {string[]}
     */
    decode(str) {
        if (str == "|") return [];
        let ind = 0;
        while (str[ind] != '|') {
            ind++;
        }

        let sizes = str.substring(0, ind-1);
        let text = str.substring(ind+1);

        sizes = sizes.split('+').map(e => parseInt(e));

        console.log(sizes);

        const ans = [];
        let i = 0;
        console.log(text);
        for (const size of sizes) {
            const newstr = text.substring(i, i+size);
            console.log(i, i+size, newstr);
            i = i + size;
            ans.push(newstr);
        }

        return ans;

    }
}
