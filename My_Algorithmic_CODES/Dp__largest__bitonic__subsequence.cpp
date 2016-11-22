/*
by chinmay rakshit
on 8/2/2016
input
8
1 11 2 10 4 5 2 1
output
6
-------------------
input
6
12 11 40 5 3 1
output
5
-------------------
input
6
80 60 30 40 20 10
output
5
-------------------
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
	int n,a[500],dp[500]={0},pd[500]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		dp[i]=1;
		for(int j=0;j<=i;j++)
		{
			if(a[j]<a[i])
				dp[i]=max(1+dp[j],dp[i]);
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		pd[i]=1;
		for(int j=n-1;j>=i;j--)
		{
			if(a[i]>a[j])
				pd[i]=max(1+pd[j],pd[i]);
		}
	}
	int ac=0;
	for(int i=0;i<n;i++)
		ac=max(ac,dp[i]+pd[i+1]);
	printf("%d\n",ac);
	return 0;
}