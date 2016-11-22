/* 
by chinmay rakshit
date 7/11/2015
i will prefer not to use trie as it will do only prefix matching 
but in actual scenario it is not so.... u have to do substring 
matching so it is not prefered.... so
go for suffix tree ... u got the reason for studying suffix tree..
if not open this article and read it again...

For example, aab, abcde, aabcd is BAD SET because aab is prefix of aabcd.

Print GOOD SET if it satisfies the problem requirement.
Else, print BAD SET and the first string for which the condition fails. 
7
aab
defgab
abcde
aabcde
cedaaa
bbbbbbbbbb
jabjjjad

BAD SET
aabcde
*/
#include <bits/stdc++.h>
typedef struct $
{
    int flag;
    struct $ **m;   
}hell;

hell *init()
{
    hell *a=(hell*)malloc(sizeof(a));
    a->flag=0;
    a->m=(hell **)malloc(11*sizeof(hell*));
    for(int i=0;i<11;i++)
        a->m[i]=NULL;
    return a;
}

bool fun(char s[],hell *x,int index,int len)
{
    if(x->flag==1)
    {
        return true;
    }
    else if(index==len)
    {
        x->flag=1;
        for(int i=0;i<11;i++)
            if(x->m[i]!=NULL)
                return true;
        return false;
    }
    else if(x->m[s[index]-'a']==NULL )
    {
        hell *start=init();
        x->m[s[index]-'a']=start;
        return fun(s,start,index+1,len);
    }
    else
    {   
        return fun(s,x->m[s[index]-'a'],index+1,len);
    }
}


int main()
{
    int n;
    scanf("%d",&n);
    char s[100005];
    getchar();
    hell *start=init();
    while(n--)
    {
        scanf("%s",s);
        if(fun(s,start,0,strlen(s)))
        {
            printf("BAD SET\n%s\n",s);
            return 0;
        }
    }
    printf("GOOD SET\n");
    return 0;
}

