#include <bits/stdc++.h>
using namespace std;
int a[10000000]={0};
int main()
{
    for(int i=2;i<=3163;i++)
        if(a[i]==0)
            for(int j=i*i;j<=10000000;j+=i)
                a[j]=i;
    a[1]=1;
    for(int i=2;i<=10000000;i++)
    {
        if(a[i]==0)
            a[i]=2;
        else
        {
            int x=a[i],z=i/x,c=2;
            while(z%x==0)
            {
                z=z/x;
                c++;
            }
            a[i]=a[z]*c;
        }
    }
    int t,x;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&x);
        if(a[x]>=4)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}