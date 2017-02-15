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

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;
int n , m;
char M[ N ][ N ];
int dist[ N ][ N ];
int dx[] = { 0 , 0 ,1 , -1};
int dy[] = { 1 , -1 , 0 , 0 };

pii BFS( int i , int j )
{
	REP( x , n ) REP( y , m ) dist[ x ][ y ] = INF;
	queue< pii >Q;
	dist[ i ][ j ] = 0;
	Q.push( mp( i , j ) );
	pii u;
	while( !Q.empty() )
	{
		u = Q.front();
		Q.pop();
		REP( k , 4 )
		{
			pii v = mp( u.fi + dx[ k ] , u.se + dy[ k ] ) ;
			if( v.fi >= 0 && v.fi < n && v.se >= 0 && v.se < m && dist[ v.fi ][ v.se ] == INF && M[ v.fi ][ v.se ] == '.' )
			{
				Q.push( v );
				dist[ v.fi ][ v.se ] = dist[ u.fi ][ u.se ] + 1;
			}
		}
	}
	return u;
}
int doit()
{
	pii u ;
	REP( i , n ) REP( j , m )
		if( M[ i ][ j ] == '.' )
		{
			u = BFS( i , j );
			pii v = BFS( u.fi , u.se );
			return dist[ v.fi ][ v.se ];
		}
	return 0;
}
int main()
{
	sync
	int tc;
	sc( tc );
	while( tc-- )
	{
		sc( m ) , sc( n );
		REP( i , n ) scanf( "%s" , M[ i ] );
		printf( "Maximum rope length is %d.\n" , doit() );
	}
}


