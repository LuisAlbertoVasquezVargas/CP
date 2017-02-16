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

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
int X[N] , Y[N];
int parent[ N*N ];
int Find( int x )
{
	if( parent[x] == x )return x;
	return parent[x] = Find( parent[x] );
}
void Union( int p , int q )
{
	p = Find( p ) , q = Find( q );
	if( p != q )
		parent[ q ] = p;
}
int main()
{
	while( sc( n ) == 1 && n )
	{
		REP( i ,  n )sc( X[i] ) , sc( Y[i] );
		REP( i , n*n )parent[i] = i;
		vector< pair< int , pii > >P;
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; j ++ )
			{
				int dx = X[i] - X[j] , dy = Y[i] - Y[j];
				int dist = dx*dx + dy*dy;
				P.pb( mp( dist , mp( i , j ) ) );
			}
		sort( all( P ) );
		int nP = P.size();
		double ans = 0.0;
		REP( i , nP )
		{
			double D = sqrt( P[i].fi );
			int u = P[i].se.fi , v = P[i].se.se;
			if( Find(u) != Find(v) )
			{
				ans += D;
				Union( u , v );
			}
		}
		printf( "%.2lf\n" , ans );
	}
}


