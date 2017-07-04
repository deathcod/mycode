
/************************
chinmay rakshit
just loves to code ;P
*************************/
#include <bits/stdc++.h>
using namespace std;

/*
This is a tree sturcture where the update is updating in D & C method the ranges with a certain value
and the query returns the sum of the values of the nodes in that range.
*/

typedef struct $
{
    int value;
    int left;
    int right;
}node;

int query(node *a, int index, int x, int y, int range_l, int range_r)
{
    int mid=(range_l + range_r)/2;

    if(x <= range_l && range_r <= y )
        return a[index].value;

    if(y <= mid)
        return query(a, 2*index +1, x, y, range_l, mid);

    if(mid+1 <= x)
        return query(a, 2*index +2, x, y, mid +1 , range_r); 

    int range_l_mid, mid_range_r;

    range_l_mid = query(a, 2*index +1, x, y, range_l, mid);
    mid_range_r = query(a, 2*index +2, x, y, mid+1, range_r); 

    return range_l_mid + mid_range_r;
}

void update(node *a, int index, int x, int range_l, int range_r, int value)
{
    printf("range_l :%d, range_r: %d, index: %d\n", range_l, range_r, index);

    if(range_l <= x && x <= range_r)
    {
        a[index].value += value;
        if(range_l == range_r)
            return;
    }

    int mid = (range_l + range_r)/2;

    if(x<= mid && range_l<=x)
        return update(a, 2* index +1, x, range_l, mid, value);

    if(mid+1 <= range_r && mid+1 <= x && x <= range_r)
        return update(a, 2* index +2, x, mid+1, range_r, value);
}

void output(node *a, int n)
{
    for (int i = 0; i < 2 * n -1; ++i)
    {
        printf("%d ", a[i].value);
    }
    printf("\n");
}

int main()
{
    int n=4;
    node* nd =new node[2*n-1];
    
    update(nd, 0, 0, 0, n-1, 1); cout << "--------------\n";
    update(nd, 0, 2, 0, n-1, 1); cout << "--------------\n";
    update(nd, 0, 1, 0, n-1, 1); cout << "--------------\n";

    output(nd, n);


    cout << query(nd, 0, 0, 3, 0, n-1) << "\n";
    return 0;
}