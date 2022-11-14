#include<stdio.h>
int main(){
    int arr[10]={93,23,56,79,53,21,24,76,43,89};
    int key;
    for(int i=1;i<10;i++){
        key = arr[i];
        for(int j=(i-1);j>=0;j--){
            if(key > arr[j]){
                arr[j+1] = arr[j];
            }else{
                arr[j+1] = key;
            }
        }
    }
    for(int i=0;i<10;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}

