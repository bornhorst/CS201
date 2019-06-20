#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define LONG_TRIALS 2000L
#define FAST_TRIALS 1L

#define TRIALS LONG_TRIALS

void SpigotE(unsigned char* output, unsigned long* workbuffer, unsigned long n);

void PrintE(unsigned char* output, long n)
{
	long i;

	printf("e = 2.");
	for (i = 1; i < n; i++)
	{
		putchar(output[i] + '0');
	}
	printf("\n");
}

int main(int argc, char*argv[])
{
	long i = 0;
	struct timeval tf, ti;
	unsigned long timems = 0;
	unsigned char* out;
	unsigned long* work;
	unsigned long n;
	int retval = 0;

	if (argc != 2)
	{
	  printf("Usage: hw3 num_digits\n");
	  goto cleanup;
	}
	
	n = strtol(argv[1], NULL, 10);
	if (n == 0)
	{
	  printf("Invalid range\n");
	  retval=1;
	  goto cleanup;
	}
	
	out = (unsigned char*) malloc(sizeof(unsigned char) * n);
	work = (unsigned long*) malloc(sizeof(unsigned long) * (n + 2));
	memset(out, 0, sizeof(unsigned char) * n);
	memset(work, 0, sizeof(unsigned long) * (n + 2));

	if (out == NULL || work == NULL)
	{
	  printf("Not enough memory \n");
	  retval=2;
	  goto cleanup;
	}

	gettimeofday(&ti, NULL);
	for (i = 0; i < TRIALS; i++)
	{
	  SpigotE(out, work, n);
	}
	gettimeofday(&tf, NULL);

	timems = (tf.tv_sec * 1000 + tf.tv_usec / 1000) - (ti.tv_sec * 1000 + tf.tv_usec / 1000);
	PrintE(out, n);
	printf("Iterations: %lu, TotalTime : %lu ms, IterTime : %lu us\n", i, timems, (1000 * timems) / TRIALS);
	printf("Speed: %lu digits/s\n", (timems > 0) ? 1000 * TRIALS * n / timems : 0);
cleanup:
	if (work != NULL) free(work);
	if (out != NULL) free(out);

	return retval;
}
