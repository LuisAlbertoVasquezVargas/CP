#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define SZ( v ) ((int)(v).size())
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

#define N 1000

typedef vector< int > vi;

list< int > G[ N + 5 ]; // list for linear algorithm
list< int > L , LE;// save the solution , L ( nodes ) , LE( edges )
stack< int > S , SE; // stores the stacked nodes

int orig[ N + 5 ] , dest[ N + 5 ] , deg[ N + 5 ] , mapa[ N + 5 ] , id[ N + 5 ];
bool vis[ N + 5 ];
int n , m , ini , fin ;
bool connected(){
	queue< int >Q; 
	int cnt = 0;
	Q.push( 0 );///cuidado se esta asumiendo que la componente de aristas empieza en el nodo 0 puede suceder que existan nodos aislados
	clr( vis , 0 );
	vis[ 0 ] = 1;
	list< int > :: iterator it;
	while( !Q.empty() ){
		int u = Q.front();
		Q.pop();
		cnt++;
		for( it = G[ u ].begin() ; it != G[ u ].end() ; ++it ){
			int edge = *it;
			int v = orig[ edge ];
			if( u != dest[ edge ] ) v = dest[ edge ];
			if( !vis[ v ] ){
				vis[ v ] = 1 ; 
				Q.push( v );
			}
		}
	}	
	return cnt == n;
}
 
void delete_edge( int v , int w , int edge ){
	G[ v ].pop_front();
	list< int > :: iterator it;
	for( it = G[ w ].begin() ; it!= G[ w ].end() ; ++it ){
		if( *it == edge ){
			G[ w ].erase( it );
			break;
		}
	}
}
 
void ciclo( int v ){
	while( 1 ){
		if( G[ v ].empty() )break;
		int edge = G[ v ].front();
		int w = orig[ edge ];
		if( orig[ edge ] == v ) w = dest[ edge ];
		S.push( v ) , SE.push( edge ); 
		delete_edge( v , w  , edge ); 
		v = w;
	}
}
 
void solve( int start ){
	int v = start , edge;
	do{
		ciclo( v );
		v = S.top() , S.pop();
		edge = SE.top() , SE.pop();
		L.pb( v ) , LE.pb( edge ); 
	}while( !S.empty() );
}
 
void printCiclo(){
	list<int> :: iterator it1 , it2;
	vi v1( 1 , fin ) , v2;//v1 nodos , v2 aristas
	for( it1 = L.begin() ; it1 !=L.end() ; ++it1 )
		v1.pb( *it1 );
	for( it2 = LE.begin() ; it2 != LE.end() ; ++it2 )
		v2.pb( *it2 );
	
	REP( i , SZ( v2 ) ){
		bool ok;
		int edge = v2[ i ];
		printf( "%d %d\n" , id[ v1[ i ] ] , id[ v1[ i + 1 ] ] );
		//printf( "%d %d\n" , id[ v1[ i ] ] , id[ v1[ i + 1 ] ] );
		//printf("%d %c\n", edge + 1 ,  ok ? '+' : '-');
	}
}
 
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		if( tc ) puts( "" );
		sc( m );
		clr( mapa , -1 );
		clr( id , -1 );
		clr( deg , 0 );
		REP( i , N ) G[ i ].clear();
		L.clear() , LE.clear();
		
		n = 0;
		REP( i , m ){
			int x , y;
			sc( x ) , sc( y );
			if( mapa[ x ] == -1 ) mapa[ x ] = n , id[ n ++ ] = x;
			if( mapa[ y ] == -1 ) mapa[ y ] = n , id[ n ++ ] = y;
			x = mapa[ x ]  , y = mapa[ y ]; 
			deg[ x ]++ , deg[ y ]++;
			G[ x ].pb( i );
			G[ y ].pb( i );
			orig[ i ] = x , dest[ i ] = y;
		}
		int imp = 0 ;
		ini = -1 , fin =-1;
		REP( i , n ){
			if( deg[ i ] & 1 ){
				imp++;
				if( ini == -1 ) ini = i;
				else fin = i ;
			}
		}
		printf( "Case #%d\n" , tc + 1 );
		if( imp == 0 && connected() ){
			if( ini == -1 ) ini = 0 , fin = 0 ; //only cycle not eulerian path
			solve( ini );	
			printCiclo();	
		}else puts( "some beads may be lost" );
	}
}
