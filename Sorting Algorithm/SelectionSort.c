#include<stdio.h>
int main(){
    int arr[10]={45,67,21,56,90,11,54,76,98,12};
    int temp,tmp_val;
    int min;
    for(int i=0;i<10;i++){
        min = arr[i];
        temp = -1;
        for(int j=i+1;j<10;j++){
            if(min>arr[j]){
                temp=j;
                min = arr[j];
            }
        }
        if(temp!=-1){
            tmp_val = arr[i];
            arr[i] = arr[temp];
            arr[temp] = tmp_val;
        }
    }
    for(int j=0;j<10;j++){
        printf("%d\t",arr[j]);
    }
    return 0;
}

