#include<stdio.h>
#include<stdlib.h>
int main(){
	printf("Enter size of array ");
	int size;
	scanf("%d",&size);
	int *arr =(int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int j,key;
	for(int gap=size/2;gap>0;gap=gap/2){
		for(int i=gap;i<size;i++){
			key = arr[i];
			for(j=gap-i;j>=0 && key<arr[j-i];j-=i){
				
			}
		}	
	}
}
