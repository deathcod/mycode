//merge sort using invertion count..
//by chinmay rakshit
//date: 20 /10/2015
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
int inv_count=0;
void merge_so(int a[],int p,int mid,int q)
{
    int i=0,j,k,l1[mid-p+1],l2[q-mid];
    for(i=p;i<=mid;i++)
        l1[i-p]=a[i];
    //l1[i-p]=1e9;
    for(i=mid+1;i<=q;i++)
        l2[i-(mid+1)]=a[i];
    //l2[i-(mid+1)]=1e9;
    i=mid,j=q,k=q;
    while(k>=p)
    {
        if(l1[i]>l2[j])
        {
            a[k--]=l1[i--];
            inv_count+=(2*q)-mid+1-j;
        }
        else
        {
            a[k--]=l2[j--];
            /* 
            suppose 1 element of 1st array and two element of the 2nd array is used
            then think the third element of the 2nd array is to be inserted in  the array
            then how many elements it have to pass by is the distance between the mid and i 
            that is the unused elements of the 1st array...
            hope this information is sufficient...
            */
        }
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
    int a[]={2,1,4,3};
    merg(a,0,3);
    for(int i=0;i<=3;i++)
        printf("%d,",a[i]);
    printf("\n");
    printf("%d\n",inv_count);
}