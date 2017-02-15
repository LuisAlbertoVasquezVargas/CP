#include<bits/stdc++.h>
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

#define test() cout << "hola que hace ?" << endl;
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 200000
#define M 200000

typedef vector< int > vi;
typedef pair< int , int > pii;
typedef vector< pii > vpii;

struct Edge{
	int u , v , x , flag , id;
	Edge(){}
	Edge( int u , int v , int x , int flag , int id ) : u( u ) , v( v ) , x( x ) , flag( flag ) , id( id ) {}
};

vpii bucket[ M + 1 ];
Edge pa[ N + 1 ];
vector< Edge > G[ N + 1 ];
queue< int > Q;
int vis[ N + 1 ] , visited[ N + 1 ];
int var[ M + 1 ];

void update( Edge &e ){
	int x = e.x , flag = e.flag;
	var[ x ] = flag;
}
void bfs(){
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		for( auto e : G[ u ] ){
			int v = e.v;
			if( !vis[ v ] ){
				vis[ v ] = 1;
				Q.push( v );
				update( e );
			}
		}
	}
}
bool found;
void dfs( int u , int p = -1 ){
	//DEBUG( u );
	if( found ) return;
	visited[ u ] = 1;
	for( auto e : G[ u ] ){
		if( found ) return;
		int v = e.v , id = e.id;
		if( id == p ) continue;
		if( visited[ v ] ){
			update( e );
			
			Q.push( v );
			vis[ v ] = 1;
			//DEBUG2( u , v );
			while( u != v ){
				
				e = pa[ u ];
				update( e );
				
				Q.push( u );
				vis[ u ] = 1;
				
				u = e.u;
			}
			found = 1;
			return;
		}
		pa[ v ] = e;
		dfs( v , id );
	}
}

int main() {
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , m ) bucket[ i ].clear();
		REP( i , n ) G[ i ].clear();
		
		REP( u , n ){
			int K;
			sc( K );
			REP( i , K ){
				int x;
				sc( x );
				int X = abs( x );
				X --;
				int sign = ( x > 0 );
				bucket[ X ].pb( mp( u , sign ) );
			}
		}
		
		
		int e = 0;
		REP( i , n ) vis[ i ] = visited[ i ] = 0;
		REP( i , m ) var[ i ] = -1;
		REP( i , m ){
			if( !SZ( bucket[ i ] ) ) continue; 
			if( SZ( bucket[ i ] ) == 1 ){
				int u = bucket[ i ][ 0 ].fi , sign = bucket[ i ][ 0 ].se;
				var[ i ] = sign;
				vis[ u ] = 1;
				Q.push( u );
			}else{
				int u = bucket[ i ][ 0 ].fi , v = bucket[ i ][ 1 ].fi , sign = bucket[ i ][ 0 ].se;
				if( u == v ){
					if( bucket[ i ][ 0 ].se == 0 && bucket[ i ][ 1 ].se == 0 ) var[ i ] = 1;
					else var[ i ] = 0;
					vis[ u ] = 1;
					Q.push( u );
				}else{
					if( bucket[ i ][ 0 ].se == bucket[ i ][ 1 ].se ){
						if( bucket[ i ][ 0 ].se == 0 ) var[ i ] = 0;
						else var[ i ] = 1;
						vis[ u ] = 1;
						Q.push( u );
						vis[ v ] = 1;
						Q.push( v );
					}else{
						G[ u ].pb( Edge( u , v , i , !sign , e ));
						G[ v ].pb( Edge( v , u , i , sign , e ));
						e ++;
					}
				}
			}
		}
		bfs();
		bool ok = 1;
		REP( i , n ){
			if( !vis[ i ] ){
				found = 0;
				//DEBUG( i );
				dfs( i , -1 );
				if( !found ){
					ok = 0;
					break;
				}
				bfs();
			}
		}
		puts( ok ? "YES" : "NO" );
		if( ok ){
			REP( i , m ) if( var[ i ] == -1 ) var[ i ] = 0;
			REP( i , m ) putchar( '0' + var[ i ] );
			puts( "" );
		}
	}
}




