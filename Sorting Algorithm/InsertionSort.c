#include<stdio.h>
int main(){
    int arr[10]={93,23,56,79,53,21,24,76,43,89};
    int key,j;
    for(int i=1;i<10;i++){
        key = arr[i];
        j = (i-1);
        while(key<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for(int i=0;i<10;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}

