
/*
hashing
Binary tree in vertical order...
by chinmay rakshit 
19/2/2016
*/
#include <bits/stdc++.h>
using namespace std;
#ifndef M
#define M 1000000007
#endif
typedef pair<int,int>pp;
typedef std::vector<pp> vpp;
typedef long long ll;
typedef long double ld;
#ifndef pb
#define pb push_back 
#endif 
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}
typedef struct $
{
	int key;
	struct $ *left,*right;
}Node;
Node *newNode(int value)
{
	Node *x=(Node *)malloc(sizeof(Node));
	x->left=NULL;
	x->right=NULL;
	x->key=value;
	return x;
}
std::vector<std::vector<int> > v(100);
void printnode(int value,Node *root)
{
	queue<pair<int,Node*> >q;
	q.push(pair<int,Node*>(value,root));
	while(!q.empty())
	{
		pair<int,Node*> f=q.front();
		q.pop();
		value=f.first;
		Node *node=f.second;
		v[value].pb(node->key);
		if(node->left)
			q.push(pair<int,Node*>(value-1,node->left));
		if(node->right)
			q.push(pair<int,Node*>(value+1,node->right));
	}
	for(int i=0;i<100;i++)
	{
		if(v[i].size())
		{for(int j=0;j<v[i].size();j++)
			printf("%d ",v[i][j]);
		printf("\n");}
	}
}
int main(int argc, char const *argv[])
{
	Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    printnode(50,root);
	return 0;
}