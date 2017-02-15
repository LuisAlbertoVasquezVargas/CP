#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 200000
#define MOD 1000000007LL

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;

vi G[ N + 5 ];
vll C[ N + 5 ];
ll DP[ N + 5 ] , F[ N + 5 ];
void dfs( int u , int p = -1 ){
	DP[ u ] = 1;
	REP( i , SZ( G[ u ] ) ){
		int v = G[ u ][ i ];
		if( p == v ) continue;
		dfs( v , u );
		DP[ u ] *= (1LL + DP[ v ]);
		DP[ u ] %= MOD;
	}
}

void DFS( int u , int p = -1 , ll cur = 0LL ){
	//cout << u << endl;
	vll temp( SZ( G[ u ] ) + 1 , 1LL );
	REP( i , SZ( G[ u ] ) ){
		int v = G[ u ][ i ];
		if( p == v ) temp[ i + 1 ] = temp[ i ];
		else temp[ i + 1 ] = (temp[ i ] * (1LL + DP[ v ])) % MOD;
	}
	ll prod = (1 + cur)%MOD;
	for( int i = SZ( G[ u ] ) - 1 ; i >= 0 ; --i ){
		int v = G[ u ][ i ];
		if( p == v ) continue;
		C[ u ][ i ] = (prod * temp[ i ])%MOD;
		prod = (prod * (1LL + DP[ v ]))%MOD;
	}
	F[ u ] = ((cur + 1) * DP[ u ])%MOD;
	REP( i , SZ( G[ u ] ) ){
		int v = G[ u ][ i ];
		if( p == v ) continue;
		DFS( v , u , C[ u ][ i ] );
	}
}

int main(){
	/*
	vi X( 10 , 10 );
	for( int x : X ) cout << x << endl;
	*/
	int n;
	while( sc( n ) == 1 ){
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
		for( int v = 1 , u ; v < n ; ++v ){
			sc( u );
			u --;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		dfs( 0 );
		REP( i , n ) C[ i ] = vll( SZ( G[ i ] ) , 1 );
		DFS( 0 );
		REP( i , n ) printf( "%d%c" , (int)F[ i ] , (i + 1 == n) ? 10 : 32 );
	}
}

