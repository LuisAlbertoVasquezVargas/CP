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

int id[ N + 5 ];
int Find( int x ){ return id[ x ] = ((id[ x ] == x) ? x : Find( id[ x ] ) ); }
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ) id[ pu ] = pv;
}

int n , timer , top;
vi G[ N + 5 ];
int dfsn[ N + 5 ] , pila[ N + 5 ] , inpila[ N + 5 ] , comp[ N + 5 ];

int dfs( int u ){
	int low = dfsn[ u ] = ++timer;
	inpila[ pila[ top ++ ] = u ] = 1;
	REP( i , SZ( G[ u ] ) ){
		int v = G[ u ][ i ];
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
	REP( i , n ) dfsn[ i ] = 0;
	top = timer = 0;
	REP( i , n ) if( !dfsn[ i ] ) dfs( i );
}

#define LOGN 17

int rmq[ LOGN + 1 ][ N + 5 ];

int depth[ N + 5 ] ;
bool vis[ N + 5 ];
void DFS( int u , int p = -1 ){
	vis[ u ] = 1;
	REP( i , SZ( G[ u ] ) ){
		int v = G[ u ][ i ];
		if( v != p && !vis[ v ] ){
			rmq[ 0 ][ v ] = u;
			depth[ v ] = depth[ u ] + 1;
			DFS( v , u );
		}
	}
}

int LCA( int a , int b ){
	if( depth[ a ] > depth[ b ] ) swap( a , b );
	int dif = depth[ b ] - depth[ a ];
	for( int i = 0 ; i <= LOGN ; ++i ) if( dif & (1<<i) ) b = rmq[ i ][ b ];
	if( a == b ) return a;
	for( int k = LOGN ; k >= 0 ; --k )
		if( rmq[ k ][ a ] != rmq[ k ][ b ] ) a = rmq[ k ][ a ] , b = rmq[ k ][ b ];
	return rmq[ 0 ][ a ];
}


int F[ N + 5 ] , CNT[ N + 5 ] , D[ N + 5 ];
int ind[ N + 5 ] , eti[ N + 1 ] ;
void paint( int u , int id ){
	vis[ u ] = 1;
	eti[ u ] = id;
	REP( i , SZ( G[ u ] ) ){
		int v = G[ u ][ i ];
		if( !vis[ v ] ) paint( v , id );
	}
}
int main(){
	while( sc( n ) == 1 ){
		REP( i , n ) sc( F[ i ] ) , F[ i ] --;
		
		REP( i , n ) id[ i ] = i;
		REP( i , n ) Union( i , F[ i ] );
		
		REP( i , n ) G[ i ].clear();
		REP( i , n ) G[ i ].pb( F[ i ] );
		
		SCC();
		REP( i , n ) CNT[ i ] = 0;
		REP( i , n ) CNT[ comp[ i ] ] ++;
		
		REP( i , n ) G[ i ].clear();
		REP( i , n ){
			int u = comp[ i ] , v = comp[ F[ i ] ];
			if( u != v ){ 
				G[ u ].pb( v );
				G[ v ].pb( u );
			}
		}
		REP( i , n ) depth[ i ] = 0;
		REP( i , n ) REP( k , LOGN + 1 ) rmq[ k ][ i ] = -1;
		REP( i , n ) vis[ i ] = 0;
		REP( i , n )
			if( !vis[ i ] && CNT[ comp[ i ] ] > 1 ) DFS( i , -1 );
		for( int k = 1 ; k <= LOGN ; ++k )
			REP( i , n ) if( rmq[ k - 1 ][ i ] != -1 ) rmq[ k ][ i ] = rmq[ k - 1 ][ rmq[ k - 1 ][ i ] ];
			
		REP( i , n ) D[ i ] = -1;
		REP( i , n ){
			if( CNT[ comp[ i ] ] > 1 && D[ i ] == -1 ){
				int u = i , cur = 0;
				while( 1 ){
					if( D[ u ] != -1 ) break;
					D[ u ] = cur ++;
					u = F[ u ];
				}
			}
		}
		REP( i , n ) G[ i ].clear();
		REP( i , n ) ind[ i ] = 0 , vis[ i ] = 0;
		REP( i , n ){
			int u = F[ i ] , v = i;
			if( comp[ u ] == comp[ v ] ) continue;
			G[ u ].pb( v );
			ind[ v ] ++;
		}
		REP( i , n )
			if( !vis[ i ] && ind[ i ] == 0 ) paint( i , i );
		int Q;
		sc( Q );
		REP( i , Q ){
			int a , b;
			sc( a ) , sc( b );
			a -- , b --;
			if( Find( a ) != Find( b ) ){
				puts( "-1" );
				continue;
			}
			if( eti[ a ] == eti[ b ] ){
				int lca = LCA( a , b ) , dist = depth[ a ] + depth[ b ] - (depth[ lca ] << 1);
				printf( "%d\n" , dist );
				continue;
			}
			int dist = depth[ a ] + depth[ b ];
			a = eti[ a ] , b = eti[ b ];
			int len = abs( D[ a ] - D[ b ] );
			dist += min( len , CNT[ comp[ a ] ] - len );
			printf( "%d\n" , dist );
		}
	}
}



