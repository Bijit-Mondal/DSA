#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
	printf("Enter size of array ");
	scanf("%d",&n);
	int *arr =(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
    int j,key;
    for(int i=1;i<n;i++){
        key = arr[i];
        j = (i-1);
        while(j>=0 && key>arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}