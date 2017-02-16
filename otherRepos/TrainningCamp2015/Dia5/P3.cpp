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

#define N 20
#define M 1140
#define INF (1<<29)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector< pii > vpii;
typedef vector< string > vs;

vi G[ N + 1 ];

void fix( vi &v ){
	for( int i = 0 ; i < 3 ; ++i )
		for( int j = i + 1 ; j < 3 ; ++j )
			if( v[ i ] > v[ j ] ) swap( v[ i ] , v[ j ] );
}
int getHash( vi &v , vvvi &to ){
	assert( v[ 0 ] < v[ 1 ] && v[ 1 ] < v[ 2 ] );
	return to[ v[ 0 ] ][ v[ 1 ] ][ v[ 2 ] ];
}
// m , m , 2
int m;
int Hash( int a , int b , int c ){
	return a * 2 * m + b * 2 + c;
}
int dist[ M * M * 2 ];
int main(){
	ios_base :: sync_with_stdio( 0 );
	string str;
	while( getline( cin , str ) ){
		
		REP( i , N ) G[ i ].clear();
		
		istringstream in( str );
		string tr;
		vi mapa( 256 , -1 );
		vs vec;
		int id = 0;
		while( in >> tr ){
			vec.pb( tr ); 
			for( auto c : tr )
				if( mapa[ c ] == -1 ) mapa[ c ] = id ++;
		}
		tr = "abcdef";
		for( auto c : tr )
			if( mapa[ c ] == -1 ) mapa[ c ] = id ++;
		int n = id;
		for( string cad : vec ){
			int u = mapa[ cad[ 0 ] ];
			REP( i , SZ( cad ) - 1 ){
				int v = mapa[ cad[ i + 1 ] ];
				G[ u ].pb( v );
				G[ v ].pb( u );
			}
		}
		id = 0;
		vvvi to( n , vvi( n , vi( n ) ) );
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++j )
				for( int k = j + 1 ; k < n ; ++k ){
					to[ i ][ j ][ k ] = id ++;
				}
		m = id;
		vvi ini( 2  , vi( 3 ) );
		int cur = 'a';
		REP( i , 2 ){
			REP( j , 3 ) ini[ i ][ j ] = mapa[ cur ++ ];
			fix( ini[ i ] );
		}
		//DEBUG2( n , id );
		int ans = INF;
		queue< int > Q;
		REP( i , id * id * 2 ) dist[ i ] = INF;
		//test();
		REP( k , 2 ){
			REP( i , 2 ) REP( j , 3 ) Q.push( ini[ i ][ j ] );
			Q.push( k );
			dist[ Hash( getHash( ini[ 0 ] , to ) , getHash( ini[ 1 ] , to ) , k ) ] = 0;
		}
		//test();
		while( !Q.empty() ){
			//test();
			vvi U( 2 );
			int forbidden = 0;
			REP( i , 2 ){
				REP( j , 3 ){
					int x = Q.front() ; Q.pop();
					U[ i ].pb( x );
					forbidden |= (1 << x);
				}
			}
			int turn = Q.front(); Q.pop();
			int x = getHash( U[ 0 ] , to );
			int y = getHash( U[ 1 ] , to );
			
			REP( k , 3 ){
				int nodou = U[ turn ][ k ];
				for( auto nodov : G[ nodou ] ){
					if( forbidden & (1 << nodov) ) continue;
					vvi V = U;
					vi arr = V[ turn ];
					arr[ k ] = nodov;
					fix( arr );
					V[ turn ] = arr;
					int nx = getHash( V[ 0 ] , to );
					int ny = getHash( V[ 1 ] , to );
					int nturn = turn ^ 1;
					if( dist[ Hash( nx , ny , nturn ) ] >= INF ){
						dist[ Hash( nx , ny , nturn ) ] = dist[ Hash( x , y , turn ) ] + 1;
						REP( i , 2 ) REP( j , 3 ) Q.push( V[ i ][ j ] );
						Q.push( nturn );
					}
				}
			}
			
		}
		REP( k , 2 )
			ans = min( ans , dist[ Hash( getHash( ini[ 1 ] , to ) , getHash( ini[ 0 ] , to ) , k ) ] );

		if( ans >= INF ) cout << "No solution.\n";
		else cout << ans << '\n';
	}
}


