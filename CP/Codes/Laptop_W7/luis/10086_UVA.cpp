#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define INF (1<<29)

#define pb push_back
#define all( v ) v.begin() , v.end()

typedef vector< int > vi;

int n;
int C[ 35 ][ 305 ][ 2 ];
int memo[ 35 ][ 305 ] , SZ[ 35 ] ;

int dp( int pos , int rods )
{
	if( pos == n ) return rods == 0 ? 0 :INF;
	int &dev = memo[ pos ][ rods ];
	if( dev == -1 )
	{
		dev = INF;
		for( int i = 0 ; i <= min( SZ[ pos ] , rods ) ; ++i )
			dev = min( dev , C[ pos ][ i ][ 0 ] + C[ pos ][ SZ[ pos ] - i ][ 1 ] + dp( pos + 1 , rods - i ) );
	}
	return dev;
}
vi rec( int pos , int rods )
{
	if( pos == n ) return vi();
	int dev = dp( pos , rods );
	for( int i = 0 ; i <= min( SZ[ pos ] , rods ) ; ++i )
		if( dev == C[ pos ][ i ][ 0 ] + C[ pos ][ SZ[ pos ] - i ][ 1 ] + dp( pos + 1 , rods - i ) )
		{
			vi v = rec( pos + 1 , rods - i );
			v.pb( i );
			return v;
		}
}
int main()
{
	int T1 , T2;
	while( sc( T1 ) == 1 )
	{
		sc( T2 );
		if( T1 == 0 && T2 == 0 ) break;
		sc( n );
		REP( i , n )
		{
			sc( SZ[ i ] );
			REP( j , SZ[ i ] ) sc( C[ i ][ j + 1 ][ 0 ] );
			REP( j , SZ[ i ] ) sc( C[ i ][ j + 1 ][ 1 ] );
		}
		clr( memo , -1 );
		printf( "%d\n" , dp( 0 , T1 ) );
		vi v = rec( 0 , T1 );
		reverse( all( v ) );
		REP( i , n )
			printf( "%d%s" , v[ i ] , i + 1 == n ? "\n":" " ); 
	}
}
