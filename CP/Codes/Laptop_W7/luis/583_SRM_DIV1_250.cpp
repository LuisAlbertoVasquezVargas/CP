#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second

using namespace std;


class TravelOnMars {
public:
	int minTimes(vector <int> v, int ini, int fin) {
		int n = v.size();
		vi dist( n , -1 );
		queue< int >Q;
		Q.push( ini );
		dist[ini] = 0;
		while( !Q.empty() )
		{
			int node = Q.front();
			Q.pop();
			for( int k = 0 ; k <= v[node] ; ++k )
				for( int j = -1 ; j <= 1 ; ++j )
				{
					if( !j )continue;
					int son = (node + j*k + n)%n;
					if( dist[son] == -1 )
					{
						dist[son] = dist[node] + 1;
						Q.push( son );
					}
				}
		}
		return dist[fin];
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
