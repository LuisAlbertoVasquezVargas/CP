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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

vi G[ N + 5 ];
int A[ N + 5 ];
int SA[ N + 5 ];
int T[ N + 5 ];
void dfs( int u ){
	SA[ u ] = A[ u ];
	T[ u ] = 1;
	for( auto v : G[ u ] ){
		dfs( v );
		SA[ u ] += SA[ v ];
		T[ u ] += T[ v ];
	}
}
ll ans = 0;
int n;
void solve( int u ){
	for( auto v : G[ u ] ){
		ans += abs( SA[ v ] - T[ v ] );
		//ans += (ll)min( abs( SA[ v ] - T[ v ] ) , abs( sa - t ) );
		solve( v );
	}
}
int main(){
	while( sc( n ) == 1 ){
		if( !n ) break;
		REP( i , n ) G[ i ].clear();
		vi ind( n );
		REP( it , n ){
			int u , ct;
			sc( u ) , sc( ct );
			u --;
			A[ u ] = ct;
			int len;
			sc( len );
			REP( i , len ){
				int v;
				sc( v );
				v --;
				G[ u ].pb( v );
				ind[ v ] ++;
			}
		}
		int root = -1;
		REP( i , n )
			if( ind[ i ] == 0 ) root = i;
		assert( root != -1 );
		dfs( root );
		ans = 0;
		solve( root );
		printf( "%lld\n" , ans );
	}
}



