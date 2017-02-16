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

#define N 12
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int memo[ N + 2 ][ ( 1 << N ) + 2 ][ 66 ];
int M[ 4 ][ 4 ];
int L;
int dp( int pos , int mask , int len )
{
	if( len == L ) return 1;
	int &dev = memo[ pos ][ mask ][ len ];
	if( dev == -1 )
	{
		dev = 0;
		int x = pos/4 , y = pos%4;
		REP( i , 3 )REP( j , 4 )
		{
			int k = 4*i + j;
			if( M[ i ][ j ] ) continue;
			if( mask &( 1<< k ) ) continue;
			int dx = abs( x - i ), dy = abs( y - j );
			int g = __gcd( dx , dy );
			bool ok = 1;
			for( int t = 1 ; t < g ; ++t )
			{
				int px = x + (t*( i - x ))/g , py = y + (t*( j - y ))/g;
				if( M[ px ][ py ] || ( mask &( 1 << ( 4*px + py ) ) ) == 0 ) {
					ok = 0;
					break;
				}
			}
			if( ok ) dev += dp( k , mask^(1<<k) , len + dx + dy );
		}
	}
	return dev;
}
int main()
{
	int tc , n ;
	sc( tc );
	while( tc-- )
	{
		sc( L ) , sc( n );
		clr( M , 0 );
		REP( i , n )
		{
			int x , y;
			sc( x ) , sc( y );
			x--, y--;
			M[ x ][ y ] = 1;
		}
		if( L >= 65 )
		{
			puts( "BAD MEMORY" );
			continue;
		}
		clr( memo , -1 );
		int ans = 0;
		REP( i , 3 ) REP( j , 4 )
			if( !M[ i ][ j ] )
				ans += dp( i*4 + j , 1<<( i*4 + j ) ,0 );
		if( !ans ) puts( "BAD MEMORY" );
		else printf( "%d\n" , ans );
	}
}


