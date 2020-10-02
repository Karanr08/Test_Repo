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


vector<int> intersection(vector<int> A, vector<int> B)
{
	int i = 0;
	int j = 0;
	vector<int> ans;

	while(i < A.size() && j < B.size())
	{
		if(A[i] == B[j])
		{
			ans.push_back(A[i]);
			i++; 
			j++;
			
		}
		else if(A[i] > B[j])
		{
			j++;
		}
		else
			i++;
	}

	return ans;
}


int main()
{
	vector<int> A = {1, 2, 3, 3, 4, 5, 6};
	vector<int> B = {3, 3, 5};
	vector<int> ans = intersection(A, B);
	for(auto it = ans.begin(); it != ans.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}