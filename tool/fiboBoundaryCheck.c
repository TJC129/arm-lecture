#include <stdio.h>
typedef  int fibo_type;
fibo_type fib[168]={0};
fibo_type fibo(int n)
{
		//printf("fibo(%d)\n",n);
		fibo_type rtn=0;
		fibo_type rtn_m1=0;
		fibo_type rtn_m2=0;
		if(n<=2)
				return 1;
		else
		{
				if(fib[n-1]==0)
				{
					rtn_m1 = fibo(n-1);
					fib[n-1] = rtn_m1;
					//printf("fibo[%d]: %d\n",n-1,fib[n-1]);
				}
				else
						rtn_m1 = fib[n-1];

				if(fib[n-2]==0)
				{
					rtn_m2 = fibo(n-2);
					fib[n-2] = rtn_m2;
					//printf("fibo[%d]: %d\n",n-2,fib[n-2]);
				}
				else
						rtn_m2 = fib[n-2];

				rtn = rtn_m1+rtn_m2;
				//printf("fibo[%d]: %d, fibo[%d]: %d, sum=%d\n",n-2,fib[n-2], n-1, fib[n-1], rtn);
				if(rtn < rtn_m1 || rtn < rtn_m2)
						return -1;
				else
				{
						fib[n]=rtn;
						//printf("fibo[%d]: %d\n",n,fib[n]);
						return rtn;
				}
		}
}
int main(void)
{
		/*	test data types with its maximum of fibonacci*/
		fibo_type result = 1;
		for(int i=1;i<100;i++)
		{
				result=fibo(i);
				if(result!=-1)
						printf("fib(%d) result: %d\n",i,result);
				else
						printf("fib(%d): out of boundary.\n", i);
		}
		return 0;
}
