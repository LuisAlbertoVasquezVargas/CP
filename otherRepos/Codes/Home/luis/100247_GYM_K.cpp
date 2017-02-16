#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

#define N 200005

typedef vector< int > vi;
typedef long long ll;

int main()
{
	int a , b , c , n;
	while( sc( n ) == 1 )
	{
		vector< pair< pair< int , int > , int > >P( n );
		REP( i , n ) {
			sc( a ) , sc( b ) , sc( c );
			P[ i ] = mp( mp( a , b ) , c );
		}
		sort( all( P ) );
		vi A( n ) , B( n ) , C( n );
		REP( i , n ) A[ i ] = P[ i ].fi.fi , B[ i ] = P[ i ].fi.se , C[ i ] = P[ i ].se;
		set< int > XY;
		ll x = 0;
		REP( i , n ){
			int w = distance( XY.begin() , XY.upper_bound( min( B[ i ] , C[ i ] ) ) );
			x += w ;
			XY.insert( max( B[ i ] , C[ i ] ) );
		}
		//cout << "tot " << (ll)( n * ( n - 1 ) )/2 << " " << x << endl; 
		cout << (ll)( n * ( n - 1 ) )/2 - x << '\n';
	}
}
