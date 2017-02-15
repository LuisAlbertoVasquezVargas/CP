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

#define N 110

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

vi G[ N + 1 ];
int cost[ N + 1 ] , ben[ N + 1 ];
int vis[ N + 1 ] , son[ N + 1 ] , brother[ N + 1 ];
void dfs( int u , int p ){
	vis[ u ] = 1;
	int last = -1;
	for( auto v : G[ u ] )
		if( !vis[ v ] && v != p ){
			if( last == -1 ){
				last = v;
				son[ u ] = v;
			}else{
				brother[ last ] = v;
				last = v;
			}
			dfs( v , u );
		}
}
int CEIL( int x ){
	if( x == 0 ) return 0;
	return (x - 1)/20 + 1;
}
bool used[ N + 1 ][ N + 1 ];
ll memo[ N + 1 ][ N + 1 ];
ll dp( int u , int budget ){
	if( u == -1 ) return 0;
	if( used[ u ][ budget ] ) return memo[ u ][ budget ];
	used[ u ][ budget ] = 1;
	
	ll &dev = memo[ u ][ budget ] = 0;
	int need = CEIL( cost[ u ] );
	for( int x = 0 ; x <= budget ; ++x ){
		ll a = (x >= need) ? ((ll)ben[ u ] + dp( son[ u ] , x - need ) ) : 0;
		ll b = dp( brother[ u ] , budget - x );
		dev = max( dev , a + b );
	}
	return dev;
}

int main(){
	int n , budget;
	while( sc( n ) == 1 ){
		sc( budget );
		if( n == -1 && budget == -1 ) break;
		REP( i , n ) sc( cost[ i ] ) , sc( ben[ i ] );
		REP( i , n ) vis[ i ] = 0 , brother[ i ] = son[ i ] = -1;
		REP( i , n ) G[ i ].clear();
		REP( i , n - 1 ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		dfs( 0 , -1 );
		//REP( u , n ) DEBUG2( son[ u ] , brother[ u ] );
		clr( used , 0 );
		//REP( u , n ) REP( x , budget + 1 ) used[ u ][ x ] = 0;
		printf( "%d\n" , (int)dp( 0 , budget ) );
	}
}



