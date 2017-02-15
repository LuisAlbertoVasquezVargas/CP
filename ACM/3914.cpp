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

#define N 1000

typedef long double ld;
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vi x( n );
		REP( i , n ) sc( x[ i ] );
			
		vi op;
		for( int target = n ; target >= 2 ; --target ){
			int pos = -1;
			REP( i , n )
				if( target == abs( x[ i ] ) ) pos = i;
			assert( pos != -1 );
			op.pb( pos + 1 );
			REP( i , pos + 1 ) x[ i ] *= -1;
			reverse( x.begin() , x.begin() + pos + 1 );
			if( x[ 0 ] > 0 ){
				op.pb( 1 );
				x[ 0 ] *= -1;
			}
			op.pb( target );
			REP( i , target ) x[ i ] *= -1;
			reverse( x.begin() , x.begin() + target );
		}
		if( x[ 0 ] < 0 ){
			op.pb( 1 );
			x[ 0 ] *= -1;
		}
		//for( auto X : x ) cout << X << " * - * "; cout << endl;
		printf( "%d %d" , tc + 1 , SZ(op) );
		for( auto X : op ) printf( " %d" , X );
		puts( "" );
	}
}






