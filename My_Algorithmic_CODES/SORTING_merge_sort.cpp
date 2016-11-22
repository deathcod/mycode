//mergesort 
//by chinmay rakshit
//date: 20/10/2015 
#include<bits/stdc++.h>
using namespace std;
#ifndef M
#define M 1000000007
#endif
typedef long long ll;
int max(int a,int b)
{
    return (a>b)?a:b;
}
int min(int a,int b)
{
    return (a>b)?b:a;
}
void merge_so(int a[],int p,int mid,int q)
{
    int i=0,j,k,l1[mid-p+1],l2[q-mid];
    for(i=p;i<=mid;i++)
        l1[i-p]=a[i];
    l1[i-p]=1e9;
    for(i=mid+1;i<=q;i++)
        l2[i-(mid+1)]=a[i];
    l2[i-(mid+1)]=1e9;
    i=0,j=0,k=p;
    while(k<=q)
    {
        if(l1[i]<l2[j])
            a[k++]=l1[i++];
        else
            a[k++]=l2[j++];
    }
}
void merg(int a[],int p,int q)
{
    if(p<q)
    {
        int mid=(p+q)/2;
        merg(a,p,mid);
        merg(a,mid+1,q);
        merge_so(a,p,mid,q);
    }
}
int main()
{
    int a[]={5,3,7,4,0};
    merg(a,0,4);
    for(int i=0;i<=4;i++)
        printf("%d,",a[i]);
    printf("\n");
}