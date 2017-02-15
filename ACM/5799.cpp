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

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector< string > vs;


int main(){

	vi v( 3 );
	while( sc( v[ 0 ] ) == 1 ){
		REP( i , 3 ){
			if( !i ) continue;
			sc( v[ i ] );
		}
		if( v == vi( 3 ) ) break;
		sort( all( v ) );
		if( v[ 0 ] == v[ 2 ] ){
			if( v[ 0 ] == 13 ) {
				puts( "*" );
				continue;
			}
			int x = ++v[ 0 ];
			printf( "%d %d %d\n" , x , x , x );
			continue;
		}
		if( v[ 0 ] != v[ 1 ] && v[ 0 ] != v[ 2 ] && v[ 1 ] != v[ 2 ] ){
			puts( "1 1 2" );
			continue;
		}
		vi vec = { 12 , 13 , 13 };
		if( v == vec ){
			puts( "1 1 1" );
			continue;
		}
		pii p;
		for( int i = 0 ; i < 3 ; ++i )
			for( int j = i + 1 ; j < 3 ; ++j ){
				if( v[ i ] == v[ j ] ){
					p = mp( v[ i ] , v[ 0 + 1 + 2 - (i + j)] );
					break;
				}
			}
		p.se ++;
		while( 1 ){
			if( p.se > 13 ){
				p.se = 1;
				p.fi ++;
				continue;
			}
			if( p.fi == p.se ){
				p.se ++;
				continue;
			}
			break;
		}
		vec = { p.fi , p.fi , p.se };
		sort( all( vec ) );
		printf( "%d %d %d\n" , vec[ 0 ] , vec[ 1 ] , vec[ 2 ] );
	}
}


