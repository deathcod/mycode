
/************************
chinmay rakshit
just loves to code ;P
*************************/
#include <bits/stdc++.h>

typedef struct $
{
    int ....;
    int ....;
    int ....;
}hell;

hell construct(hell *a,int index,int l,int r,char *s)
{
    hell p,q,rr;
    if(r==l)
    {
        /*
        here write the code for the base case
        */
    }
    int mid=(l+r)/2;
    q=construct(a,2*index+1,l,mid,s);
    rr=construct(a,2*index+2,mid+1,r,s);
    /*
	here write the code for the case when you merge the cases...
	play safe
    */
    a[index]=p;
    return a[index];
}

hell query(hell *a,int index,int x,int y,int l,int r)
{
    int mid=(l+r)/2;
    hell p,q,rr;
    if(x<=l && r<=y)
        return a[index];
    if(y<=mid)
        return query(a,2*index+1,x,y,l,mid);
    if(mid+1<=x)
        return query(a,2*index+2,x,y,mid+1,r); 
    q=query(a,2*index+1,x,y,l,mid);
    rr=query(a,2*index+2,x,y,mid+1,r); 
    /*
    here write the code for the case when you merge the cases...
	play safe
    */
    return p;
}
int main()
{
    int n,xx,yy;
    int,char s[100000];
    /*
    input the array and save them and perform the computation
    */
    int x=ceil(log2(len));
    x=(1<<(x+1))-1;
    hell *a=(hell *)calloc(x,sizeof(hell));
    
    //construct the segment tree...
    construct(a,0,0,len-1,s);
 
    //input the query starting and ending....
    hell p=query(a,0,xx,yy,0,len-1);
    printf("%d\n",p.ans );
    return 0;
}