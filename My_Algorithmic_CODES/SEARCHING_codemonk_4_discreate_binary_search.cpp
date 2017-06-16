#include <bits/stdc++.h>
using namespace std;
int fun(int a[],int n,int dis)
{
    dis=2*dis;
    int i=0,cur=a[0]+dis,c=1;
    while(i<n)
    {
        if(a[i]<=cur)
            i++;
        else
        {
            cur=a[i]+dis;
            c++;
        }
    }
    return c;
}
int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    int *a=(int *)malloc((n+1)*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int lo=0,hi=a[n-1]-a[0],mid;
    while(lo<hi)
    {
        mid=lo+(hi-lo)/2;
        if(fun(a,n,mid)<=m)
            hi=mid;
        else
            lo=mid+1;
    }
    printf("%d\n",hi);
    return 0;
}
