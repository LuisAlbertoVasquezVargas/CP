#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
 
#define sc(x) scanf( "%d" , &x )
#define REP(i , n) for( int i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )
 
#define pb push_back
#define all(v) v.begin() , v.end()
#define SZ(v) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second

#define N 5000
#define M 13500000
#define MOD 1000000007LL

typedef long long ll;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

ll F[ M + 5 ] , FP[ M + 5 ];

ll pow( ll a , ll b , ll c ){
	ll ans = 1;
	while( b ){
		if( b & 1 ) ans = ( ans * a )%c;
		a = ( a * a )%c;
		b >>= 1;
	}
	return ans;
}
ll mod_inv( ll a , ll p ){
	return pow( a , p - 2 , p );
}
void init(){
	F[ 0 ] = 1;
	for( int i = 1 ; i <= M ; ++i ) 
		F[ i ] = ( (ll) i * F[ i - 1 ] )%MOD;
	FP[ M ] = mod_inv( F[ M ] , MOD ) ;
	for( int i = M - 1 ; i >= 0 ; --i ) 
		FP[ i ] = ( (ll)FP[ i + 1 ]*( i + 1 ) )%MOD;
}

ll comb( ll n, ll k ){
	ll ans = 1;
    while( n > 0 ){
        ll ni = n%MOD,ki = k%MOD;
        n /= MOD; k /= MOD;
        if( ni - ki < 0 )return 0;
        ll temp = (FP[ki]*FP[ni-ki])%MOD;
        temp = (temp*F[ni])%MOD;
        ans = (ans*temp)%MOD;
    }
    return ans;
}

int MODULO[] = { 1000000007 , 1000000009 };
int B = 31;
struct Hash{
	int H[ 2 ];
	Hash(){ H[ 0 ] = H[ 1 ] = 0;}
	void add( int x ){
		REP( i , 2 ) H[ i ] = ((ll)H[ i ] * B + (ll)x)%MODULO[ i ];
	}
};

char S[ N + 5 ];

int main(){
	init();
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , Q;
		sc( n ) , sc( Q );
		scanf( "%s" , S );
		//vpii V;
		unordered_map< ll , int > mapa;
		for( int i = 0 ; i < n ; ++i ){
			Hash H;
			for( int j = i ; j < n ; ++j ){
				H.add( S[ j ] - 'a' + 1 );
				//V.pb( mp( H.H[ 0 ] , H.H[ 1 ] ) );
				mapa[ (ll)H.H[ 0 ] * MODULO[ 1 ] + (ll)H.H[ 1 ] ] ++;
			}
		}
		int m = ((n) * (n + 1)) / 2;
		vi ans;
		for( auto it : mapa ){
			int cnt = it.se;
			if( SZ( ans ) < cnt + 1 ) ans.resize( cnt + 1 );
			for( int k = 1 ; k <= cnt ; ++k )
				ans[ k ] = (ans[ k ] + comb( cnt , k ) )%MOD;
		}
		//sort( all( V ) );
		//assert( 0 );
		/*
		
		*/
		/*
		REP( i , SZ( V ) ){
			int ind , cnt = 0;
			for( int j = i ; j < SZ( V ) ; ++j ){
				if( V[ i ] == V[ j ] ) {
					cnt ++;
					ind = j;
				}
				else break;
			}
			for( int k = 1 ; k <= cnt ; ++k )
				ans[ k ] = (ans[ k ] + comb( cnt , k ) )%MOD;
			i = ind;
		}
		*/
		
		REP( i , Q ){
			int x;
			sc( x );
			if( x >= SZ( ans ) ) puts( "0" );
			else printf( "%d\n" , ans[ x ] );
		}
		
	}
}


