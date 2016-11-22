#include <bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=n-1;i>=0;i--)
        {
            int key=a[i];
            b[i]=0;
            int j=i+1;
            while(j<n && a[j]<key)
            {
                a[j-1]=a[j];
                b[i]++;
                j++;
            }
            a[j-1]=key;
        }
        for(int i=0;i<n;i++)
            printf("%d ",b[i]);
        printf("\n");
    }
    return 0;
}
