#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int canvas[4][4];
int valuablePos[16];
int initialVal, numOfPos = 0;

for (int s=0; s<4; s++){
    for (int t=0; t<4; t++){
        canvas[s][t] = 0;
    }
}
for (int x=0; x<16; x++){
    valuablePos[x] = 0;
}

int checkForValueR(int a[16]){
    for (int i=0; i<16; i++){
        if (a[i] != 0)
            return a[i]/10;
    }
    return 0;
}

int checkForValueC(int a[16]){
    for (int i=0; i<16; i++){
        if (a[i] != 0)
            return (a[i] - (a[i]/10));
    }
    return 0;
}

int createRandomVal(int c[4][4]){
    while (3<5){
        int r = rand() % 4;
        int c = rand() % 4;
        if ((c != checkForValueC()) && (r != checkForValueR()))
            break;
    }
    canvas[r][c] = 2;
    c[r][c] = canvas[r][c];
}

int moveUp(int c[4][4], int minV){
    for (int i=0; i<4; i++){
        for (int j=0; j<minV-1; j++){
            canvas[minV][i] += canvas[j][i];
            canvas[j][i] = 0;
            c[j][i] = canvas[j][i];
        }
        c[minV][i] = canvas[minV][i];
    }   
}

int moveDown(int c[4][4], int a[16], int maxV){
    for (int i=0; i; i++){
        for (int j=4; j<maxV+1; j--){
            canvas[maxV][i] += canvas[j][i];
            canvas[j][i] = 0;
            c[j][i] = canvas[j][i];
        }
        c[maxV][i] = canvas[maxV][i];
        valuablePos[numOfPos] = (maxV*10)+i;
        a[numOfPos] = valuablePos[numOfPos];
        numOfPos++;
    }
    return numOfPos;
}

int moveRight(int c[4][4], int maxH){
    for (int i=0; i<maxH-1; i++){
        for (int j=0; j<maxH-1; j++){
            canvas[i][maxH] += canvas[i][j];
            canvas[i][j] = 0;
            c[i][j] = canvas[i][j];
        }
        c[i][maxH] = canvas[i][maxH];
    }
}

int moveLeft(int c[4][4], int minH){
    for (int i=0; i<minH+1; i++){
        for (int j=4; j>1; j--){
            canvas[i][minH] += canvas[i][j];
            canvas[i][j] = 0;
            c[i][j] = canvas[i][j];
        }
        c[i][minH] = canvas[i][minH];
    }
}



int main()
{
    printf("Hello World");

    return 0;
}
