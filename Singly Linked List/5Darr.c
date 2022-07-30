#include<stdio.h>
#include<stdlib.h>
int main(){
    int *****arr;
    arr = (int*****)malloc(sizeof(int*)*2);
    for(int i=0;i<2;i++){
        arr[i] = (int****)malloc(sizeof(int*)*3);
        for(int j=0;j<3;j++){
            arr[i][j] = (int***)malloc(sizeof(int*)*4);
            for(int k=0;k<4;k++){
                arr[i][j][k] = (int**)malloc(sizeof(int*)*5);
                for(int l=0;l<5;l++){
                    arr[i][j][k][l] = (int*)malloc(sizeof(int)*6);
                }
            }
        }
    }
    int e=100;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<4;k++){
                for(int l=0;l<5;l++){
                    for(int m=0;m<6;m++){
                        arr[i][j][k][l][m] = ++e;
                    }
                }
            }
        }
    }
 for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<4;k++){
                for(int l=0;l<5;l++){
                    for(int m=0;m<6;m++){
                        printf("%d\t",arr[i][j][k][l][m]);
                    }
                    printf("\n");
                }
                 printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

