#include<stdio.h>
int main(){
    int arr[10]={39,53,67,43,45,76,11,24,60,32};
    int temp;
    for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i=0;i<10;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}

