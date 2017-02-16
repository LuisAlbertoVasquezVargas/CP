#include <bits/stdc++.h>

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

int n;

int main()
{
	int tc;
	cin >> tc;
	for( int t = 0 ; t < tc ; ++t )
	{
		cin >> n ;
		vll v;
		for( int k = 1 ; k < n ; ++k )
		{
			ll K = 1LL*k*k;
			if( K > n )break;
			ll x = n - K;
			if( x && x%k == 0 )v.pb( x );
		}
		cout << "Case " << t + 1 << ": " ;
		int nv = v.size();
		sort( all(v) );
		REP( i , nv )
			cout << v[i] << (i+1==nv?"\n":" ");
	}
}


