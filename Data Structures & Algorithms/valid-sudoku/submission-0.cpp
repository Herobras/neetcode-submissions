class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, vector<bool>> um;
        int index;
        int aux_ind;
        int num;
        for (int i = 1 ; i<=9 ; i++){
            for (int j = 1 ; j<=9; j++){
                if (board[i-1][j-1] == '.'){
                    continue;
                }
                else{
                    num = board[i-1][j-1] - '0';
                    index = 10*i+j;
                    auto it = um.find(index);
                    if ( it == um.end()){
                        um[index] = vector<bool>(10,false);
                        um[index][num] = true;
                    }
                    else if (it->second[num]==true){
                        return false;
                    }
                    else {
                        it->second[num]=true;
                    }
                    // Recorro la fila sub i
                    for (int col = 1; col<=9; ++col){
                        aux_ind = 10*i+col;
                        if (aux_ind == index){
                            continue;
                        }
                        it = um.find(aux_ind);
                        if ( it == um.end()){
                            continue;
                        }
                        else if (it->second[num]==true){
                            return false;
                        }
                    }

                    // Recorro la columna J
                    for (int row = 1; row <= 9; ++row){
                        aux_ind = 10*row+j;
                        if (aux_ind == index){
                            continue;
                        }
                        it = um.find(aux_ind);
                        if ( it == um.end()){
                            continue;
                        }
                        else if (it->second[num]==true){
                            return false;
                        }
                    }

                    // Recorro el sub sudoku
                    int res_i = (i-1)/3;
                    int res_j = (j-1)/3;
                    for (int row = res_i*3+1; row<=res_i*3+3;++row){
                        for (int col = res_j*3+1; col<=res_j*3+3;++col){
                            aux_ind = 10*row+col;
                            if (aux_ind == index){
                                continue;
                            }
                            it = um.find(aux_ind);
                            if ( it == um.end()){
                                continue;
                            }
                            else if (it->second[num]==true){
                                return false;
                            }
                        }
                    }
                }

            }
        }
        return true;
    }
};
