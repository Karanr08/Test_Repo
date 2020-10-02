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


class Node
{
public:
	int data;
	Node *next;
};


void removeDuplicates(Node *head)
{
	Node *current = head;
	Node *next;
	if(current == NULL)
		return;

	while(current->next != NULL)
	{
		if(current-> data == current->next->data)
		{
			next = current->next->next;
			free(current->next);
			current->next = next;
		}
		else
		{
			current = current->next;
		}
	}
}