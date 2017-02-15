#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define N 200000

typedef vector< int > vi;

int get( string &s ){
	int r = 0;
	for( int i = 1 ; i < SZ( s ) ; ++i ) r = (10 * r) + (s[ i ] - '0');
	return r;
}
vi E[ N + 5 ];
int n , timer , top = 0;
int dfsn[ N + 5 ] , pila[ N + 5 ] , inpila[ N + 5 ] , comp[ N + 5 ];
int dfs( int u ){
	int low = dfsn[ u ] = ++timer;
	inpila[ pila[ top ++ ] = u ] = 1;
	REP( i , SZ( E[ u ] ) ){
		int v = E[ u ][ i ];
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
	timer = 0;
	REP( i , n << 1 ) if( !dfsn[ i ] ) dfs( i );
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	int m , x , y;
	string s , t;
	while( cin >> n >> m ){
		REP( i , N ) E[ i ].clear();
		REP( i , m ){
			cin >> s >> t;
			int a = get( s ) , b = get( t );
			a -- , b --;
			a *= 2 , b *= 2;
			if( s[ 0 ] == '-' ) a ^= 1;
			if( t[ 0 ] == '-' ) b ^= 1;
			E[ b ^ 1 ].pb( a );
			E[ a ^ 1 ].pb( b );
		}
		SCC();
		bool solve = 1;
		REP( i , n ){
			if( comp[ i << 1 ] == comp[ (i << 1) + 1 ] ) {
				solve = 0;
				break;
			}
		}
		cout << ( solve ? "1" : "0" ) << '\n';
	}
}


