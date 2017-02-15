#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 105
#define INF (1<<29)
#define PI acos( -1.0 )
#define R 6378

typedef long double ld;

ld A[ N ] , B[ N ];
int D[ N ][ N ];

int main()
{
	int n , m , Q , tc = 0;
	while( scanf( "%d%d%d" , &n , &m , &Q ) == 3 )
	{
		if( n == 0 && m == 0 && Q == 0 ) break;
		if( tc ) puts( "" );
		printf( "Case #%d\n" , ++tc );
		map< string , int >M;
		REP( i , n )
		{
			string s;
			cin >> s >> A[ i ] >> B[ i ];
			A[ i ] *= ( PI/180 );
			B[ i ] *= ( PI/180 );
			M[ s ] = i;
		}
		REP( i , n ) REP( j , n ) D[ i ][ j ] = INF;
		REP( i , m )
		{
			string s , t;
			cin >> s >> t;
			int a = M[ s ] , b = M[ t ];
			ld cost = sin( A[ a ] )*sin( A[ b ] ) + cos( A[ a ] )*cos( A[ b ] )*cos( B[ a ] - B[ b ] );
			ld T = acos( cost );
			ld dist = T*R;
			D[ a ][ b ] = round( dist );
		}
		REP( k , n )REP( i , n )REP( j , n )
			D[ i ][ j ] = min( D[ i ][ j ] , D[ i ][ k ] + D[ k ][ j ] );
		REP( i , Q )
		{
			string s , t;
			cin >> s >> t;
			int a = M[ s ] , b = M[ t ];
			if( D[ a ][ b ] >= INF ) puts( "no route exists" );
			else printf( "%d km\n" , D[ a ][ b ] );
		}
	} 
}
