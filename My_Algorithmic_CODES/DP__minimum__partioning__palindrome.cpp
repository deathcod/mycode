/*
by chinmay rakshit
on 8/2/2016
input
ababbbabbababa
output
3

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
	int n,dp[500]={0},palin[500][500]={0};
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<=len;i++)
	{
		palin[i][i]=1;
	}
	for(int l=1;l<len;l++)
	{
		for(int i=0;i<=len-l;i++)
		{
			int j=l+i;
			if((l==1 && s[i]==s[j])||(s[i]==s[j] && palin[i+1][j-1]))
			{
				printf("%d %d\n",i,j );
				palin[i][j]=1;
			}
		}
	}
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
			printf("%d ",palin[i][j] );
		printf("\n");
	}
	for(int i=0;i<len;i++)
	{
		if(palin[0][i])
			dp[i]=0;
		else
		{
			dp[i]=1e9;
			for(int j=1;j<=i;j++)
				if(palin[j][i] && 1+dp[j-1]<dp[i])
					dp[i]=dp[j-1]+1;
		}
	}
	for(int i=0;i<len;i++)
		printf("%d ",dp[i] );
	printf("%d\n",dp[len-1]);
	return 0;
}