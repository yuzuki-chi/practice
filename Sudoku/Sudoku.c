#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE    1
#define FALSE   0
#define DATA_SIZE0  3
#define DATA_SIZE   DATA_SIZE0*DATA_SIZE0

/**
 * print_board ... 解答の表示 
 */
void print_board(int board[DATA_SIZE][DATA_SIZE]){
    int x,y;

    for (y = 0; y < DATA_SIZE; ++y){
        for (x = 0; x < DATA_SIZE; ++x){
            if(board[y][x]==0) printf("- ");
            else printf("%d ",board[y][x]);
        }
        printf("\n");
    }
}

/**
 * read_problem ... 引数から解析するdatファイルを読み込む
 */
void read_problem(char *fname, int board[DATA_SIZE][DATA_SIZE]){
    int x, y;
    FILE *fp;

    if((fp=fopen(fname,"r"))==NULL){
        printf("read_problem(): Cannot open \"%s\"\n",fname);
        exit(1);
    }

    for(y=0;y<DATA_SIZE;y++){
        for(x=0;x<DATA_SIZE;x++){
            fscanf(fp,"%d ",&board[y][x]);
        }
    }
    fclose(fp);
} 

/**
 *  空白マス(0)の検出             
 */
int find_blank(int *x, int *y, int board[DATA_SIZE][DATA_SIZE]){
    int i,j;

    for(;*y<DATA_SIZE;(*y)++,*x=0){ 
        for(;*x<DATA_SIZE;(*x)++){
            if(board[*y][*x]==0) return TRUE;
        }
    }
    return  FALSE;
} 

/**
 *   問題を解く
 */
void solve(int x, int y, int board[DATA_SIZE][DATA_SIZE]){
    int i,j,x0,y0;
    int possible[DATA_SIZE+1];
  
    /* 途中経過を表示 */
    printf( "[途中経過]\n" );
    print_board(board);

    /* 空白のマスがなければ答えを表示する */
    if(!find_blank(&x,&y,board)){
        printf( "[答え]\n" );
        print_board(board);
        exit(0);
    }

    /* 全て使用可にする */
    for(i=1;i<=DATA_SIZE;i++){      
        possible[i]=TRUE;
    }

    /* 縦・横方向に boardの値を調べて、すでに使用されている数字のところは
        possible を FALSE にする */
    for(i=0;i<DATA_SIZE;i++){
        /* 横方向 */
        if(board[i][x]!=0) possible[board[i][x]] = FALSE;
        /* 縦方向 */
        if(board[y][i]!=0) possible[board[y][i]] = FALSE;
    }
  
    /* DATA_SIZE0xDATA_SIZE0の枠の中の board の値を調べて、
        すでに使用されている数字のところは possible を FALSE にする */
    y0 = y/DATA_SIZE0*DATA_SIZE0;
    x0 = x/DATA_SIZE0*DATA_SIZE0;
    for(i=0; i<DATA_SIZE0; i++){
        for(j=0; j<DATA_SIZE0; j++){
            if(board[y0+i][x0+j]!=0) possible[board[y0+i][x0+j]] = FALSE;
        }
    }

    for(i=1;i<=DATA_SIZE;i++){
        if(possible[i]==FALSE) continue;
        board[y][x]=i;
        solve(x,y,board);
        board[y][x]=0;
    }
}

/**
 * Main Program
 */
int main( int argc, char *argv[]){
    int board[DATA_SIZE][DATA_SIZE];

    if(argc!=2){
        printf("error: select dat file for Sudoku");
    }

    /* 問題の読み込み */
    // read_problem(argv[1],board);
    read_problem("problem.dat", board);

    /* 問題の表示 */
    printf("[問題]\n");
    print_board(board); 
    /* 問題を解く */
    solve(0,0,board);

    return 0;
}






