/*

suffix array
O(N*logn*logn)
chinmay Rakshit
date 19/2/2016

inputs banana
output 5 3 1 0 4 2 
inputs mississppi
output 10 7 4 1 0 9 8 6 3 5 2 

*/

#include <bits/stdc++.h>
using namespace std;
#ifndef M
#define M 1000000007
#endif
typedef pair<int,int>pp;
typedef std::vector<pp> vpp;
typedef long long ll;
typedef long double ld;
#ifndef pb
#define pb push_back 
#endif 
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}
typedef struct $
{
	int index;
	int rank[2];
}suffix;
bool cmpfun(suffix a,suffix b)
{
	return(a.rank[0]<b.rank[0])?1:((a.rank[0]==b.rank[0])?(a.rank[1]<b.rank[1]):0);
}
bool cmp(suffix a,suffix b)
{
	return(a.index<b.index);
}
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	int len=s.size();
	std::vector<suffix> v(len);
	for(int i=0;i<len;i++)
	{
		v[i].index=i;
		v[i].rank[0]=s[i]-'a';
		v[i].rank[1]=(i+1==len)?-1:s[i+1]-'a';
	}
	for (int i = 0; i < len; ++i)
	{
		printf("%d %d %d\n",v[i].index,v[i].rank[0],v[i].rank[1] );
	}
	printf("===========================\n");
	int k=2;
	while(1)
	{
		int i=0,a[100]={0};
		sort(v.begin(),v.end(),cmpfun);
		for (int i = 0; i < len; ++i)
		{
			printf("%d %d %d\n",v[i].index,v[i].rank[0],v[i].rank[1] );
		}
		printf("---------------------------------\n");
		for(int j=1;j<len;j++)
		{
			if(!(v[j-1].rank[0]==v[j].rank[0] && v[j-1].rank[1]==v[j].rank[1]))
				i++;
			a[j]=i;
		}
		if(i==len-1)
			break;
		for(int i=0;i<len;i++)
			v[i].rank[0]=a[i];
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<len;i++)
			v[i].rank[1]=(v[i].index+k<len)?v[v[i].index+k].rank[0]:-1;
		for (int i = 0; i < len; ++i)
		{
			printf("%d %d %d\n",v[i].index,v[i].rank[0],v[i].rank[1] );
		}
		k++;
		printf("===================================\n");
		//return 0;
	}
	for(int i=0;i<len;i++)
		printf("%d ",v[i].index);
	printf("\n");
	return 0;
}