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
ll a[1000000]={0,};
int main(int argc, char const *argv[])
{
    for(int i=1;i<=1000000;i++)
    {
    	set<int>s;
    	int k=1;
    	while(s.size()!=10)
    	{
    		int f=i*k;
    		while(f>0)
    		{
    			s.insert(f%10);
    			f/=10;
    		}
    		k++;
    	}
    	a[i]=(k-1)*i;
    }
    int t,x;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
    	scanf("%d",&x);
    	if(x==0)
    		printf("Case #%d: INSOMNIA\n",i );
    	else
    		printf("Case #%d: %lld\n",i,a[x] );
    }
    return 0;
}