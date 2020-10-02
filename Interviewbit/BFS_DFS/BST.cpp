#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#define fo(i,l,r) for(int i=l;i< r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int lli;
typedef unsigned long long int ulli;
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
using namespace std;
#define M 1000000007

struct Node{
	int data;
	Node *left, *right;
};

/*
void storeBSTNodes(Node *root, vector<Node*> &nodes)
{
	if(root == NULL)
		return;

	storeBSTNodes(root -> left, nodes);
	nodes.push_back(root);
	storeBSTNodes(root -> right, nodes);
}


Node *buildTreeUtil(vector<Node*> &nodes, int start, int end)
{
	if(start > end)
		return NULL;
	int mid = (start + end)/2;

	Node *root = nodes[mid];

	root -> left = buildTreeUtil(nodes, 0, mid - 1);
	root -> right = buildTreeUtil(nodes, mid + 1, end);
	return root;
}


Node *buildTree(Node *root)
{
	vector<Node*> nodes;
	storeBSTNodes(root, nodes);
	int n = nodes.size();
	return buildTreeUtil(nodes, 0, n - 1);
}

Node *newNode(int data)
{
	Node *node = new Node;

	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;
	return (node);
}

void preOrder(Node *node)
{
	if(node == NULL)
		return;
	printf("%d", node -> data);

	preOrder(node -> left);
	preOrder(node -> right);
}


int main()
{
	Node *root = newNode(10);
	root->left = newNode(8); 
    root->left->left = newNode(7); 
    root->left->left->left = newNode(6); 
    root->left->left->left->left = newNode(5);

    root = buildTree(root);
    preOrder(root);
    return 0;
}*/
Node *newNode(int data)
{
	Node *node = new Node;

	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;
	return (node);
}

void help1(Node *root, vector<int> &v)
{
	if(root == NULL)
		return;
	help1(root -> left, v);
	v.push_back(root -> data);
	help1(root -> right, v);
}

int main()
{
	Node *root1 = newNode(2);
	root1 -> left = newNode(1);
	root1 -> right = newNode(4);
	Node *root2 = newNode(1);
	root2 -> left = newNode(0);
	root2 -> right = newNode(3);

	vector<int> v1, v2;
	help1(root1, v1);
	help1(root2, v2);
	for(int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}