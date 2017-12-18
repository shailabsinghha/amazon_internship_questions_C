#include <string.h>
int solution(char* S){

	// while S[i] is within printable characters ascii that is numeric only we have to see

	int len = strlen(S)-1; 
	int a =0;
	int v =  1;

	while(S[len]>=48 && S[len]<=57){

		a = a + v*(S[len]&15); // &15 converts into num ascii to decimal 
		v = v*10;
		if (a< 0){
			printf("%s ", "overflow"); // since a will turn to be less than 0 whenever there is overflow other wise it will be normal
			return 0;
		} 	

		len--;
	}

	if (len) return a;
	return a*-1;

}

int main(int argc, char const *argv[])
{
	printf("%d\n", solution("-789100123"));
	printf("%d\n", solution("100123"));
	printf("%d\n", solution("13333333333333300123"));
	printf("%d\n", solution("00000000000000000333300123"));
	printf("%d\n", solution("333300123"));

	return 0;
}