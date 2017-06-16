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
	int n;
	scanf("%d",&n);
	vpp v(n+1);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&v[i].first,&v[i].second);
	int dp[500]={0};
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;
		for(int j=1;j<i;j++)
		{
			if(v[i].first>v[j].second)
			{
				dp[i]=max(dp[j]+1,dp[i]);
			}
		}
	}
	int c=0;
	for(int i=1;i<=n;i++)
	{
		c=max(c,dp[i]);
		printf("%d ",dp[i] );
	}
	printf("\n");
	printf("the longest size is %d\n",c );
	return 0;
}