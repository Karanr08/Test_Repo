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
typedef pair<int, int> pi; 
typedef pair<int, pair<int, int>> ppi;



struct ListNode{
	int val;
	ListNode *next;
};


struct compare{
	bool operator()( ListNode *a, ListNode *b)
	{
		return a->data > b->data;
	}
};

ListNode *mergeksorted(ListNode *arr[], int k)
{
	ListNode *head = NULL, *last;
	priority_queue<ListNode*, vector<ListNode*>, compare> pq;


	for(int i = 0; i < k; i++)
	{
		if(arr[i] != NULL)
		{
			pq.push(arr[i]);
		}
	}

	while(!pq.empty())
	{
		ListNode* top = pq.top();

		pq.pop();

		if(top -> next != NULL)
			pq.push(top->next);

		if(head == NULL){
			head = top;

			last = top;
		}
		else
		{
			last->next = top;
			last = top;
		}


	}

	return head;
}