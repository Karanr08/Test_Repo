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


typedef struct Node{
	int data;
	struct Node *next;

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
}Node;

int findLength(Node *temp)
{
	int l = 0;
	while(temp!= NULL)
	{
		l++;
		temp = temp -> next;
	}
	return l;
}

int lPalin(Node *A)
{
	int len = findLength(A);
	Node *mid = A;
	int half;
	if(len&1)
		half = len/2 + 1;
	else
		half = len/2;

	Node *prev = NULL;

	for(int i = 0; i < half ; i++)
	{
		prev = mid;
		mid = mid -> next;
	}
	prev -> next = NULL;

	prev = NULL;

	Node *curr = mid;
	Node *next = NULL;

	while(curr != NULL)
	{
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}

	Node *t1 = A;
	Node *t2 = prev;

	while(t1 != NULL && t2 != NULL)
	{
		if(t1 -> val != t2 -> val)
			return 0;
		t1 = t1 -> next;
		t2 = t2 -> next;
	}

	return 1;
}


