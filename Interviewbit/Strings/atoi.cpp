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
/*
string printRoman(int number) 
{ 
	string s;
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
    int i=12;     
    while(number>0) 
    { 
      int div = number/num[i]; 
      number = number%num[i]; 
      while(div--) 
      { 
        s += sym[i]; 
      } 
      i--; 
    } 
    return s;

} */

/*
long long int atoi(string s)
{
	speed;
	int sign = 1, base = 0, i = 0;
	while(s[i] == ' ')
		i++;

	if(s[i] == '-' || s[i] == '+')
	{
		sign = 1 - 2*(s[i++] == '-');
	}

	while(s[i] >= '0' && s[i] <= '9')
	{
		if(base > INT_MAX /10 || (base == INT_MAX/10 && s[i] - '0' > 7))
		{
			if(sign == 1)
				return INT_MAX;
			else
				return INT_MIN;
		}
		base = 10*base + (s[i++] - '0');

	}
	return base*sign;
	/*int result = 0 ;
	int val;
	for(int i = 0; i < s.length(); i++)
	{
		val = s[i] - '0';
		if(val >= 0 && val <= 9)
		{
			result = result*10 + val;
		}
		else
			break;
	}
	return result;*/
/*
string binSum(string a, string b)
{
	string result = ""; // Initialize result 
    int s = 0;          // Initialize digit sum 
  
    // Traverse both strings starting from last 
    // characters 
    int i = a.size() - 1, j = b.size() - 1; 
    while (i >= 0 || j >= 0 || s == 1) 
    { 
        // Comput sum of last digits and carry 
        s += ((i >= 0)? a[i] - '0': 0); 
        s += ((j >= 0)? b[j] - '0': 0); 
  
        // If current digit sum is 1 or 3, add 1 to result 
        result = char(s % 2 + '0') + result; 
  
        // Compute carry 
        s /= 2; 
  
        // Move to next digits 
        i--; j--; 
    } 
    return result; 
}

*/
int subetSum(int arr[], int n, int Sum)
{

	int dp[n + 1][Sum + 1];

	for(int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;
	}

	for(int i = 1; i <= Sum; i++)
	{
		dp[0][i] = 0 ;
	}
	

	for(int i = 1; i <=n ; i++)
	{
		for(int j = 1; j <= Sum; j++)
		{
			if(j < arr[i - 1])
				dp[i][j] = dp[i-1][j];
			if(j >= arr[i - 1])
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
		}
	}
	return dp[n][Sum];
}


int main()
{
	
}