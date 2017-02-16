#include<bits/stdc++.h>
using namespace std;
//a = latitude , b = longitude 
//ld cost = sin( a1 )*sin( a2 ) + cos( a1 )*cos( a2 )*cos( (b1 - b2) );
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 105
#define R 6378
#define PI 3.141592653589793
#define EPS (1e-8)
#define INF (1e50)

typedef long double ld;

string city[ N ];
ld lat[ N ] , lon[ N ];
ld DP[ N ][ N ];

void fix( ld &x ){
	x *= PI/180.0;
}
int main()
{
	int n , m , Q , tc = 0;
	while( cin >> n >> m >> Q ){
		if( n == 0 && m == 0 && Q == 0 ) break;
		REP( i , n ) REP( j , n ) DP[ i ][ j ] = INF;
		REP( i , n ) DP[ i ][ i ] = 0;
		REP( i , n ) cin >> city[ i ] >> lat[ i ] >> lon[ i ];
		map< string , int >id;
		REP( i , n ) id[ city[ i ] ] = i;
		string s , t;
		REP( i , m ){
			cin >> s >> t;
			int u = id[ s ] , v = id[ t ];
			ld a1 = lat[ u ] , a2 = lat[ v ];
			ld b1 = lon[ u ] , b2 = lon[ v ];
			fix( a1 ) , fix( a2 ) , fix( b1 ) , fix( b2 );
			ld cost = sin( a1 )*sin( a2 ) + cos( a1 )*cos( a2 )*cos( (b1 - b2) );
			ld tt = acos( cost );
			DP[ u ][ v ] = round( tt*R );
		}
		REP( k , n ) REP( i , n ) REP( j , n ) DP[ i ][ j ] = min( DP[ i ][ j ] , DP[ i ][ k ] + DP[ k ][ j ] );
		if( tc ) puts( "" );
		printf( "Case #%d\n" , ++ tc );
		REP( i , Q ){
			cin >> s >> t;
			int u = id[ s ] , v = id[ t ];
			if( (ld)INF - (ld)EPS <= DP[ u ][ v ] ) puts( "no route exists" );
			else printf( "%.0f km\n" , double( DP[ u ][ v ] ) );
		}
	}
}
