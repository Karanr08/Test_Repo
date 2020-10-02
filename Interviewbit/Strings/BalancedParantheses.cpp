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
/*

unsigned long long binomialCoeff(int n, int k)
{
	unsigned long long int res = 1;
	if(k > n - k)
		k = n - k;

	for(int i = 0; i < k; i++)
	{
		res *=(n - i);
		res /= (i + 1);
	}

	return res;
}


unsigned long long catalan(int n)
{
	unsigned long long c = binomialCoeff(2*n, n);

	return c/(n +1);
}

unsigned long long findways(int n)
{
	if(n&1)
		return 0;

	return catalan(n/2);
}

int main()
{
	int n;
	cin >> n;
	cout << findways(2*n) << endl;
}

*/
/*
vector<string> ans;/*
void balancedParantheses(int pos, int n, int open, int close, int &ans, vector<string> &result)
{

	string str;

	if(close == n)
	{
		result.push_back(str);
		ans++;
		return;
	}

	else
	{
		if(open > close)
		{
			str[pos] = ')';
			balancedParantheses(pos + 1, n, open , close + 1, ans, result);
		}
		if(open < n){

			str[pos] = '(';

			balancedParantheses(pos + 1, n, open + 1, close, ans, result);
		}	

	}
}

int main()
{

	speed;
	int n;
	cin >> n;

	int ans  = 0;
	vector<string> result;

	balancedParantheses(0, n, 0, 0, ans, result);
	cout << ans  << endl;

	for(auto it : result)
	{
		cout << it << endl;
	}


}*/
/*
int n;
string s;

void solve(int pos, int open, int closed)
{
	if(pos == 2*n)
	{
		ans.push_back(s);
		return;
	}

	if(open > closed)
	{
		s[pos] = ')';
		solve(pos + 1, open, closed + 1);
	}

	if(open < n)
	{
		s[pos] = '(';
		solve(pos + 1, open + 1, closed);
	}
}


int32_t main()
{

	speed;
	cin >> n;

	s.assign(2*n, '(');

	solve(0, 0, 0);
	

	
	cout << ans.size() << endl;

	for(auto i : ans)
		cout << i << endl;
}

*/

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n, 0);

	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	priority_queue<pair<int, int>> pq;

	for(int i = 0; i < n; i++)
	{
		if(i - arr[i] < 0)
		{
			pq.push({arr[i] + 1, i});
		}
		else
			pq.push({2*arr[i] + 1, i});
	}
	int count = 0;
	int total = 0;
	while(!pq.empty())
	{
		pair<int, int> temp = pq.top();
		total += temp.first;
		if(total >= n){
			count++;
			break;
		}
		count++;

		pq.pop();
	}
	cout <<count << endl;

}


int m;
int n;

string str;

int wl;

vector<vector<char>> board;

bool exist(vector<vector<char>> &b, string word)
{
	m = b.size();
	n = b[0].size();

	str = word;

	wl = word.length();

	board = b;

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(board[i][j] == word[0] && dfs(i, j, 0))
				return true;
		}
	}

	return false;
}


bool dfs(int i, int j, int c)
{
	if(c == wl)
		return true;

	if(i >= m || i < 0 || j >= n || j < 0 || board[i][j] != str[c])
	{
		return false;
	}


	char temp = board[i][j];
	board[i][j] = '@';

	bool found = (dfs(i, j + 1, c + 1) || dfs(i, j - 1, c + 1) || dfs(i + 1, j, c + 1) || dfs(i - 1, j ,c +1));
	board[i][j] = temp;

	return found;
}