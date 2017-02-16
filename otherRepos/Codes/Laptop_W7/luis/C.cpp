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
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

vi E[ N ];
int vis[ N ] , ind[ N ];
void dfs( int u )
{
	vis[ u ] = 1;
	FOR( v , E[ u ] )
		if( !vis[ *v] )
			dfs( *v );
}
int main()
{
	int tc;
	sc( tc );
	while( tc-- )
	{
		int n , m;
		sc( n ) , sc( m );
		REP( i , n ) E[ i ].clear();
		clr( ind , 0 );
		clr( vis,0 );
		REP( i , m )
		{
			int x , y;
			sc( x ) ,sc( y );
			x-- , y--;
			E[ x ].pb( y );
			ind[ y ]++;
		}
		int ans = 0;
		REP( i , n )
			if( ind[ i ] == 0 && !vis[ i ] )
			{
				ans++;
				dfs( i );
			}
		REP( i , n )
			if( !vis[ i ] )
				ans++ , dfs( i );
		printf( "%d\n" , ans );
	}
}


