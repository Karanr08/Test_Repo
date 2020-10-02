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


vector<int> nextGreaterInleft(int a[], int n)
{
	vector<int> left_index(MAX, 0);

	stack<int> s;

	for(int i = n-1; i >=0; i--)
	{
		while(!s.empty() && a[i] > a[s.top() - 1])
		{
			int r = s.top();
			s.pop();


			left_index[r - 1] = i + 1;
		}
		s.push(i + 1);
	}
	return left_index;
}


vector<int> nextGreaterInRight(int a[], int n)
{
	vector<int> right_index(MAX, 0);

	stack<int> s;

	for(int i = 0; i < n; i++)
	{
		while(!s.empty() && a[i] > a[s.top() - 1])
		{
			int r = s.top();
			s.pop();

			right_index[r - 1] = i + 1;
		}
		s.push(i + 1);
	}
	return right_index;
}


int LRProd(int arr[], int n)
{
	vector<int> left = nextGreaterInleft(arr, n);

	vector<int> right = nextGreaterInRight(arr, n);

	int ans = -1;

	for(int i = 1; i <=n; i++)
	{
		ans = max(ans, left[i]*right[i]);
	}
	return ans;
}