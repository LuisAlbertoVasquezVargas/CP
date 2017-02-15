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
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

#define MAXN 20
#define MAXVAL 10000

int p[MAXVAL*MAXN+1];
int v[MAXN];
int n;

void doit()
{
	me( p , 0 );
	p[0] = 1;
	for( int j = 0 ; j < n ; ++j)
		for( int k = MAXVAL* MAXN - v[j] ; k >= 0 ; k--)
			if(p[k])  p[k + v[j]]++;
}

int main()
{
	int tc;
	cin >> tc;
	while( tc-- )
	{
		cin >> n;
		for( int i = 0 ; i < n ; ++i ) cin >> v[i];
		doit();
		bool solve = 0;
		for( int i = 1 ; i <= MAXVAL*MAXN ; ++i )
			if( p[i] >= 4 ) solve =  1;
		if( solve )puts("yes");
		else	puts("no");
	}
}
