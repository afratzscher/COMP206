#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int convertDecimalToBinary(int n);

int main(){
	char *Input = getenv("QUERY_STRING"); // gets data as string
	int start;

	sscanf(Input, "Input=%d", &start);

	printf("Content-Type:text/html\n\n");	//CGI output tag
	printf("<html>");

	printf("\nThe number '%d' in binary is: ", start);
	convertDecimalToBinary(start);
	printf("<html>");	// close tag

	return 0;
}

int convertDecimalToBinary(int n){
	int c, k;
	for (c = 31; c >=0; c--){ // repeat for 32 bits
		k = n >> c; // means shift right ie. divide n by 2 and put in k
		if (k & 1){
			printf("1"); // if remainder = 1, print 1
		}else{
			printf("0"); // else, print 0
		}
	}
}

