/*
count sort by chinmay rakshit
date 26/10/2015
*/
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
int count_sort(int a[],int n)
{
    int maximum=0;
    for(int i=0;i<n;i++)
        maximum=max(a[i],maximum);
    maximum+=1;
    //finding the maximum element and amking an array till the maximum element
    int *aux=(int *)calloc(maximum,sizeof(int));
    for(int i=0;i<n;i++)
        aux[a[i]]++;
    for(int i=1;i<maximum;i++)
        aux[i]+=aux[i-1];
    //sliding window... now the fun thing going to start..
    int *out=(int *)malloc(maximum*sizeof(int));
    for(int i=0;i<n;i++)
    {
        out[aux[a[i]]-1]=a[i];
        /*
            for example..
            a[]=6 4 6 2 2
            aux[]=0 0 2 0 1 0 2 0
                  0 1 2 3 4 5 6 7 
            aux[]=0 0 2 2 3 3 5 5
                appling sliding window
            out[]->
            sliding window actually shows us how many elements are 
            there before a particular number
            for example
            out[aux[a[0]]-1]==out[aux[6]-1]==out[4]==6
            aux[a[0]]==aux[6]==5--=4(stored)(means if next 6 occurs will be stored in 3(4-1))
            hope this is clear... :)       
        */
        aux[a[i]]--;
    }
    for(int i=0;i<n;i++)
        printf("%d,",out[i] );
    printf("\n");
}
int main()
{
    int a[5]={5,6,6,4,5};
    count_sort(a,5);
    return 0;
}