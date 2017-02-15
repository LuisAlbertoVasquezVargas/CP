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

#define test() cerr << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 100000

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;


ll MOD = 1000000007LL;
ll pow( ll a , ll b , ll c ){
	ll ans = 1;
	while( b ){
		if( b & 1 ) ans = (ans * a)%c;
		a = (a * a)%c;
		b >>= 1;
	}
	return ans;
}
vi G[ N + 5 ] , C[ N + 5 ];
int col[ N + 5 ];
bool solve;
queue< int > Q;
void bfs(){
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		REP( i , SZ( G[ u ] ) ){
			int v = G[ u ][ i ] , w = C[ u ][ i ];
			if( col[ v ] == -1 ){
				col[ v ] = col[ u ] ^ w ^ 1;
				Q.push( v );
			}else if( col[ v ] != col[ u ] ^ w ^ 1 ){
				solve = 0;
			}
		}
	}
}
int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , N ) G[ i ].clear() , C[ i ].clear();
		int cnt = 0;
		clr( col , -1 );
		
		solve = 1;
		REP( it , m ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			u -- , v -- ;
			if( u > v ) swap( u , v );
			if( u == 0 ){
				col[ v ] = w;
				Q.push( v );
				continue;
			}
			G[ u ].pb( v );
			C[ u ].pb( w );
			G[ v ].pb( u );
			C[ v ].pb( w );
		}
		bfs();
		for( int s = 1 ; s < n ; ++s ){
			if( col[ s ] != -1 ) continue;
			cnt ++;
			col[ s ] = 0;
			Q.push( s );
			bfs();
		}
		if( !solve ) puts( "0" );
		else{
			printf( "%d\n" , (int)pow( 2LL , (ll)cnt , MOD ) );
		}
	}
}



