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





bool checkRedundancy(string &str)
{
	stack<char> st; 
  
    // Iterate through the given expression 
    for (auto& ch : str) { 
  
        // if current character is close parenthesis ')' 
        if (ch == ')') { 
            char top = st.top(); 
            st.pop(); 
  
            // If immediate pop have open parenthesis '(' 
            // duplicate brackets found 
            bool flag = true; 
  
            while (top != '(') { 
  
                // Check for operators in expression 
                if (top == '+' || top == '-' ||  
                    top == '*' || top == '/') 
                    flag = false; 
  
                // Fetch top element of stack 
                top = st.top(); 
                st.pop(); 
            } 
  
            // If operators not found 
            if (flag == true) 
                return true; 
        } 
  
        else
            st.push(ch); // push open parenthesis '(', 
                  // operators and operands to stack 
    } 
    return false; 
}
int main()
{
	string s;
	cin >> s;
	cout << checkRedundancy(s);
}