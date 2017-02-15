#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
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
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

pii P[ N ];
pii p[ N*N ];
int main()
{
	int tc;
	sc( tc );
	while( tc -- )
	{
		int n;
		sc( n );
		REP( i , n ) sc( P[ i ].fi ) , sc( P[ i ].se );
		int t = 0;
		REP( i , n )
			for( int j = i + 1 ; j < n ; ++j )
				p[ t++ ] = mp( P[i].fi + P[j].fi , P[i].se + P[j].se );
		sort( p , p + t );
		ll ans = 0;
		for( int i = 0 ; i < t ; ++i )
		{
			ll tam = 1;
			while( i + tam < t &&p[ i ] == p[ i + tam ] ) tam++;
			i = i + tam - 1;
			ans += tam*(tam-1);
		}
		cout << ans/2 << endl;
	}
}
