#include<stdio.h>
#define N 10 
int main(){
	int a[N];
	int i;
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<N;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	int j;
	i=0;j=N-1;
	while(i<j){
		while (a[i] > 0) i++;
        while (a[j] < 0) j--;
		int temp; 
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }	
	}
		for(i=0;i<N;i++){
		printf("%d ",a[i]);
	}
} 
