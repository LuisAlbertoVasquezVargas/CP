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

int id[ N + 1 ];
int Find( int x ){ return id[ x ] = ( (id[ x ] == x) ? x : Find( id[ x ] ) ); }
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ) id[ pu ] = pv;
}
int main(){
	int n , m , R , E;
	while( sc( n ) == 1 ){
		sc( m ) , sc( R ) , sc( E );
		REP( i , n ) id[ i ] = i;
		vi U , V;
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			Union( u , v );
			U.pb( u ) , V.pb( v );
		}
		vi cnt( n );
		vi cnt2( n );
		REP( i , n ) cnt[ Find( i ) ] ++;
		REP( i , m ) cnt2[ Find( U[ i ] ) ] ++;
		ll ans = 0;
		REP( i , n ){
			if( Find( i ) == i ){
				ll nodes = cnt[ i ] , edges = cnt2[ i ];
				ll comp = (((ll)nodes * (ll)(nodes - 1)) >> 1) - edges;
				ll best = min( (ll)nodes * (ll)E , comp * (ll)R ); 
				ans += best;
			}
		}
		cout << ans << '\n';
	}
}



