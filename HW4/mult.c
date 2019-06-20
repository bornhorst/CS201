#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ByteMult(unsigned long* a, unsigned long* b,unsigned long* result,long n)
{
int i;
int j;
int k;

for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		result[i*n+j] = 0;
		for(k=0;k<n;k++){
			result[i*n+j] = result[i*n+j] + a[i*n+k]*b[k*n+j];
		}
	}
}

}



