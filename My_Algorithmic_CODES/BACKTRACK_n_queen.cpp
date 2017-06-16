//8 Queen problem
#include <bits/stdc++.h>
int flag=0;
bool check(int a[101][101],int n,int row,int col)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        c+=a[row][i];
        c+=a[i][col];
    }
    int i=row,j=col;
    while(i>=0 && j>=0) c+=a[i--][j--];
    i=row,j=col;
    while(i>=0 && j<n) c+=a[i--][j++];
    i=row,j=col;
    while(i<n && j<n) c+=a[i++][j++];
    i=row,j=col;
    while(i<n && j>=0) c+=a[i++][j--];
    if(c==6)
        return true;
    else
        return false;
}
bool fun(int a[101][101],int n,int row)
{
    if(row==n)
    {
        flag=1;
        return true;
    }
    for(int i=0;i<n;i++)
    {
        a[row][i]=1;
        if(check(a,n,row,i) && fun(a,n,row+1))
            break;
        a[row][i]=0;
    }
    if(flag)return true;
    else return false;
}
int main()
{
    int n,a[101][101]={0};
    scanf("%d",&n);
    if(fun(a,n,0))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                printf("%d ",a[i][j] );
            printf("\n");
        }
    }
    return 0;
}