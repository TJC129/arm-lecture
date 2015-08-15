#include <stdio.h>
#include <time.h>

#define FILE_NAME "fib.txt"
extern int fibonacci(int x);

int main(int argc, char **argv)
{
  int number=0;
  int result=0;
	clock_t clock_begin;
	double time_result;
	FILE* fp;
	
	clock_begin = clock();
	scanf("%d",&number);
  result = fibonacci(number);   
  time_result = (double)(clock() - clock_begin) / CLOCKS_PER_SEC;
  printf("The fibonacci sequence at %d is: %d, time elapsed:%f \n", number, result, time_result);
	fp = fopen(FILE_NAME, "a");
	if(fp!=NULL){
			fprintf(fp, "%d %f\n",number,time_result); 
	}
  return 0;
}

