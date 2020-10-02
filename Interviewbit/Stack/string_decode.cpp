
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


string decode(string str)
{
	stack<int> intStack;
	stack<char> charStack;

	string temp = "", result = "";

	int n = str.length();

	for(int i = 0; i < n; i++)
	{
		int count = 0;
		if(str[i] >= '0' && str[i] <= '9')
		{
			while(str[i] >= '0' && str[i] <= '9')
			{
				count = count*10 + str[i] - '0';
				i++;
			}
			i--;
			intStack.push(count);
		}

		else if(str[i] == ']')
		{
			temp = "";
			count = 0;
			if(!intStack.empty())
			{
				count = intStack.top();
				intStack.pop();
			}

			while(!charStack.empty() && charStack.top() != '[')
			{
				temp = charStack.top() + temp;
				charStack.pop();
			}
			if(!charStack.empty() && charStack.top() == '[')
			{
				charStack.pop();
			}
			for(int j = 0; j < count; j++)
			{
				result += temp;
			}
			for(int j = 0; j < result.length(); j++)
			{
				charStack.push(result[j]);
			}
			result = "";
		}
		else if (str[i] == '[')
		{
			if(str[i - 1] >= '0' && str[i - 1] <= '9')
				charStack.push(str[i]);
			else
			{
				charStack.push(str[i]);
				intStack.push(1);
			}
		}
		else
			charStack.push(str[i]);


	}

	while(!charStack.empty()){
		result = charStack.top() + result;
		charStack.pop();
	}

	return result;

}
int main()
{
	string str;
	cin >> str;
	cout << decode(str) << endl;
}