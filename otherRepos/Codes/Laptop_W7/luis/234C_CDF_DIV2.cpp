#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100000
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

struct Point{
	ll x , y;
	Point(){}
	Point( ll x , ll y ) : x( x ) , y( y ){}
	Point ort(){ return Point( -y , x ); }
}P[ N + 5 ];

Point f( Point p , ll n , ll m ){
	Point t = p;
	t.y = m - p.y - 1;
	return t;
}
void impr( int n ){
	test
	REP( i , n ) printf( "%d %d\n" , P[ i ].x , P[ i ].y );
	test
}
int main()
{
	int n , m , a , b , c , p , x , y;
	while( sc( n ) == 1 ){
		sc( m ) , sc( a ) , sc( b ) , sc( c ) , sc( p );
		REP( i , p ) {
			sc( x ) , sc( y ) ;
			x-- , y--;
			P[ i ] = Point( x , y );
		}
		a %= 4;
		a = ( 4 - a )%4;
		REP( j , a ){
			REP( i , p ){
				P[ i ] = P[ i ].ort();
				P[ i ].x += m - 1;
			}
			swap( n , m );
		}
		//impr( p );
		b %= 2;
		if( b ) REP( i , p ) P[ i ] = f( P[ i ] , n , m );
		//impr( p );
		c %= 4;
		REP( j , c ){
			REP( i , p ){
				P[ i ] = P[ i ].ort();
				P[ i ].x += m - 1;
			}
			swap( n , m );
		}
		REP( i , p ){
			x = P[ i ].x , y = P[ i ].y;
			x ++ , y++;
			printf( "%d %d\n" , x , y );
		}
	}
}



