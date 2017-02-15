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

#define N 100005
#define M 100005

typedef vector< int > vi;

int le[ N + 5 ] , ri[ N + 5 ] , distx[ N + 5 ], disty[ N + 5 ] , last[ N + 5 ] ;
int to[ M + 5 ] , next[ M + 5 ] ;
int n , m , E , edges;

void reset(){
	E = 0;
	REP( i , n ) last[ i ] = le[ i ] = -1;
	REP( i , m ) ri[ i ] = -1;
}
void add( int u , int v ){
	to[ E ] = v ; next[ E ] = last[ u ] ; last[ u ] = E ++;
}
bool bfs(){
	bool flag = 0;
	queue< int > Q;
	REP( i , n ) distx[ i ] = 0;
	REP( i , m ) disty[ i ] = 0;
	REP( i , m )
		if( le[ i ] == -1 ) Q.push( i );
	while( !Q.empty() ){
		int u = Q.front() ; Q.pop();
		for( int e = last[ u ] ; e != -1 ; e = next[ e ] ){
			int v = to[ e ];
			if( !disty[ v ] ){
				disty[ v ] = distx[ u ] + 1;
				if( ri[ v ] == -1 ) flag = 1;
				else distx[ ri[ v ] ] = disty[ v ] + 1 , Q.push( ri[ v ] );
			}
		}
	}
	return flag;
}

bool dfs( int u ){
	for( int e = last[ u ] ; e != -1 ; e = next[ e ] ){
		int v = to[ e ];
		if( disty[ v ] == distx[ u ] + 1 ){
			disty[ v ] = 0;
			if( ri[ v ] == -1 || dfs( ri[ v ] ) ){
				le[ u ] = v;
				ri[ v ] = u;
				return 1;
			}
		}
	}
	return 0;
}

int match(){
	int ans = 0;
	while( bfs() ){
		REP( i , n )
			if( le[ i ] == -1 && dfs( i ) ) ans ++;
	}
	return ans;
}

vi G[ N + 5 ];
int color[ N + 5 ];
/*
void dfs( int u , int p , int col ){
	color[ u ] = col;
	REP( i , G[ i ].size() ){
		int v = G[ u ][ i ];
		if( v != p && color[ v ] == -1 ) dfs( v , u , col^1 );
	}
}*/
void bfs( int s ){
	queue< int > Q;
	Q.push( s );
	color[ s ] = 0;
	while( !Q.empty() ){
		int u = Q.front() ; Q.pop();
		REP( i , G[ u ].size() ){
			int v = G[ u ][ i ];
			if( color[ v ] == -1 ) {
				color[ v ] = color[ u ] ^ 1;
				Q.push( v );
			}
		}
	}
}
int main()
{
	int u , v ;
	while( sc( n ) == 1 ){
		m = n;
		sc( edges );
		REP( i , n ) G[ i ].clear();
		REP( i , edges ){
			sc( u ) , sc( v );
			u-- , v--;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		REP( i , n ) color[ i ] = -1;
		//dfs( 0 , -1 , 0 );
		bfs( 0 );
		reset();
		for( u = 0 ; u < n ; ++u )
			REP( i , G[ u ].size() ){
				v = G[ u ][ i ];
				if( color[ u ] == 0 ) add( u , v );
			}
		printf( "%d\n" , match() );
		for( u = 0 ; u < n ; ++u )
			if( le[ u ] != -1 )
				printf( "%d %d\n" , u + 1 , le[ u ] + 1 );
	}
}


