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


void dist(vector<vector<int>> A, int k)
{
	int rows = A.size();
	int cols = A[0].size();
	int dist;
	priority_queue<ppi> pq;
        for(int i = 0; i < rows; i++)
        {
            
            
                int dist = A[i][0]*A[i][0] + A[i][1]*A[i][1];
                pq.push({dist, {A[i][0], A[i][1]}});
                
                if(pq.size() > k)
                    pq.pop();
            
        }
        vector<vector<int>> ans;
        
        while(pq.size() > 0)
        {
           cout << pq.top().second.first << "  " << pq.top().second.first << endl;
           pq.pop();
        }
         rows = ans.size();
		

		
        
}



int main()
{
	vector<vector<int>> A = {{1, 3}, {-2, 2}};
	dist(A, 1);

}
