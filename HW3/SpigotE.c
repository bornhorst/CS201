#include <stdio.h>

void SpigotE(unsigned char* output, unsigned long* workbuffer, unsigned long n)
{
	long i, j;
	unsigned char q;
	unsigned long temp;

	output[0] = 2;
	for (i = n + 1; i >= 0; i--)
	{
		workbuffer[i] = 1;
	}

	for (j = 1; j < n; j++)
	{
		q = 0;
		for (i = n + 1; i >= 0; i--)
		{
			temp = 10 * workbuffer[i] + q;
			q = temp / (i + 2);
			workbuffer[i] = temp % (i + 2);
		}

		output[j] = q;
	}
	
	return;
}
