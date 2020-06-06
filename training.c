#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define FALSE 0
#define TRUE 1
#define LIMIT 2000;
#define beep() putchar('\a')

int main(){	
	/*
	int mydt;
	mydt = 1234;
	printf("mydt=%d\n", mydt);
	printf("mydtのアドレス=%p\n", &mydt);
	*/

	/*int i;
	for(i = 1; i <= 2000 ; i++){
		printf("%d\n", i);
	}
	printf("%s\n", "script end");
	*/

	double x, r;

	printf("   x      sin(x)      cos(x)\n");
	for(x=0.0; x<=180.0; x+=15.00){
		r= x * 3.14159 / 180.0;
		printf("%6.2f  %8.5f  %8.5f\n", x, sin(x), cos(r));
	}

	return 0;
}

