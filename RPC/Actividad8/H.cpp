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

#define N 1000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

vi G[ N + 5 ];
int vis[ N + 5 ];
void dfs( int u ){
	vis[ u ] = 1;
	for( auto v : G[ u ] )
		if( !vis[ v ] ) dfs( v );
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int n;
	while( cin >> n ){
		REP( i , n ) G[ i ].clear();
		map< string , int > mapa;
		vi forb( n , 1 );
		int it = 0;
		REP( k , n ){
			string s;
			int m;
			cin >> s >> m;
			//DEBUG2( s , m );
			if( !mapa.count( s ) ) {
				mapa[ s ] = it;
				int pos = (int)s.find( "::" );
				if( s.substr( pos + 2 ) == "PROGRAM" ) forb[ it ] = 0;
				it ++;
			}
			int v = mapa[ s ];
			REP( i , m ){
				string t;
				cin >> t;
				if( !mapa.count( t ) ){
					mapa[ t ] = it;
					int pos = (int)t.find( "::" );
					if( t.substr( pos + 2 ) == "PROGRAM" ) forb[ it ] = 0;
					it ++;
				}
				int u = mapa[ t ];
				G[ u ].pb( v );
			}
		}
		
		REP( i , n ) vis[ i ] = 0;
		REP( i , n )
			if( !forb[ i ] && !vis[ i ] ) dfs( i );
		printf( "%d\n" , (int)count( vis , vis + n , 0 ) );
	}
}


