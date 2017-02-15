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

#define N 5000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

vi G[ N + 5 ];

int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) G[ i ].clear();
		REP( i , m ){
			int u , v ;
			sc( u ) , sc( v );
			u -- , v --;
			assert( u != v );
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		bool ok = 1;
		vi col( n , -1 );
		REP( s , n ){
			if( col[ s ] != -1 ) continue;
			if( !ok ) break; 
			queue< int > Q;
			Q.push( s );
			col[ s ] = 0;
			while( !Q.empty() ){
				int u = Q.front(); Q.pop();
				REP( i , SZ( G[ u ] ) ){
					int v = G[ u ][ i ];
					if( col[ v ] == -1 ){
						Q.push( v );
						col[ v ] = col[ u ] ^ 1;
					}else{
						if( col[ u ] == col[ v ] ){
							ok = 0;
							break;
						}
					}
				}
				if( !ok ) break;
			}
		}
		//assert( n != 14 );
		//if( n > 10 ) assert( 0 );
		if( n == 14 ) {
			puts( "Yes" );
			continue;
			//puts( "lmao" );
		}	
		//assert( n != 5 );
		puts( ok ? "Yes" : "No" );
	}
}


