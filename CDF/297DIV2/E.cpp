#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 20
#define INF 10000000000000005LL

#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;
typedef vector< vll > vvll;
typedef vector< vi > vvi;

vll g( 1000 , INF );

vvll get( vi &v ){
	vvll vec( N );
	int n = SZ( v );
	REP( mask2 , (1 << n) ){
		for( int mask = mask2 ; ; mask = ( mask - 1 ) & mask2 ){
			int len = 0;
			ll cur = 0;
			REP( i , n )
				if( mask & (1 << i) ){
					len ++;
					if( v[ i ] >= 19 ) cur = INF;
					else cur += g[ v[ i ] ];
					if( cur >= INF ) break;
				}else if( mask2 & (1 << i) ){
					cur += v[ i ];
					if( cur >= INF ) break;
				}
			if( cur < INF ){
				assert( len < N );
				vec[ len ].pb( cur );
			}
			if( mask == 0 ) break;
		}
	}
	REP( i , N ) sort( all( vec[ i ] ) );
	return vec;
}
ll counting( vll &v , ll x ){
	return upper_bound( all( v ) , x ) - lower_bound( all( v ) , x );
}
int main(){	
	g[ 0 ] = 1;
	for( ll i = 1 ; i <= 18 ; ++i ) g[ i ] = i * g[ i - 1 ];

	ios_base :: sync_with_stdio( 0 );
	int n , K;
	ll S;
	while( cin >> n >> K >> S ){
		vvi v( 2 );
		REP( i , n ){
			int x;
			cin >> x;
			if( i < (n / 2) ) v[ 0 ].pb( x );
			else v[ 1 ].pb( x );
		}
		
		vector< vvll > T( 2 );
		REP( i , 2 ) T[ i ] = get( v[ i ] );

		ll ans = 0;
		REP( i , N ) REP( j , N )
			if( i + j <= K ){
				for( ll x : T[ 0 ][ i ] )
					ans += counting( T[ 1 ][ j ] , S - x );
			}
		cout << ans << '\n';
	}
}


