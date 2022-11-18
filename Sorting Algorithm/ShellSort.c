#include<stdio.h>
int main(){
    int size = 10;
    int arr[10]={23,54,11,35,76,21,25,87,20,1};
    for(int gap=size/2;gap > 0;gap/=2){
        for(int i=gap;i<size;i++){
            int key = arr[i];
            int j;
            for(j=i;j>=gap && arr[j-gap]>key; j=j-gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = key;
        }
        printf("Gap: %d - ",gap);
        for(int k=0;k<size;k++){
            printf("%d,",arr[k]);
        }
        printf("\b \n");
    }
    printf("Final Sorted List : ");
    return 0;
}

