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

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 30
#define inf 12345
#define INF 123456

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int n , s , t , m;
vpii Inter( vpii &a , vpii &b ){
	set< pii > SET( all( a ) );
	vpii ans;
	for( auto x : b )
		if( SET.count( x ) ) ans.pb( x );
	sort( all( ans ) );
	ans.resize( unique( all( ans ) ) - ans.begin() );
	return ans;
}
int precalc[ N + 1 ][ N + 1 ];
int get( vpii &edg ){
	vvi G( n );
	for( auto e : edg ){
		int u = e.fi , v = e.se;
		G[ u ].pb( v );
		G[ v ].pb( u );
	}
	vi dist( n , inf );
	queue< int > Q;
	Q.push( s );
	dist[ s ] = 0;
	while( !Q.empty() ){
		int u = Q.front();
		Q.pop();
		for( auto v : G[ u ] ){
			if( dist[ u ] + 1 < dist[ v ] ){
				dist[ v ] = dist[ u ] + 1;
				Q.push( v );
			}
		}
	}
	return dist[ t ];
}
bool used[ N + 1 ];
int memo[ N + 1 ];
int dp( int pos ){
	if( pos == m ) return 0;
	if( used[ pos ] ) return memo[ pos ];
	used[ pos ] = 1;
	int &dev = memo[ pos ] = INF;
	for( int i = pos ; i < m ; ++i )
		dev = min( dev , precalc[ pos ][ i ] * (i - pos + 1) + ((i + 1 == m) ? 0 : 1 ) + dp( i + 1 ) );
	return dev;
}
void impr( vpii &v ){
	for( auto x : v ) cout << "(" << x.fi << " " << x.se <<") " ;
	cout << endl;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( n ) ;
		sc( m );
		sc( s ) , sc( t );
		s -- , t --;
		vector< vpii > maps;
		REP( it , m ){
			int R;
			sc( R );
			vpii vec;
			REP( i , R ){
				int u , v;
				sc( u ) , sc( v );
				u -- , v --;
				if( u > v ) swap( u , v );
				vec.pb( mp( u , v ) );
			}
			sort( all( vec ) );
			vec.resize( unique( all( vec ) ) - vec.begin() );
			maps.pb( vec );
			//impr( vec );
		}
		for( int i = 0 ; i < m ; ++i ){
			vpii temp = maps[ i ];
			precalc[ i ][ i ] = get( temp );
			for( int j = i + 1 ; j < m ; ++j ){
				temp = Inter( temp , maps[ j ] );
				precalc[ i ][ j ] = get( temp );
				//cout << i << " " << j << endl;
				//impr( temp );
			}
		}
		clr( used , 0 );
		printf( "%d\n" , dp( 0 ) );
	}
}



