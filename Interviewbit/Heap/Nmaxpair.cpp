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

// MIN_HEAP priority_queue <Type, vector<Type>, ComparisonType> min_heap;
void Solve(vector<int> A, vector<int> B, int N)
{
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	priority_queue <pair<int, pair<int, int>>> pq;

	set< pair<int, int>> my_set;
	pq.push(make_pair(A[N - 1] + B[N - 1], make_pair(N-1, N-1)));

	my_set.insert(make_pair(N-1, N-1));

	for(int k = 0; k < N; k++)
	{
		pair<int, pair<int, int> > temp = pq.top(); 
        pq.pop(); 

        cout << temp.first << endl;

        int i = temp.second.first;
        int j = temp.second.second;

        int sum = A[i - 1] + B[j];

        pair<int, int> temp1 = make_pair(i - 1, j);
        if(my_set.find(temp1) == my_set.end())
        {
        	pq.push(make_pair(sum, temp1));
        	my_set.insert(temp1);
        }

        sum = A[i] + B[j - 1];
        temp1 = make_pair(i, j - 1);
        if (my_set.find(temp1) == my_set.end()) { 
            pq.push(make_pair(sum, temp1)); 
            my_set.insert(temp1); }

	}


}

int main()
{
	vector<int> A = {3, 2, 4, 2};
	vector<int> B = {4, 3, 1, 2};
	Solve(A, B, A.size());
}