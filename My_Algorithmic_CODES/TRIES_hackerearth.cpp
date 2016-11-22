#include <bits/stdc++.h>
using namespace std;
#ifndef M
#define M 1000000007
#endif
typedef long long ll;
typedef pair<int,int>pp;
typedef std::vector<pp> vpp;
typedef long double ld;
#ifndef pb
#define pb push_back 
#endif 
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}
typedef struct $
{
    int flag;
    struct $ **m;
}hell;

hell *init()
{
    hell *a=(hell *)malloc(sizeof(a));
    a->flag=-1;
    a->m=(hell **)malloc(27*sizeof(hell *));
    for(int i=1;i<27;i++)
        a->m[i]=NULL;
    return a;
}

void construct(char s[],hell *z,int index,int len,int value)
{
    if(index==len)
        return;
    //printf("%c %d %d\n",s[index],z->flag,value );
    //z->flag=max(value,z->flag);
    if(z->m[s[index]-'a']==NULL)
    {
        //if(s[index]=='q')
          //  printf("hello\n");
        hell *go=init();
        z->m[s[index]-'a']=go;
        go->flag=(go->flag<value)?value:go->flag;
        //printf("%c %d\n",s[index],go->flag);
        construct(s,go,index+1,len,value);
    }
    else
    {
        //if(s[index]=='e')
          //  printf("tell me ur problem\n");
        z->m[s[index]-'a']->flag=(z->m[s[index]-'a']->flag<value)?value:z->m[s[index]-'a']->flag;
        //printf("%c %d\n",s[index],z->m[s[index]-'a']->flag);
        construct(s,z->m[s[index]-'a'],index+1,len,value);
    }
}

void query(char s[],hell *z,int index,int len,int &value)
{
    value=z->flag;
    if(index==len)
        return;
    if(z->m[s[index]-'a']!=NULL)
        query(s,z->m[s[index]-'a'],index+1,len,value);
    else
    {
        value=-1;
        return;
    }
}
char s[1000006];
int main()
{
    int n,q,v;
    scanf("%d %d",&n,&q);
    getchar();
    hell *start=init();
    int z=0;
    while(n--)
    {
        scanf("%s %d",s,&v);
        //if(n!=1)
        construct(s,start,0,strlen(s),v);
       // else
         //   construct(s,start,0,strlen(s),v,1);

        z++;
    }
    while(q--)
    {
        scanf("%s",s);
        v=-1;
        query(s,start,0,strlen(s),v);
        printf("%d\n",v);
    }
    return 0;
}
