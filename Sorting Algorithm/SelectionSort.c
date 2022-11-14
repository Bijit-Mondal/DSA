#include<stdio.h>
int main(){
    int arr[10]={12,67,21,56,90,13,54,76,98,21};
    int min = arr[0];
    int temp;
    for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            if(min>arr[j]){
                temp = arr[j];
                arr[j] = min;
                min = temp;
            }
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d\t",arr[i]);
        }
    }
    return 0;
}

