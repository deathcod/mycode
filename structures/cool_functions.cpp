#define gu getchar();
#include <bits/stdc++.h>
#define M 10000
using namespace std;
typedef long long ll;
inline int scan()
{
    int n=0;
    char ch=gu;
    while(ch<48){ch=gu;}
    while(ch>47){n=(n<<3)+(n<<1)+ch-'0';ch=gu;}
    return n;
}
int fast_gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}
int a[10000]={0},prime[1000];
void prime_calculator()
{
    for(int i=6;i<=100;i+=6)
    {
        if(a[i-1]==0)
            for(int j=(i-1)*(i-1);j<=M;j+=((i-1)<<1))
                a[j]=1;
        if(a[i+1]==0)
            for(int j=(i+1)*(i+1);j<=M;j+=((i+1)<<1))
                a[j]=1;
    }
    int j=2;prime[0]=2,prime[1]=3;
    for(int i=6;i<=M+6;i+=6)
    {
        if(a[i-1]==0)
            prime[j++]=i-1;
        if(a[i+1]==0)
            prime[j++]=i+1;
    }
}