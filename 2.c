#include<stdlib.h>
#include<stdio.h>
int solution(int M, int A[], int N){

	int *count = malloc((M+1)*sizeof(int)); 
	int i;
	for (i=0;i<=M;i++) count[i] =0; 
	int mc = 1;
	int index =0; // this should be intilized to 0 in case where frequency is 1 for all  element else it will return A[-1] if freqency of all is 1

	for (i=0;i<N;i++){ 

		if (count[A[i]]> 0){
			int tmp = count[A[i]]+1; // one change since the tmp should be incremented with 1 
			//all time whenever it occurs so that we can change mc(maximum occurence) with incremented value
			
			if (tmp > mc){
				mc = tmp; 
				index =i;
			}
			count[A[i]] = tmp; // second change (since it is already incremented)
			printf("%s %d\n", "maxocuurence", mc);
		}
		else{

			count[A[i]] = 1;
		}
	}
	return A[index];

}
int main(){

	int A[] = {1, 2};
	int N = sizeof(A)/sizeof(int);
	printf("%d\n", N);
	printf("%d\n", solution(2, A, N));
	return 0;

}