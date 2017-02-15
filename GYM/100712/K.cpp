#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , X;
		sc( n ) , sc( X );
		vi A( n );
		REP( i , n ) sc( A[ i ] );
		vpii v;
		REP( i , n ) v.pb( mp( A[ i ] , i ) );
		sort( all( v ) );
		pii best( INT_MAX , INT_MAX );
		
		REP( i , n ){
			if( A[ i ] == 0 ) continue;
			if( X % A[ i ] == 0 ){
				int pos = lower_bound( all( v ) , mp( X / A[ i ] , i + 1 ) ) - v.begin();
				if( pos < SZ( v ) && (ll)v[ pos ].fi * A[ i ] == X ){
					int a = A[ i ] , b = v[ pos ].fi;
					if( a >= b ) swap( a , b );
					best = min( best , mp( a , b ) );
				}
			}
		}
		if( best.fi == INT_MAX ) puts( "-1" );
		else{
			printf( "%d %d\n" , best.fi , best.se );
		}
	}
}


