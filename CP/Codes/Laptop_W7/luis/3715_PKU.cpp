#include<bits/stdc++.h>
using namespace std;

#define N 205

#define FOR( it , A ) for( typeof (A.begin()) it = A.begin() ; it != A.end() ; ++it )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )
#define clr( t , val )

#define pb push_back
#define all( v ) v.begin() , v.end()

typedef vector< int > vi;

int n;
vi E[ N ];
int vis[ N ] , match[ N ];
bool dfs( int u ){
	if( vis[ u ] ) return 0;
	vis[ u ] = 1;
	FOR( v , E[ u ] )
		if( match[ *v ] == -1 || dfs( *v ) )
		{
			match[ *v ] = u;
			return 1;
		}
	return 0;
}
int bpm()
{
	clr( match , -1 );
	int cnt = 0;
	REP( i , n )
	{
		clr( vis , 0 );
		cnt += dfs( i );
	}
	return cnt;
}

bool type[ N ];

int main()
{
	int cases , m , x , y ;
	sc( cases );
	while( cases -- )
	{
		sc( n );
		REP( i , n )
		{
			sc( x );
			type[ i ] = x;
		}
		sc( m );
		REP( i , m )
		{
			sc( x ) , sc( y );
			if( type[ x ] == 1 && type[ y ] == 0 )
				E[ y ].pb( x );
			else if( type[ x ] == 0 && type[ y ] == 1 )
				E[ x ].pb( y );
		}
		REP( i , n ) sort( all( E[ i ] ) );
		cout << bpm() << endl;
	}
}
