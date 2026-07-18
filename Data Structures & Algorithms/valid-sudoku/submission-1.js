class Solution {
    /**
     * @param {character[][]} board
     * @return {boolean}
     */
    isValidSudoku(board) {
        // valid rows
        // valid cols
        //valid 3x3

        for (let i=0; i<9; i++) {
            if (!this.isValidRow(board, i)) {
                console.log('no valid row', i);
                return false;
            }
        }

        for (let i=0 ;i<9; i++) {
            if (!this.isValidCol(board, i)) {
                console.log('not valid col', i);
                return false;
            }
        }

        for (let i=0;i<3;i++) {
            for (let j=0; j<3; j++) {
                if (!this.isValidMiniSquare(board, 3*i, 3*j)) {
                    console.log('not valid mini sq', 3*i , 3*j);
                    return false;
                }
            }
        }

        return true;
    }

    isValidRow(board, row) {
        const map = new Map();
        for (let i=0;i < 9; i++) {
            if (board[row][i] == '.') continue;

            if (map.has(board[row][i])) {
                return false;
            } else {
                map.set(board[row][i], true);
            }
        }

        return true;
    }

    isValidCol(board, col) {
        const map = new Map();
        for (let i=0;i < 9; i++) {
            if (board[i][col] == '.') continue; 
            if (map.has(board[i][col])) {
                return false;
            } else {
                map.set(board[i][col], true);
            }
        }

        return true;
    }

    isValidMiniSquare(board, x, y) {
        const map = new Map();
        for (let i=x; i<x+3; i++) {
            for (let j=y; j<y+3; j++) {
                if (board[i][j] == '.') continue; 
                
                if (map.has(board[i][j])) {
                    return false;
                } else {
                    map.set(board[i][j], true);
                }
            }
        }

        return true;
    }
}
