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

#define N 16
#define INF (1<<20)

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int , int > pii;

ll S[ 1 << N ];
/*
bool used[ 2 ][ 1 << N ];
ll memo[ 2 ][ 1 << N ];
ll K , W;
ll A[ N + 1 ];
int n ;
ll dp( int state , int mask ){
	if( mask == 0 ) return 0;
	if( used[ state ][ mask ] ) return memo[ state ][ mask ];
	used[ state ][ mask ] = 1;
	ll &dev = memo[ state ][ mask ] = INF;
	if( state == 0 ){
		for( int mask2 = mask ; mask2 != 0 ; mask2 = ( mask2 - 1 ) & mask ){
			if( __builtin_popcount( mask2 ) <= (K) && S[ mask2 ] <= (W) ){
				dev = min( dev , 1 + dp( 1 , mask ^ mask2 ) );
			}
		}
	}else{
		REP( i , n )
			if( !(mask & (1 << i)) )
				if( A[ i ] <= W ) dev = min( dev , 1 + dp( 0 , mask ^ (1 << i) ) );
	}
	return dev;
}
*/

ll K , W;
ll A[ N + 1 ];
int n ;

int main(){
	
	while( cin >> n ){
		cin >> W >> K;
		REP( i , n ) cin >> A[ i ];
		sort( A , A + n );
		REP( mask , 1 << n ){
			if( !mask ) continue;
			int pos = 31 - __builtin_clz( mask );
			S[ mask ] = (ll)A[ pos ] + S[ mask ^ (1 << pos) ];
		}

		vvi d( 2 , vi( 1 << n , INF ) );
		
		queue< pii > Q;
		d[ 0 ][ (1 << n) - 1 ] = 0;
		Q.push( mp( 0 , (1 << n) - 1 ) );
		
		while( !Q.empty() ){
			pii U = Q.front(); Q.pop();
			int state = U.fi , mask = U.se;
			if( state == 0 ){
				for( int mask2 = mask ; mask2 != 0 ; mask2 = ( mask2 - 1 ) & mask ){
					if( __builtin_popcount( mask2 ) <= (K) && S[ mask2 ] <= (W) ){
						if( d[ 1 ][ mask ^ mask2 ] >= INF ){
							Q.push( mp( 1 , mask ^ mask2 ) );
							d[ 1 ][ mask ^ mask2 ] = 1 + d[ state ][ mask ];
						}
					}
				}
			}else{
				REP( i , n )
					if( !(mask & (1 << i)) )
						if( A[ i ] <= W ) {
							if( d[ 0 ][ mask ^ (1 << i) ] >= INF ){
								Q.push( mp( 0 , mask ^ (1 << i) ) );
								d[ 0 ][ mask ^ (1 << i) ] = 1 + d[ state ][ mask ];
							}
						}
			}
		}
		//cout << d[ 0 ][ 0 ] << " " << d[ 1 ][ 0 ] << endl;
		int ans = min( d[ 0 ][ 0 ] , d[ 1 ][ 0 ] );
		if( ans >= INF ){
			puts( "-1" );
			continue;
		}
		printf( "%d\n" , (int)ans );
	}
}


