#include<bits/stdc++.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}
typedef struct tree
{
    int leftmostsum;
    int maxsum;
    int rightmostsum;
    int sum;
}t;
t combine(t q,t r)
{
    t p;
    p.rightmostsum=max(r.sum+q.rightmostsum,r.rightmostsum);
    p.leftmostsum=max(r.leftmostsum+q.sum,q.leftmostsum);
    p.sum=q.sum+r.sum;
    p.maxsum=max(p.rightmostsum,max(p.sum,max(p.leftmostsum,q.rightmostsum+r.leftmostsum)));
    p.maxsum=max(p.maxsum,max(q.maxsum,r.maxsum));
    return p;
}
t construct_segment_tree(t *we,int a[],int left,int right,int pos)
{
    t p;
    if(left==right)
    {
        p.leftmostsum=p.rightmostsum=p.sum=p.maxsum=a[left];
        we[pos]=p;
        return p;
    }
    int mid=(left+right)/2;
    t q=construct_segment_tree(we,a,left,mid,2*pos+1);
    t r=construct_segment_tree(we,a,mid+1,right,2*pos+2);
    
    p=combine(q,r);
    we[pos]=p;
    return p;
}
void update(t *we,int index,int value,int lo,int hi,int pos)
{
    t p;
    if(lo==hi && lo==index)
    {
        p.leftmostsum=p.rightmostsum=p.sum=p.maxsum=value;
        we[pos]=p;
        return ;
    }
    if(index>hi||index<lo||lo>hi)return;
    int mid=(lo+hi)/2;
    update(we,index,value,lo,mid,2*pos+1);
    update(we,index,value,mid+1,hi,2*pos+2);
    we[pos]=combine(we[2*pos+1],we[2*pos+2]);
}
t query(t *we,int left,int right,int lo,int hi,int pos)
{
    if(lo>=left && hi<=right)
        return we[pos];
    t p,q,r;
    int mid=(lo+hi)/2;
    if(right<=mid)
        return query(we,left,right,lo,mid,2*pos+1);
    if(left>=mid+1)
        return query(we,left,right,mid+1,hi,2*pos+2);
    q=query(we,left,right,lo,mid,2*pos+1);
    r=query(we,left,right,mid+1,hi,2*pos+2);
    return combine(q,r);
}
int main(int argc, char const *argv[])
{
    int n,a[50005],w;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int x=ceil(log2(n));
    x=(1<<x+1)-1;
    t *p=(t *)calloc(x,(sizeof(t)));
    construct_segment_tree(p,a,0,n-1,0);
    int z,l,r;
    scanf("%d",&z);
    while(z--)
    {
        scanf("%d %d %d",&w,&l,&r);
        if(w==1)
            printf("%d\n",(query(p,l-1,r-1,0,n-1,0)).maxsum);
        else
            update(p,l-1,r,0,n-1,0);
    }
    free(p);
    return 0;
}