#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include <ctype.h>
int main(){

	int x[] ={2,3,5,7},n=1,i,count=0;
FILE *f ;

	printf("enter a num  " );
	scanf("%d",n);
for(i=0;i<4;i++)
{
	if((n/x[i])==1) count++;
}
if(count>1)
	printf("the number is not prime");
else
	printf("the number is prime");


    return 0;
}



