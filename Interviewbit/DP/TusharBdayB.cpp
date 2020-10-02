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



/*vector<int> Solve(vector<int> B, int A)
{
	int mn = INT_MAX;
	int N = B.size(), i, j, pos;
	for(i = 0; i < N; i++)
	{
		if(B[i] < mn)
		{
			mn = B[i];
			pos = i;
		}
	}
	int maxkick = A/mn;

	vector<int> order;

	for(i = 0; i < maxkick; i++)
	{
		order.pb(pos);
	}
	int rem = maxkick*mn;
	rem = A - rem;
	i = 0;
	while(i < maxkick)
	{
		pos = order[i];
		int ind = -1;
		for(j = 0; j < n; j++)
		{
			if(rem - B[j] + B[pos] >= 0)
			{
				ind = j;
				rem = rem - B[j] + B[pos];
				break;
			}

		}

		if(j == n)
			break;
		order[i] = j;
		i++;
	}
	return order;
	
}*/

/*
vector<int> Solve(int W, vector<int> &wt) {
	vector<pair<int, int>> newWt;
	int prev = INT_MAX;
	for (int i = 0; i < wt.size(); i++) {
		if (wt[i] < prev) {
			newWt.push_back({i, wt[i]});
			prev = wt[i];
			cout << prev << " --->" << i << endl;
		}
	}
	int n = newWt.size();
	vector<int> ans;
	int i = 0, curr = newWt[n - 1].second;
	cout << curr << " curr " << endl;
	while (i < n) {
		if (W >= newWt[i].second && (1 + (W - newWt[i].second) / curr == W / curr)) {

			ans.push_back(newWt[i].first);
			cout << newWt[i].first << " 1"<<  endl;
			cout << newWt[i].second << " 2" << endl;
			W -= newWt[i].second;
			cout << W << "W" <<  endl;
		} else {
			i++;
		}
	}
	return ans;
}

int main()
{
	int A;
	cin >> A;
	vector<int> B = {6, 8, 5, 4, 7};
	vector<int> ans = Solve(A, B);

	for(auto it = ans.begin(); it != ans.end(); it++)
	{
		cout << *it << endl;
	}
}

*/


int main()
{
	vector<string> s = {"3", "30", "9" , "5", "34"};

	sort(s.begin(), s.end());

	for(int i = 0; i < 5; i++)
	{
		cout << s[i] << endl;
	}


}

vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
       
        priority_queue<pair<int,int> >q;
        
        int lastBusyTimeSoFar = -1;
        
        for (int i = 0 ; i < schedule.size(); ++i)
        {
            vector<Interval> busyTimes = schedule[i];
            
            for (int j = 0 ; j < busyTimes.size(); ++j)
                q.push(make_pair(-busyTimes[j].start, - busyTimes[j].end));
        }
        
        vector<Interval> result;
        
        while ( !q.empty() )
        {
            int s = -q.top().first;
            int e = -q.top().second;
            
            q.pop();
            
            if (lastBusyTimeSoFar == -1)
                lastBusyTimeSoFar = e;
            else
            {
                if ( s > lastBusyTimeSoFar) // found a gap
                {
                    result.push_back(Interval(lastBusyTimeSoFar, s));
                }
                
                if (e > lastBusyTimeSoFar)
                    lastBusyTimeSoFar = e;
            }
        }
        
        return result;
    }


    /*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>> schedule) {
       vector<Interval*> ans;
        struct cmp {
           bool operator()(Interval* a, Interval* b) {
               return a->start > b->start;
           }
       }; 
        //earlier start time has top priority
        priority_queue<Interval*, vector<Interval*>, cmp> pq; 
        //insert all employee times into the priority_queue
        for(auto employee : schedule) {
            for(auto t : employee) {
                pq.push(t);
            }
        }
        Interval* temp = pq.top();
        pq.pop();
        while(!pq.empty()) {
            auto t = pq.top();
            if(temp->end < t->start) { // No intersection
                ans.push_back(new Interval(temp->end, t->start));
                temp = pq.top();
                pq.pop();
            } else { // there is an intersection
                temp = temp->end < t->end ? t : temp;
                pq.pop();
            }
        }
        return ans;
    }
};