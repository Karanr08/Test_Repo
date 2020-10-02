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




bool isBalanced(string s)
{
	int count = 0;
	for(char x : s)
	{
		if( x == '(') count++;
		else if (x == ')') count--;
		if (count < 0) return 0;
	}


	return count == 0;
}


void solve()
{
	map<string, bool> vis;

	vector<string> ans;
	queue<string> q;

	Q.push(s);

	int found = 0;

	while (!Q.empty())
	{
		string u = Q.front();
		Q.pop();

		if(vis[u])
			continue;

		vis[u] = 1;

		if(isBalanced(u))
		{
			found = 1;
			ans.push_back(u);
		}

		if(found)
			continue;

		for(int i = 0; i < u.size(); i++)
		{
			if(u[i] == '(' || u[i] == ')')
			{
				string v = u.substr(0, i) + u.substr(i + 1, u.size());
				Q.push(v);
			}
		}
	}

	return ans;

}


int main()
{

}



vector<int> v;
vector<vector<int>> ans;



void getSum(TreeNode *root, int target)
{

	if(root == NULL)
		return;
	int val = root->val;


	if(target == val && root->left == NULL && root->right == NULL)
	{
		v.push_back(val);
		ans.push_back(v);
		v.pop_back();
	}

	v.push_back(val);
	getSum(root->left, target - val);
	getSum(root->right, target - val);

	v.pop_back();
}