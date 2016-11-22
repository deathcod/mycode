/*
quicksort
by chinmay rakshit
*/
#include <bits/stdc++.h>
void swap(int a[],int i,int j)
{
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}
void quick(int a[],int m,int n)
{
    int i,j,temp,key;
 if(m<n){
   key=a[m];
   i=m;
   j=n+1;   
   while(i<j){ 
   do{
     i=i+1;
     }while(a[i]<key && i<=n);
   do{
     j=j-1;
    }while(key<a[j]);
    if(i<j){
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
     }
     } 
     a[m]=a[j];
     a[j]=key;
     quick(a,m,j-1);
     quick(a,j+1,n);
    }
}
using namespace std;
int main()
{
    int a[5]={2,1,1,1,1};
    quick(a,0,4);
    for(int i=0;i<=4;i++)
        printf("%d,",a[i] );
    printf("\n");
    return 0;
}