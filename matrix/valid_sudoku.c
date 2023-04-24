void initialize(int* hash, int size) {
    memset(hash, 0, size * sizeof(int));
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int hash[9];
    int i, j, k, row, col, index;

    /** check row duplicates **/
    for (i = 0; i < boardSize; i++) {
        initialize(hash, 9);
        for (j = 0; j < boardSize; j++) {
            if (board[i][j] != '.') {
                index = board[i][j] - '1';
                if (hash[index] > 0) {
                    return false;
                }
                hash[index]++;
            }
        }
    }

    /** check column duplicates **/
    for (i = 0; i < boardSize; i++) {
        initialize(hash, 9);
        for (j = 0; j < boardSize; j++) {
            if (board[j][i] != '.') {
                index = board[j][i] - '1';
                if (hash[index] > 0) {
                    return false;
                }
                hash[index]++;
            }
        }
    }

    /** check sub-boxes duplicates **/
    for (i = 0; i < boardSize; i += 3) {
        for (j = 0; j < boardSize; j += 3) {
            initialize(hash, 9);
            for (row = i; row < i + 3; row++) {
                for (col = j; col < j + 3; col++) {
                    if (board[row][col] != '.') {
                        index = board[row][col] - '1';
                        if (hash[index] > 0) {
                            return false;
                        }
                        hash[index]++;
                    }
                }
            }
        }
    }

    return true;
}
