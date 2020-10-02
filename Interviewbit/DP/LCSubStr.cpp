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

string PrintLCSubstr(string x, string y, int m, int n)
{
	int LCS[m + 1][n + 1];

	int len = 0;

	int row, col;

	for(int i = 0; i <=m; i++){
		for(int j = 0; j <=n; j++){
			if(i == 0 || j == 0)
				LCS[i][j] = 0;

			else if(x[i - 1] == y[j - 1]){
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
				if(len < LCS[i][j])
				{
					len = LCS[i][j];
					row = i;
					col = j;
				}
			}
			else
					LCS[i][j] = 0;
		}
	}


	if (len == 0)
		return 0;

	char *result = (char*)malloc((len + 1)*sizeof(char));
	while(LCS[row][col] != 0)
	{
		result[--len] = x[row-1];
		row--;
		col--;
	}

	return result;
}


void printSubStr(string x, int low, int high)
{
	for(int i = low; i <= high; i++)
		cout << x[i];
}

void longestPalSubstr(string str)
{
	int n = str.size();

	bool table[n][n];
	memset(table, 0, sizeof(table));

	int maxlen = 1;

	for(int i = 0; i < n; i++)
	{
		table[i][i] = true;
	}


	int start = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if(str[i] == str[i + 1])
		{
			table[i][i + 1] = true;

			start = i;
			maxlen = 2;
		}
	}


	for(int k = 3; k <=n ; k++)
	{
		for(int i = 0; i < n - k + 1; i++)
		{
			int j = i + k -1;

			if(table[i + 1][j - 1] && str[i] == str[j])
			{
				table[i][j] = true;

				if(k > maxlen)
				{
					start = i;
					maxlen = k;
				}
			}
		}
	}
	printSubStr(str, start, start + maxlen - 1); 
}
int main()
{
	string x;
	cin >> x;
	longestPalSubstr(x);

}