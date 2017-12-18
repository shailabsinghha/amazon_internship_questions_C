#include<math.h>
int solution(int A[], int N){

	int min = 1e6, i, j, temp, v1, v2;

	for(i =0;i<N-1;i++) for(j =i+1;j<N;j++) {
		temp = abs(A[i]-A[j]);
		if (temp<min) min = temp, v1= A[i], v2 = A[j];
	}
	
//	printf("%d %d\n", v1, v2); Numbers in consideration
	return min;
}


int main(int argc, char const *argv[])
{
	/* code */
	int A[] ={8, 24, 3, 20, 1, 17}, N=6;
	printf("%d\n", solution(A, N));

	return 0;
}

// Complexity O(n)