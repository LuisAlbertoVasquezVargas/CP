#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define INF (1000000000000000LL)
#define DEBUG( x ) cout << #x << " " << (x) << endl;
#define N 16

typedef vector< int > vi;
typedef vector< string > vs;
typedef long long ll;
typedef vector< ll > vll;
typedef long double ld;

ll T[ 1 << N ];
int main(){
	ll w , m;
	while( cin >> w >> m ){
		if( w <= 3 ){
			cout << "YES\n";
			continue;
		}
		vll POW( N + 1 , 1 );
		for( int i = 1 ; i <= N ; ++i ){
			ld cur = (ld) w * (ld)POW[ i - 1 ];
			if( cur >= INF ) {
				POW[ i ] = INF;
				continue;
			}
			POW[ i ] = (ll) w * POW[ i - 1 ];
		}
		T[ 0 ] = 0;
		REP( mask , (1 << N) ){
			if( !mask ) continue;
			int r = 31 - __builtin_clz( mask );
			T[ mask ] = POW[ r ] + T[ mask ^ (1 << r) ];
			T[ mask ] = min( T[ mask ] , INF );
		}
		bool ok = 0;
		REP( mask , (1<<N) ){
			if( T[ mask ] >= INF ) continue;
			ll cur = m + T[ mask ];
			if( cur >= INF ) continue;
			int s = ((1<<N) - 1)^mask;
			for( int mask2 = s ; ; mask2 = ( mask2 - 1 ) & s ){
				if( T[ mask2 ] >= INF ) continue;
				if( T[ mask2 ] == cur ){
					//cout << cur << " " << T[ mask2 ] << " " << endl;
					ok = 1;
					break;
				}
				if( mask2 == 0 ) break;
			}
		}
		//assert( ok );
		//cout << w << " ";
		cout << (ok ? "YES" : "NO") << '\n';
	}
}


