class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(10, false));
        vector<vector<bool>> cols(9, vector<bool>(10, false));
        vector<vector<bool>> boxes(9, vector<bool>(10, false));
        int num, box, res_i, res_j;
        for (int i = 1; i<=9; ++i){
            for (int j = 1; j<= 9; ++j){
                if (board[i-1][j-1]=='.'){
                    continue;
                }
                num = board[i-1][j-1] - '0';
                res_i = (i-1)/3;
                res_j = (j-1)/3;
                box = res_i*3 + res_j+1;
                if (rows[i-1][num]==true || cols[j-1][num]==true || boxes[box-1][num]== true){
                    return false;
                }
                else {
                    rows[i-1][num]=true;
                    cols[j-1][num]=true;
                    boxes[box-1][num]= true;
                }
            }
        }
        return true;
    }
};