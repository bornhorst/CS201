#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ByteMult(unsigned long* a, unsigned long* b,unsigned long* result,long n)
{
int i;
int j;
int k;
int iter;
iter = (n%4 == 0) ?
	n:n-1;


for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		result[i*n+j] = 0;
		for(k=0;(k < iter) && (n > 4);k+=4){
			result[i*n+j] = result[i*n+j] + a[i*n+(k)]*b[(k)*n+j];
			result[i*n+j] = result[i*n+j] + a[i*n+(k+1)]*b[(k+1)*n+j];
			result[i*n+j] = result[i*n+j] + a[i*n+(k+2)]*b[(k+2)*n+j];
			result[i*n+j] = result[i*n+j] + a[i*n+(k+3)]*b[(k+3)*n+j];
		}	
		for(;k<n;k++)
			result[i*n+j] = result[i*n+j] + a[i*n+k]*b[k*n+j];
		}
	}


}

