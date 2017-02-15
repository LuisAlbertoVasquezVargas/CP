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

int F[ N + 5 ];
int n;
ll ans;
ll CEIL( ll a , ll b ){
	if( a <= 0 ) return 0;
	return (a - 1)/b + 1;
}
void solve( ll cant ){
	if( cant < 2 ) return;
	if( cant % n ) return;
	ll K = cant / n , last = -1;
	REP( i , n )
		if( F[ i ] % K ) return;
		else {
			ll cur = ((ll)F[ i ]) % ((ll) K * n);
			if( last == -1 ) last = cur;
			else{
				if( last != cur ) return;
			}
		}
	if( last == 0 ) last = K * n;
	//DEBUG( tope );
	ll lo = (last/K) , hi = (F[ 0 ] - cant)/K;
	ans += CEIL( hi - lo + 1 , n );
	/*
	for( ll B = (last/K) ; B <= (F[ 0 ] - cant)/K ; B += n ){
		//cout << B << endl;
		bool ok = 1;
		REP( i , n )
			if( (F[ i ] - B * K) % cant ){
				ok = 0;
				break;
			}
		ans += ok;
	}
	*/
}
int main(){
	while( sc( n ) == 1 ){
		if( !n ) break;
		REP( i , n ) sc( F[ i ] );
		
		sort( F , F + n );
		
		ll S = 0;
		REP( i , n ) S += F[ i ];
		
		ans = 0;
		for( ll d = 1 ; d * d <= S ; ++d ){
			if( S % d == 0 ){
				ll d1 = d , d2 = S /d;
				if( d1 != d2 ) solve( d1 ) , solve( d2 );
				else solve( d1 );
			}
		}
		printf( "%lld\n" , ans );
	}
}


