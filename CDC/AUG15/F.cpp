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

#define N 300000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int A[ N + 5 ];
int P[ N + 5 ];
void sieve(){
	clr( P , -1 );
	P[ 0 ] = P[ 1 ] = 0;
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
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

vi get( vi pr , vi ex ){
	int k = pr.size();
	vi divisors( 1 , 1 );

	REP( i , k ){
		int m = divisors.size();
		REP( j , ex[ i ] )
			REP( a , m ) divisors.pb( pr[ i ] * divisors[ a + j * m ] );
	}
	return divisors;
}
int mapa[ N + 5 ];
int main(){
	sieve();
	int n , K;
	while( sc( n ) == 1 ){
		sc( K );
		REP( i , n ) sc( A[ i ] );
		ll ans = 0;
		int cnt = 0;
		for( int lo = 0 , hi = -1 ; lo < n ; ++lo ){
			while( hi + 1 < n ){
				int y = A[ hi + 1 ];
				bool ok = 1;
				if( y < K ){
					//dont worry
				}else if( y == K ){
					//just use cnt
					cnt ++;
				}else{
					//just 
					if( cnt ) ok = 0;
					else{
						if( mapa[ y ] ) ok = 0;
						else{
							vi p , e , divi;
							primefact( y - K , p ,e );
							divi = get( p , e );
							for( auto d : divi ) mapa[ d ] ++;
						}
					}
				}
				if( !ok ) break;
				hi ++;
			}
			int y = A[ lo ];
			bool ok = 1;
			if( y < K ){
				//dont worry
			}else if( y == K ){
				//just use cnt
				cnt --;
			}else{
				//just 
				vi p , e , divi;
				primefact( y - K , p ,e );
				divi = get( p , e );
				for( auto d : divi ) mapa[ d ] --;
			}
			ans += hi - lo + 1;
		}
		cout << ans << '\n';
	}
}



