#include <bits/stdc++.h>
using namespace std;
#ifndef M
#define M 1000000007
#endif
typedef pair<int,int>pp;
/*
minimum cost path
by chinmay rakshit
date 6/2/2016
input
3 3
1 2 3
4 8 2
1 5 3
output
8
*/

typedef std::vector<pp> vpp;
typedef long long ll;
#ifndef pb
#define pb push_back 
#endif 
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}
int main()
{
	int n,m,a[100][100]={0},b[100][100]={0};
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			b[i][j]=1e9;
		}
	b[1][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i-1>=1)
				b[i][j]=min(b[i][j],b[i-1][j]);
			if(j-1>=1)
				b[i][j]=min(b[i][j],b[i][j-1]);
			if(i-1>=1 && j-1>=1)
				b[i][j]=min(b[i][j],b[i-1][j-1]);
			b[i][j]+=a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",b[i][j] );
		printf("\n");
	}
	printf("%d\n",b[n][m]);
	return 0;
}