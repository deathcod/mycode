#include <stdio.h>
#include <stdlib.h>
#include "iostream"
using namespace std;
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	if(n==0)
	{
		return 0;
	}
	int square=1+2*n;
	char a[100][100];
	for(int i=0;i<square;i++)
		for(int j=0;j<square;j++)
			a[i][j]=' ';
	for(int i=0;i<square;i++)
	{
		a[0][i]='*';
		a[i][0]='*';
	}
	for(int i=square-1;i>=0;i-=2)
	{
		for(int j=0;j<=i;j++)
		{
			a[i][j]='*';
			a[j][i]='*';
		}
	}
	for(int i=0;i<square;i++)
	{
		for(int j=0;j<square;j++)
		{
			//if(j!=0 && a[i][j-1]==a[i][j] && a[i][j]==' ')
			//	continue;
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}