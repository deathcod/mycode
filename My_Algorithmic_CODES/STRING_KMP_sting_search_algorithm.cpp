/*
KMP search algorithm
by chinmay rakshit
*/
#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[])
{
    char s[10]="abcd";
    char s1[100]="abcxabcdabxabcdabcd";
    int a[100]={0};
    int i=1,j=0,z=0;a[0]=0;
    while(1)
    {
        if(i==strlen(s))break;
        if(s[i]==s[j]){a[i++]=++j;}
        else
        {
            if(j)j=a[j-1];
            else a[i++]=0;
        }
    }
    i=0,j=0,z=strlen(s1);
    while(i<z)
    {
        if(s1[i]==s[j])
        {
            i++;j++;
            if(j==strlen(s))
            {printf("%lu\n",i-strlen(s));j=a[j-1];}
        }
        else
        {
            if(j) j=a[j-1];
            else i++;
        }
    }
    return 0;
}