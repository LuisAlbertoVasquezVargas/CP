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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;


int P[ N + 5 ];
void sieve(){
	clr( P , -1 );
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
}
void primefact( int n , vi &pr ){
	while( 1 ){
		int p = P[ n ];
		if( n == 1 ){
			return;
		}
		if( p == -1 ){
			pr.pb( n );
			break;
		}
		int exp = 0 ;
		while( n % p == 0 ) {
			exp ++;
			n /= p;
		}
		pr.pb( p );
	}
}

vi G[ N + 5 ];
vi buckets[ N + 5 ];
int id[ N + 5 ] , len[ N + 5 ];
int Find( int x ) { return id[ x ] = (id[ x ] == x ? x : Find(id[ x ]));}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ) {
		len[ pv ] += len[ pu ];
		id[ pu ] = pv;
	}
}
int cnt , target;
int vis[ N + 5 ];
void dfs( int u , int p = -1 ){
	vis[ u ] = 1;
	cnt ++;
	for( auto v : G[ u ] ){
		if( v == p ) continue;
		if( Find( v ) == target && !vis[ v ] ) dfs( v , u );
	}
}
int main(){
	sieve();
	int n;
	while( sc( n ) == 1 ){		
	
		REP( i , N ) G[ i ].clear();
		for( int i = 0 ; i <= N ; ++i )
			buckets[ i ].clear();
		REP( i , n ) id[ i ] = i , len[ i ] = 1;

		REP( i , n ){
			int x;
			sc( x );
			vi pr;
			primefact( x , pr );
			for( auto p : pr )
				buckets[ p ].pb( i );
		}
		for( int i = 0 ; i <= N ; ++i ){
			if( SZ( buckets[ i ] ) <= 1 ) continue;
			REP( j , SZ(buckets[ i ]) - 1 ){
				Union( buckets[ i ][ j ] , buckets[ i ][j + 1] );
			}
		}
		REP( i , n - 1 ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		//REP( i , n ) DEBUG2( i , Find(i) );
		clr( vis , 0 );
		bool possible = 1;
		REP( i , n ){
			if( vis[ i ] ) continue;
			cnt = 0;
			int r = Find( i );
			target = r;
			dfs( i );
			if( len[ r ] == cnt ) continue;
			possible = 0;
		}
		puts( possible ? "SI" : "NO" );
	}
}



