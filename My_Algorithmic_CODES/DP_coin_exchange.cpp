/*
coin exchange
by chinmay rakshit
date 6/2/2016 
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
	int n,m,a[5000]={0},b[5000]={0};
	scanf("%d %d",&n,&m);
	a[0]=1;
	for(int i=0;i<m;i++)
		scanf("%d",&b[i]);
	for(int j=0;j<m;j++)
	{
		for(int i=1;i<=n;i++)
			if(i-b[j]>=0)
				a[i]+=a[i-b[j]];
		for(int j=0;j<=n;j++)
			printf("%d ",a[j] );
		printf("\n");
	}
	printf("%d\n",a[n]);
	return 0;
}