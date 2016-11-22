/*
by chinmay rakshit
date 12/2/2016
implementation of coin change 
input
6
3 1 1 2 2 1
output u will understand..
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
int main()
{
	int a[500]={0},n,c=0,k=0;
	bool dp[500][500]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		k+=a[i];
	}
	if(k&1)
	{
		printf("NO\n");
		return 0;
	}
	k=k/2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j-a[i-1]==0 || dp[i-1][j-a[i-1]]==1)
				dp[i][j]+=1;
			/*
			dekho yaha approach hai ki agar ekk bar n/2 touch 
			kar gaya tab fir you have got true than you know 
			that atleast there are some set of number which are
			equal to n/2 and if thats is true then the rest half itself 
			becomes true.
			*/
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}
	if(dp[n][k]==1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}