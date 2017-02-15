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

#define M 47

typedef long long ll;
typedef vector< ll > vll;
typedef vector< vll > vvll;
typedef vector< vvll > vvvll;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< pll > vpll;
typedef vector< vpll > vvpll;
typedef vector< int > vi;
typedef long double ld;

ld INF = 1e20;
ld EPS = 1e-9;

vvll generate( vpll &v , vpll &w ){
	vvll ans( M + 5 );
	int n = SZ(v);
	for( int mask = 1 ; mask < (1 << n) ; ++mask ){
		ll num = 0 , den = 0;
		REP( i , n )
			if( mask & (1 << i) ){
				num += v[ i ].fi * v[ i ].se;
				den += v[ i ].se;
			}
		ans[ den ].pb( num );
		w.pb( mp(num , den) );
	}
	for( auto &v : ans ) sort( all( v ) );
	return ans;
}


void doit( ll X , ld &dif , vvpll &R ){
	REP( i , 2 ){
		for( auto r : R[ i ] ){
			ll A1 = r.fi , B1 = r.se;
			dif = min( dif , abs( (ld)X - (ld)A1/(ld)B1) );
		}
	}
}
void doit2( ll X , ld &dif , vvll &T , vpll &R ){
	for( auto r : R ){
		ll A1 = r.fi , B1 = r.se;
		REP( B2 , M + 1 ){
			ll exp = X * B1 - A1 + X * B2;
			int pos = upper_bound( all( T[ B2 ] ) , exp ) - T[ B2 ].begin();
		
			if( pos < SZ(T[ B2 ]) ){
				ll A2 = T[ B2 ][ pos ];
				dif = min( dif , abs( (ld)X - (ld)(A1 + A2)/(ld)(B1 + B2)) );
			}
		
			if( pos - 1 >= 0 ){
				ll A2 = T[ B2 ][ pos - 1 ];
				dif = min( dif , abs( (ld)X - (ld)(A1 + A2)/(ld)(B1 + B2)) );
			}
		
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(0);
	int n ;
	ll H , S;
	while( cin >> n >> H >> S ){
		vvpll V( 2 );
		REP( i , n ){
			ll K , W;
			cin >> K >> W;
			V[ ((i < n/2)?0 : 1) ].pb( mp( K , W ) );
		}
		vvvll T( 2 );
		vvpll R( 2 );
		REP( i , 2 ) T[ i ] = generate( V[ i ] , R[ i ] );
		
		ld bestH = INF , bestS = INF;
		
		doit( H , bestH , R );
		doit( S , bestS , R );
		
		doit2( H , bestH , T[ 1 ] , R[ 0 ] );
		doit2( S , bestS , T[ 1 ] , R[ 0 ] );
		
		//DEBUG2( bestH.num , bestH.den );
		//DEBUG2( bestS.num , bestS.den );
		if( abs( bestH - bestS ) < EPS ){
			cout << "Tie\n";
		}else{
			if( bestH < bestS ) cout << "Hawks\n";
			else cout << "Swans\n";
		}
	}
}



