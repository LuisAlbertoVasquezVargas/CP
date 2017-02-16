#include<bits/stdc++.h>
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

#define N 5000000

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< int > vi;

int P[ N + 5 ];
int phi[ N + 5 ];

void sieve(){
	clr( P , -1 );
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
			
	for( int i = 1; i <= N ; ++i ) phi[ i ] = i;
	for( int i = 1; i <= N ; ++i ) for ( int j = i * 2; j <= N; j += i ) phi[j] -= phi[i];

}
void primefact( int n , vi &pr , vi &ex ){
	while( 1 ){
		int p = P[ n ];
		if( n == 1 ){
			return;
		}
		if( p == -1 ){
			pr.pb( n ) , ex.pb( 1 );
			break;
		}
		int exp = 0 ;
		while( n % p == 0 ) {
			exp ++;
			n /= p;
		}
		pr.pb( p ) , ex.pb( exp );
	}
}

vi getAllDivisors( vi pr , vi ex ){
	int k = pr.size();
	vi divisors( 1 , 1 );

	REP( i , k ){
		int m = divisors.size();
		REP( j , ex[ i ] )
			REP( a , m ) divisors.pb( pr[ i ] * divisors[ a + j * m ] );
	}
	return divisors;
}
ull AC[ N + 5 ];
ull get( ll n ){
	if( n == 1 ) return 1;
	ll ans = ((ll)phi[ n ] * n);
	assert( ans % 2 == 0 );
	return ans >> 1;
}
ull get2( ll n ){
	return (n * (n + 1)) >> 1;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	sieve();
	for( int i = 1 ; i <= N ; ++i ){
		vi p , e;
		primefact( i , p , e );
		vi divi = getAllDivisors( p , e );
		ull ans = 0;
		for( ll g : divi )
			ans += ( get( i / g ) * ((ll)i) );
		AC[ i ] = AC[ i - 1 ] + ans;
	}
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int n;
		cin >> n;
		ull a = AC[ n ];
		ull b = get2( n );
		ull c = a - b;
		cout << "Case " << tc + 1 << ": " << c << '\n';
	}
}



