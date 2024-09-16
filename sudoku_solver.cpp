#include <iostream>
#include <vector>
using namespace std;
void draw(vector<vector<int>> board){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl; 
    }
}
bool check_if_valid(int i, int j, int num, vector<vector<int>> board){
    int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for(int k = 0; k < 4; k++){
        int temp_i  = i;
        int temp_j = j;
        while((temp_i  + direction[k][0] >= 0) && (temp_i + direction[k][0] <= 8) && (temp_j + direction[k][1] >= 0) && (temp_j + direction[k][1] <= 8)){
            temp_i += direction[k][0];
            temp_j += direction[k][1];
            if(board[temp_i][temp_j] == num){
                return false;
            }
        }
    }
    int temp_i = (i/3) * 3;
    int temp_j = (j/3) * 3;
    if(board[temp_i + 1][temp_j] == num){
        return false;
    }
    if(board[temp_i + 2][temp_j] == num){
        return false;
    }
    if(board[temp_i ][temp_j + 1] == num){
        return false;
    }
    if(board[temp_i][temp_j + 2] == num){
        return false;
    }
    if(board[temp_i][temp_j] == num){
        return false;
    }
    if(board[temp_i + 1][temp_j + 1] == num){
        return false;
    }
    if(board[temp_i + 1][temp_j + 2] == num){
        return false;
    }
    if(board[temp_i + 2][temp_j + 1] == num){
        return false;
    }
    if(board[temp_i + 2][temp_j + 2] == num){
        return false;
    }
    return true; 
}
void solve(vector<vector<int>>& board){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == 0){
                for(int k = 1; k <= 9; k++){
                    if (check_if_valid(i, j, k, board)){
                        board[i][j] = k;
                        solve(board);
                        board[i][j] = 0;
                    }
                }
                return; 
            }
        }
    }
    draw(board);
    int a; 
    cin >> a;
}
int main(){
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    solve(board);
    return 0; 
}
