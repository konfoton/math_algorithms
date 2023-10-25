#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<time.h>
#define alive '0'
#define dead '.'
#define size_x 50
#define size_y 60
// GAME OF LIFE
char board[size_y][size_x];
char board_help[size_y][size_x];
void init(char board[size_y][size_x]) {
    for(int x = 0; x < size_x; x++) {
        for(int y = 0; y < size_y; y ++) {
            board[y][x] = '.';
 }    
}
}
void random_alive(char board[size_y][size_x], int random) {
    srand(time(NULL));
    for(int x = 0; x < random; x++) {
        int y = (rand() % (size_y - 1 - 0  + 1)) - 0;
        int x = (rand() % (size_x - 1 - 0  + 1)) - 0;
        board[y][x] = alive;
    }
}
int* checking(char board[size_y][size_x], int cords[]) {
    int al = 0;
    int de = 0;
    int* arr = (int*)malloc(2 * sizeof(int));
    if (board[cords[0] + 1 ][cords[1] + 1] == alive) {
        al +=1;
    } else {
        de += 1;
    }
    if (board[cords[0] - 1 ][cords[1] - 1] == alive) {
    al +=1;
    }else {
        de += 1;
    }
    if (board[cords[0]][cords[1] + 1] == alive) {
        al +=1;
    }else {
        de += 1;
    }
    if (board[cords[0] + 1 ][cords[1]] == alive) {
        al +=1;
    }else {
        de += 1;
    }
    if (board[cords[0] + 1 ][cords[1] - 1] == alive) {
        al +=1;
    }else {
        de += 1;
    }
    if (board[cords[0] - 1 ][cords[1] + 1] == alive) {
        al +=1;
    }else {
        de += 1;
    }
    if (board[cords[0]][cords[1] - 1] == alive) {
        al +=1;
} else {
        de += 1;
    }
    if (board[cords[0] - 1 ][cords[1]] == alive) {
        al +=1;
    }else {
        de += 1;
    }
    arr[0] = al;
    arr[1] = de;
return arr;
}
void print(char board[size_y][size_x]) {
    for(int y = 0; y < size_y; y++) {
        for(int x = 0; x < size_x; x++) {
            printf("%c  ", board[y][x]);
        }
    printf("\n");
    }
}
void load_value(char board[size_y][size_x], char board_help[size_y][size_x]) {
    for(int y = 0; y < size_y; y++) {
        for(int x = 0; x < size_x; x++) {
            board_help[y][x] = board[y][x];
        }
    }
}
int main(void) {
    init(board);
    random_alive(board, 500);
    load_value(board, board_help);
    while(true) {
        for(int y = 1; y < size_y - 1; y ++) {
            for(int x = 1; x < size_x - 1; x ++) {
                int cords[] = {y, x};
                int* stats = checking(board, cords);
                if(board[y][x] == alive) {
                    if(stats[0] < 2 || stats[0] > 3) {
                        board_help[y][x] = '.';
                    }
                }
                if(board[y][x] == '.') {
                    if(stats[0] == 3) {
                        board_help[y][x] = alive;
                    }
                }
        }
        }
    load_value(board_help, board);
    print(board);
    sleep(1);
    printf("\n\n\n\n\n\n\n\n");

    }
    
    return 0;
}