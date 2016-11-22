#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}
int a[2500007]={0};
int main(int argc, char const *argv[])
{
	int x=sqrt(2500006);
	for(int i=2;i<=x;i++)
	{
		for(int j= i*i;j<=2500006;j+=i)
			a[j]=1;
	}
	int n,m,temp=0;
	scanf("%d %d",&n,&m);
	for(int i=2;i<=n;i++)
	{
		if(a[i]==0)
		{
			int j=0;
			long long p=i;
			while(p<=2500006 && j<=m && a[p]==0)
			{
				p=2*p+1;
				j++;
			}
			if(j==m+1){
				if(temp) printf(" ");
				printf("%d",i);
				temp=1;
			}
		}
	}
	return 0;
}