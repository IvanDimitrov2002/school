#include "stdio.h"

int sum(int n, int m){
	return n+m;
}
 int multiply(int a, int b){
	int i,k=a;
	for(i=1;i<b;i++)
	{
		a=sum(a,k);
	}
	return a;
}

int power(int a, int b){
	int i,k=a;
	for(i=1;i<b;i++)
	{
		a=multiply(a,k);
	}
	return a;
}

int power_2(int a){
	return power(a,2);
}

int is_simple(int a){
	int i;
	for(i=2;i<=a;i++){
		if(a%i==0){
			if(a==i) return 1;
			return 0;
		}
	}
	return 0;
}

int fib(int a){
  if (a==0 || a==1)
    return a;
  else
    return (fib(a-1)+fib(a-2));
}

int main() {
	int i,a=0;
	printf("\n %d", sum(1,2));
	printf("\n %d", multiply(6,8));
	printf("\n %d", power(5,3));
	printf("\n %d", power_2(2));
	printf("\n %d", is_simple(2));
	for(i=1;i<=10;i++)
	{
		printf("\n %d", fib(a));
		a++;
	}
	return 0;
}
