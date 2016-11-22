pp/*
by chinmay rakshit
on 8/2/2016
input 
5
10 20 30 40 30
output
0 6000 18000 30000 
0 0 24000 48000 
0 0 0 36000 
0 0 0 0 
input
5
40 20 30 10 30
output
0 24000 14000 26000 
0 0 6000 12000 
0 0 0 9000 
0 0 0 0 
input
3
10 20 30
output
0 6000 
0 0 
*/



#include <bits/stdc++.h>
using namespace std;
#ifndef M
#define M 1000000007
#endif
typedef pair<int,int>pp;
typedef std::vector<pp> vpp;
typedef long long ll;
#ifndef pb
#define pb push_back 
#endif 
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}
int main(int argc, char const *argv[])
{
	int n,a[500],dp[500][500]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int len=1;len<n;len++)
	{
		for(int i=1;i<=n-len;i++)
		{
			int j=len+i;
			dp[i][j]=1e9;
			for(int k=i;k<j;k++)
			{
				dp[i][j]=min(dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j],dp[i][j]);
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
			printf("%d ",dp[i][j] );
		printf("\n");
	}
	return 0;
}