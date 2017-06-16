/*
spoj ETF
inp   output
5
1       1
2       1
3       2
4       2
5       4
*/
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return (a>b)?a:b;
}
int li[1000005]={0},phi[1000005]={0},n=1000000,t;
std::vector<int> v;
int main(int argc, char const *argv[])
{
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!li[i])
        {
            li[i]=i;
            phi[i]=i-1;
            v.push_back(i);
        }
        else
        {
            if(li[i]==li[i/li[i]])
                phi[i]=phi[i/li[i]]*li[i];
            else
                phi[i]=phi[i/li[i]]*(li[i]-1);
        }
        for(int j=0;j<v.size() && v[j]<=li[i] && i*v[j]<=n;j++)
            li[i*v[j]]=v[j];
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
        printf("%d\n",phi[t]);
    }
    return 0;
}