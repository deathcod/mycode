#include <bits/stdc++.h>
using namespace std;
#ifndef M
#define M 1000000007
#endif
typedef long long ll;
typedef pair<int,int>pp;
typedef std::vector<pp> vpp;
typedef long double ld;
#ifndef pb
#define pb push_back 
#endif 
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}
int main(int argc, char const *argv[])
{
	int t,flag=0;
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
		string s;
		cin>>s;
		int len=s.size();
		flag=0;
		for(int i=len-1;i>=0;i--)
		{
			if((s[i]=='+' && flag%2==0) || (s[i]=='-' && flag%2==1))
				continue;
			else
				flag++;
		}
		printf("Case #%d: %d\n",j,flag);
	}
	return 0;
}