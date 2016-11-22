	/*
done by chinmay 
date 6/2/2016
input
sunday saturday
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
int main()
{
	string s,t;
	cin>>s>>t;
	int len1=s.size(),len2=t.size(),a[105][105]={0};
	for(int i=0;i<=len1;i++)
		a[i][0]=i;
	for(int j=0;j<=len2;j++)
		a[0][j]=j;
	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			if(s[i-1]==t[j-1])
				a[i][j]=a[i-1][j-1];
			else
				a[i][j]=min(a[i][j-1],min(a[i-1][j],a[i-1][j-1]))+1;
		}
	}
	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
			printf("%d ",a[i][j] );
		printf("\n");
	}
	printf("%d\n",a[len1][len2] );
	return 0;
}