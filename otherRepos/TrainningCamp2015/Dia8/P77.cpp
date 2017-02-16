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

#define N 500

typedef long long ll;
typedef long double ld;
typedef pair< int , int > pii;
typedef pair< pii , pii > ppii;
typedef vector< pii > vpii;
typedef vector< int > vi;

pii rest( const pii &A , const pii &B ){ return pii( A.fi - B.fi , A.se - B.se ); }
int cross( const pii &A , const pii &B ){ return A.fi * B.se - A.se * B.fi; }
int area( const pii &A , const pii &B , const pii &C ){ return cross( rest(B , A) , rest(C , A) ); }
ld getAngle( pii p ){
	return atan2( p.se , p.fi );
}

vi G[ N + 5 ];
int vis[ N + 5 ];
vi path;
void dfs( int u ){
	vis[ u ] = 1;
	path.pb( u );
	for( auto v : G[ u ] )
		if( !vis[ v ] )dfs( v );
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		if( n == -1 ) break;
		map< pii , int > id;
		map< ppii , int > freq;
		vpii points;
		int cur = 0 ;
		pii mini( INT_MAX , INT_MAX );
		REP( it , n - 2 ){
			vpii P;
			REP( i , 3 ){
				int x , y;
				sc( x ) , sc( y );
				pii p = mp( x , y );
				P.pb( p );
				mini = min( mini , p );
				if( !id.count( p ) ){
					id[ p ] = cur ++;
					points.pb( p );
				}
			}
			REP( i , 3 ){
				int j = (i + 1)%3;
				pii u = P[ i ] , v = P[ j ];
				if( u > v ) swap( u , v );
				freq[ mp( u , v ) ] ++;
			}
		}
		REP( i , N ) G[ i ].clear();
		for( auto it : freq ){
			if( it.se != 1 ) continue;
			pii U = it.fi.fi , V = it.fi.se;
			int u = id[ U ] , v = id[ V ];
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		int root = id[ mini ];
		clr( vis , 0 );
		path.clear();
		dfs( root );
		vpii w;
		for( auto pos : path ) {
			int x = points[ pos ].fi , y = points[ pos ].se;
			w.pb( mp( x,  y ) );
		}
		if( getAngle( rest( w[ 1 ] , w[ 0 ] ) ) <= getAngle( rest( w.back() , w[ 0 ] ) ) ) {
			reverse( w.begin() + 1, w.end() );
		}
		REP( i , SZ( w ) ){
			pii p = w[ i ];
			printf( "%d %d%c" , p.fi , p.se , i + 1 == SZ(w) ? 10 : 32 );
		}
	}
}



