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

#define INF (1<<30)
#define N 200000

#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;

struct EuclidReturn{
    ll u , v , d;
    EuclidReturn( ll u , ll v, ll d ) : u( u ) , v( v ) , d( d ) {}
};
    
EuclidReturn Extended_Euclid( ll a , ll b){
    if( b == 0 ) return EuclidReturn( 1 , 0 , a );
    EuclidReturn aux = Extended_Euclid( b , a%b );
    ll v = aux.u - (a/b)*aux.v;
    return EuclidReturn( aux.v , v , aux.d );
}

// ax = 1(mod n)
ll modular_inverse( ll a , ll n ){
    EuclidReturn aux = Extended_Euclid( a , n );
    return ((aux.u/aux.d)%n+n)%n;
}

ll chinese_remainder( vll &rem, vll &mod ){
	ll ans = rem[ 0 ] , m = mod[ 0 ];
    for( int i = 1 ; i < SZ(rem) ; ++i ){
        int a = modular_inverse( m , mod[ i ] );
        int b = modular_inverse( mod[ i ] , m );
        ans = ( ans * b * mod[ i ] + rem[ i ] * a * m)%( m*mod[ i ] );
        m *= mod[i];
    }
    return ans;
}


void primefact( int n , vll &p , vll &e , vll &pe ){
	for( int i = 2 ; i * i <= n ; ++i ){
		if( n % i == 0 ){
			int exp = 0 , pot = 1;
			while( n % i == 0 ){
				n /= i;
				exp ++;
				pot *= i;
			}
			p.pb( i ) , e.pb( exp ) , pe.pb( pot );
		}
	}
	if( n > 1 ) p.pb( n ) , e.pb( 1 ) , pe.pb( n );
}

ll pow( ll a , ll b , ll c ){
	ll ans = 1;
	while( b ){
		if( b & 1 ) ans = (ans * a)%c;
		a = (a * a)%c;
		b >>= 1;
	}
	return ans;
}
ll factmod( ll n , ll p , ll pe ){
	if( n == 0 ) return 1;
	ll cpa = 1;
    ll ost = 1;
    for( ll i = 1; i <= pe; i++ ){
        if( i % p != 0 ) cpa = (cpa * i) % pe;
        if( i == (n % pe) ) ost = cpa;
    }
    cpa = pow(cpa, n / pe, pe);
    cpa = (cpa * ost) % pe;
    ost = factmod(n / p, p, pe);
    cpa = (cpa * ost) % pe;
    return cpa;
}
ll factst( ll a , ll b ){
	ll ans = 0;
	while( a ){
		ans += a / b;
		a /= b;
	}
	return ans;
}

ll solve( ll n , ll k , ll p , ll e , ll pe ){
	ll np = factmod( n , p , pe );
	ll kp = factmod( k , p , pe );
	ll nkp = factmod( n - k , p , pe );
	ll cnt = factst( n , p ) - factst( k , p ) - factst( n - k , p );
	if( cnt >= e ) return 0;
	ll r = ((np * modular_inverse( kp , pe ))% pe);
	r = (r * modular_inverse( nkp , pe ))%pe;
	REP( i , cnt ) r = (r * p) % pe;
	return r;
}

int main(){
	ll n , k , mod;
	while( cin >> n >> k >> mod ){
		vll p , e , pe;// pe = p ^ e
		primefact( mod , p , e , pe );
		vll rem;
		REP( i , SZ( p ) ) rem.pb( solve( n , k , p[ i ] , e[ i ] , pe[ i ] ) );
		cout << chinese_remainder( rem ,  pe ) << '\n';
	}
}


