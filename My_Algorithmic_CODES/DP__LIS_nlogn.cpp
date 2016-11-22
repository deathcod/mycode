/*
dp lis time complexity nlogn
by chinmay rakshit
date:27/1/2016
input 
11
3 4 -1 5 8 2 3 12 7 9 
output
10 9 7 3 2 -1 (do the reverse,plzz)
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
int a[1000000]={0};
char ch;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int len[100005]={0},parent[100005];
	for(int i=0;i<=n;i++)
		parent[i]=-1;
	int x=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>a[len[x]])
		{
			len[++x]=i;
			parent[i]=len[x-1];
		}
		else
		{
			int lo=0,hi=x;
			while(lo<hi)
			{
				int mid=(lo+(hi-lo)/2);
				if(a[len[mid]]<=a[i])lo=mid+1;
				else hi=mid;
			}
			//if(i==6)
				//printf("%d %d %d\n",parent[i],len[hi], );
			if(hi!=0)
				parent[i]=len[hi-1];
			len[hi]=i;
		}
		for(int j=0;j<n;j++)
			printf("%d ",parent[j] );
		printf("\n");
		for(int j=0;j<n;j++)
			printf("%d ",len[j] );
		printf("\n\n");
	}
	//return 0;
	x=len[x];
	while(x!=-1)
	{
		printf("%d ",a[x]);
		x=parent[x];
	}
	printf("\n");
	return 0;
}