#include<stdio.h>
#include<stdlib.h>
int main(){
	printf("Enter size of array ");
	int n;
	scanf("%d",&n);
	int *arr =(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int j,key;
	for(int gap=n/2;gap>0;gap=gap/2){
		// for(int i=gap;i<size;i++){
		// 	key = arr[i];
		// 	for(j=i;j<=gap && key<arr[j-gap];j-=gap){
				
		// 	}
		// }
		for(int i=gap;i<n;i++){
			key = arr[i];
			j = (i-gap);
			while(j>=0 && key>arr[j]){
				arr[j+gap] = arr[j];
				j=j-gap;
			}
        	arr[j+gap] = key;
   		}	
	}
	for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
