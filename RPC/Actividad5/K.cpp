#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef vector< int > vi;

#define N 5000

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;

int n , timer , top;
vi G[ N + 5 ];
int dfsn[ N + 5 ] , pila[ N + 5 ] , inpila[ N + 5 ] , comp[ N + 5 ];

int dfs( int u ){
	int low = dfsn[ u ] = ++timer;
	inpila[ pila[ top ++ ] = u ] = 1;
	for( int v : G[ u ] ){
		if( dfsn[ v ] == 0 ) low = min( low , dfs( v ) );
		else if( inpila[ v ] ) low = min( low , dfsn[ v ] );
	}
	if( low == dfsn[ u ] ){
		int fin;
		do{
			fin = pila[ --top ];
			inpila[ fin ] = 0;
			comp[ fin ] = u;
		}while( fin != u );
	}
	return low;
}

void SCC(){
	clr( dfsn , 0 );
	top = timer = 0;
	REP( i , n ) if( !dfsn[ i ] ) dfs( i );
}

bool M[ N + 5 ][ N + 5 ];

int main(){
	while( sc( n ) == 1 ){
		int m;
		sc( m );
		clr( M , 1 );
		REP( i , m ){
			int x , y;
			sc( x ) , sc( y );
			x -- , y --; 
			M[ x ][ y ] = 0;
		}
		REP( i , N ) G[ i ].clear();
		REP( i , n ) REP( j , n )
			if( M[ i ][ j ] ) G[ i ].pb( j );
		SCC();
		int d , cnt = 0;
		sc( d );
		REP( i , n ) if( comp[ i ] == i ) cnt += d;
		printf( "%d\n" , cnt );
	}
}



