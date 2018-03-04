/*
This is a semi-complete version of the game 2048,
there are a few issues like not being able to delete
the previouse steps in the game, and the moving of
numbers in different boxes not working properly, but
other than that this is the game 2048, done in 2 hrs 
and 30 mins.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int canvas[4][4];
int valuablePos[16];
int initialVal, numOfPos = 0;
char input;
int maxV, minV, maxH, minH = 0;

void initialize(int c[4][4], int v[16]){
    for (int s=0; s<4; s++){
        for (int t=0; t<4; t++){
            canvas[s][t] = 0;
            c[s][t] = canvas[s][t];
        }
    }
    for (int x=0; x<16; x++){
        valuablePos[x] = 0;
        v[x] = valuablePos[x];
    }
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

int createRandomVal(int a[4][4]){
    bool isThere;
    int r,c;
    r = rand() % 4;
    c = rand() % 4;
    if ((c != checkForValueC(valuablePos)) && (r != checkForValueR(valuablePos)))
        isThere = true;
    canvas[r][c] = 2;
    a[r][c] = canvas[r][c];
    addValue(valuablePos, r, c);
        if (!isThere)
            createRandomVal(canvas);
}

/*int checkMaxV(){
    for (int i=0; i<4; i++){
        if (canvas[maxV][i] == 2048)
            maxV++;
    }
}*/

void moveUp(int c[4][4], int minV){
    for (int i=0; i<4; i++){
        for (int j=0; j<minV-1; j++){
            canvas[minV][i] += canvas[j][i];
            canvas[j][i] = 0;
            c[j][i] = canvas[j][i];
        }
        c[minV][i] = canvas[minV][i];
        addValue(valuablePos, i, minV);
    }   
}

void moveDown(int c[4][4], int maxV){
    for (int i=0; i; i++){
        for (int j=4; j<maxV+1; j--){
            canvas[maxV][i] += canvas[j][i];
            canvas[j][i] = 0;
            c[j][i] = canvas[j][i];
        }
        c[maxV][i] = canvas[maxV][i];
        addValue(valuablePos, i, maxV);
    }
}

void moveRight(int c[4][4], int maxH){
    for (int i=0; i<maxH-1; i++){
        for (int j=0; j<maxH-1; j++){
            canvas[i][maxH] += canvas[i][j];
            canvas[i][j] = 0;
            c[i][j] = canvas[i][j];
        }
        c[i][maxH] = canvas[i][maxH];
        addValue(valuablePos, i, maxH);
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
        addValue(valuablePos, i, minH);
    }
}

void addValue(int v[16], int iY, int iX){
    bool isThere;
    int index = 0;
    for (int i=0; i<16; i++){
        if ((iY*10)+(iX) == valuablePos[i])
            isThere = true;
        else isThere = false;
        if (valuablePos[i] == 0){
            index = i;
            index--;
        }
        v[i] = valuablePos[i];
    }
    index++;
    if (!isThere)
        valuablePos[index] = (iY*10) + iX;
}


int main()
{
    initialize(canvas, valuablePos);
    for (int i=0; i<100; i++){
        if (i == 0)
            createRandomVal(canvas);
        for (int j=0; j<4; j++){
            for (int k=0; k<4; k++){
                if (canvas[j][k] == 0)
                    printf("[ ]");
                else printf("[%d]", canvas[j][k]);
            }
            printf("\n");
        }
        scanf("%c", &input);
        switch (input){
            case 'w':
                moveUp(canvas, minV);
                break;
            case 's':
                moveDown(canvas, maxV);
                break;
            case 'a':
                moveLeft(canvas, minH);
                break;
            case 'd':
                moveRight(canvas, maxH);
        }
        if (i != 0)
            createRandomVal(canvas);
    }
    return 0;
}
