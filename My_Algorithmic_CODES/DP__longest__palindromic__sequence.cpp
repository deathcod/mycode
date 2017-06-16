/*
done by chinmay rakshit
date 8/2/2016
input 
GEEKSFORGEEKS
output 
5
input
BBABCBCAB
output
7
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
	string s;
	cin>>s;
	int n=s.length();
	int a[500][500]={0};
	for(int i=0;i<=n;i++)
		a[i][i]=1;
	for(int len=1;len<n;len++)
	{
		for(int i=1;i<=n-len;i++)
		{
			int j=i+len;
			if(len==1 && s[i-1]==s[j-1])
				a[i][j]=2;
			else if(s[i-1]==s[j-1])
				a[i][j]=a[i+1][j-1]+2;
			else
				a[i][j]=max(a[i][j-1],a[i+1][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",a[i][j] );
		printf("\n");
	}
	printf("%d\n",a[n][n] );
	return 0;
}