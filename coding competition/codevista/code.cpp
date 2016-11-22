#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include "iostream"
#ifndef M
#define M 1000000007
#endif
using namespace std;
long long power(long long n)
{
	if(n==0)
		return 1;
	if(n==1)
		return 2;
	long long z=power(n/2)*power(n/2);
	z%=M;
	if(n&1)
	{
		z<<=1;
		z%=M;
	}
	return z;
}
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}
int main(int argc, char const *argv[])
{
		
	return 0;
}