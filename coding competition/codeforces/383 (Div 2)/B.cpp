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
ll a[100005]={0};

int main(int argc, char const *argv[])
{
    int n,m,x;
    scanf("%d %d",&n,&m);
    

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        a[x]++;
    }
    ll sum = 0;
    for (int i = 1; i <= 100000; ++i)
    {
        if (a[i]!=0 && (i^m) <= 100000 && a[i^m]!=0)
        {
            sum += (ll)(a[i]*a[i^m]);
        }
    }
    if(m==0)
        cout << (sum-n)/2;
    else
        cout << sum/2;

    return 0;
}