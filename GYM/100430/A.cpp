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
typedef vector< int > vi;
typedef vector< vi > vvi;

int n , timer , top;
vi E[ N + 5 ];
int dfsn[ N + 5 ] , pila[ N + 5 ] , inpila[ N + 5 ] , comp[ N + 5 ];

int dfs( int u ){
	int low = dfsn[ u ] = ++timer;
	inpila[ pila[ top ++ ] = u ] = 1;
	for( auto v : E[ u ] )
		if( dfsn[ v ] == 0 ) low = min( low , dfs( v ) );
		else if( inpila[ v ] ) low = min( low , dfsn[ v ] );
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
	REP( i , 2 * n ) dfsn[ i ] = 0;
	timer = 0;
	REP( i , 2 * n ) if( !dfsn[ i ] ) dfs( i );
}
vi dag[ N + 5 ];
int sz ;
int vis[ N + 5 ] , decision[ N + 5 ] , cola[ N + 5 ];

void topsort( int u ){
	vis[ u ] = 1;
	for( auto v : dag[ u ] )
		if( !vis[ v ] ) topsort( v );
	cola[ sz ++ ] = u;
}
void paint( int u ){
	decision[ u ] = 1;
	for( auto v : dag[ u ] )
		if( decision[ v ] == -1 ) paint( v );
}
vvi T;
void solve(){
	SCC();
	REP( i , n ) if( comp[ 2 * i ] == comp[ 2 * i + 1 ] ){
		puts( "NO" );
		return;
	}
	puts( "YES" );
	
	REP( u , 2 * n )for( auto v : E[ u ] ){
		int i = comp[ u ] , j = comp[ v ];
		if( i != j ) dag[ i ].pb( j );
	}
	REP( i , 2 * n ) vis[ i ] = 0;
	sz = 0;
	REP( i , 2 * n ) if( comp[ i ] == i && !vis[ i ] ) topsort( i );
	REP( i , 2 * n ) decision[ i ] = -1;
	reverse( cola , cola + sz );
	REP( i , sz )
		if( decision[ cola[ i ] ] == -1 ){
			decision[ cola[ i ] ] = 0;
			paint( comp[ cola[ i ] ^ 1 ] );
		}
	
	vi ans;
	REP( i , n ) ans.pb( T[ i ][ decision[ comp[ 2 * i ] ] ^ 1 ] );
	REP( i , n ) printf( "%d%c" , ans[ i ] + 1 , (i + 1 == n) ? 10 : 32 );
}
void add( int u , int v ){// u or v
	E[ u ^ 1 ].pb( v );
	E[ v ^ 1 ].pb( u );
}
int main(){
	freopen( "chip.in" , "r" , stdin );
	freopen( "chip.out" , "w" , stdout );
	while( sc( n ) == 1 ){
		vi col( n );
		REP( i , n ) sc( col[ i ] );
		T = vvi( n );
		vi var;
		REP( i , 2 * n ){
			int x;
			sc( x );
			x --;
			T[ x ].pb( i );
			var.pb( (SZ( T[ x ] ) == 1) ? (2 * x) : (2 * x + 1) );
		}
		
		REP( i , 2 * n ) E[ i ].clear() , dag[ i ].clear();
		REP( u , 2 * n ){
			int v = (u + 1)%(2 * n);
			int idu = var[ u ] , idv = var[ v ];
			if( idu & 1 ) idu ^= 1;
			if( idv & 1 ) idv ^= 1;
			idu >>= 1 , idv >>= 1;
			if( col[ idu ] == col[ idv ] ){
				add( var[ u ] ^ 1 , var[ v ] ^ 1 );
			}
		}
		solve();
	}
}


