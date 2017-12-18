// this is a BFS question
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct Results{

	int *A;
	int N;

};


struct Results solution(int A[], int M){


	// first make ajcency matrix 
	
	int ARR[M][M];
	int i, j;

	memset(ARR, 0, sizeof(ARR[0][0]) * M * M);
	int capital;	
	for(i=0;i<M;i++) if (A[i] != i) ARR[i][A[i]]=ARR[A[i]][i]=1;
		else capital = i;


	// now apply BFS with counting the levels 
	int q[M];
	int count;
	q[0] = capital;
	count = 0;
	int visited[M];
	memset(visited, 0, sizeof(visited));
	int top=1;
	visited[capital]=1;
	int level[M];
	level[capital]=0;

	while (count != top){

		//take out the first elemen from q
		int elem = q[count++];
		int ans =0;

		// check the neighbours of elem
		// the number of neighbours elem has is the answer
		//printf("%s: ",  "Visited elements in the ");
		for (i=0;i<M;i++){
			if (ARR[elem][i] && !visited[i]){   // neighbours of element not visited
				q[top++]=i;    // inlcude the nighbour
				visited[i]=1;  // mark visited
				ans++;		  // visited
				//printf("%d ", i);
				level[ i ] = level[ elem ] + 1;
			}
		}

	}
	// printing the elements in the levels
	// find the frequency of all the levels

	int frequency[M]; 
	memset(frequency, 0, sizeof(frequency));

	for(i=0;i<M;i++) 
		frequency[level[i]]+=1;

	struct Results r;
	r.N = M;
	r.A = malloc(sizeof(int) * (M+1));

	for(i=0;i<M;i++)
		r.A[i] = frequency[i];


	return r;
}

int main(){

	int size=11;
	int A[size];

	A[0]=9;
	A[3]=9;
	A[6]=8;
	A[9]=1;
	A[1]=1;
	A[4]=0;
	A[7]=9;
	A[2]=4;
	A[5]=4;
	A[8]=0;
	A[10] =8;
	struct Results r = solution(A, size);

	int i;
	size= r.N;

	for (int i = 1; i < size; ++i)
			printf("%d ", r.A[i]);	

}