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


typedef struct ListNode
{
	int val;
	ListNode *next;
}ListNode;



void MoveListNode(ListNode** destRef, ListNode** sourcerRef)
{
	ListNode *newListNode = new *sourcerRef;
	assert(newListNode != NULL);

	*sourcerRef  = newListNode -> next;

	newListNode -> next = *destRef;
	*destRef = newListNode;
}
ListNode*SortedMerge(ListNode *a, ListNode *b)
{
	ListNode dummy;

	ListNode *tail = &dummy;

	dummy.next = NULL;

	while(1)
	{
		if(a == NULL){
  			break;
		}
		else if(b == NULL)
		{
			tail->next = a;
			break;
		}

		if(a->data <= b->data)
			MoveListNode(&(tail->next), &a);
		else
			MoveListNode(&(tail->next), &b);

		tail = tail->next;
	}

	return (dummy.next);
}