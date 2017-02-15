#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 10000
#define MOD 1000000007LL

typedef long long ll;

ll F[ N + 5 ] , FP[ N + 5 ];

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
	for( int i = 1 ; i <= N ; ++i ) 
		F[ i ] = ( (ll) i * F[ i - 1 ] )%MOD;
	FP[ N ] = mod_inv( F[ N ] , MOD ) ;
	for( int i = N - 1 ; i >= 0 ; --i ) 
		FP[ i ] = ( (ll)FP[ i + 1 ]*( i + 1 ) )%MOD;
}
ll comb( ll n, ll k ){
	ll ans = 1;
    while( n > 0 ){
        ll ni = n%MOD , ki = k%MOD;
        n /= MOD; k /= MOD;
        if( ni - ki < 0 ) return 0;
        ll temp = (FP[ki]*FP[ni-ki])%MOD;
        temp = (temp*F[ni])%MOD;
        ans = (ans*temp)%MOD;
    }
    return ans;
}

int A[ N + 5 ];
int main()
{
	init();
	int cases, n , k ;
	sc( cases );
	REP( tc , cases ){
		sc( n ) , sc( k );
		REP( i , n ) sc( A[ i ] );
		sort( A , A + n );
		ll ans = 0;
		for( int i = k - 1 ; i < n ; ++i )
			ans = ( ans + (ll)A[ i ] *  comb( i , k - 1 ) )%MOD;
		//cout << comb( n - 1 , k - 1 ) << endl;
		cout << "Case #" << tc + 1 << ": " << ans << "\n";
	}
}

