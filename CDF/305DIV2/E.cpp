#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define SZ( v ) ((int)(v).size())
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

#define N 500000

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;

int P[ N + 5 ];
void sieve(){
	clr( P , -1 );
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
ll mu[ N + 5 ];
int getMu( int n ){
	int cnt = 0;
	while( 1 ){
		int p = P[ n ];
		if( n == 1 ){
			break;
		}
		if( p == -1 ){
			cnt ++;
			break;
		}
		int exp = 0 ;
		while( n % p == 0 ) {
			exp ++;
			n /= p;
		}
		if( exp > 1 ) return 0;
		cnt ++;
	}
	if( cnt & 1 ) return -1;
	return 1;
}
ll S;
ll f( ll n ){
	return (n * (n - 1))/2LL;
}
ll freq[ N + 5 ];
ll g( ll n ){
	return f( freq[ n ] ) * mu[ n ];
}
int main(){
	sieve();
	for( int i = 1 ; i <= N ; ++i ) mu[ i ] = getMu( i );
	int n;
	while( sc( n ) == 1 ){
		clr( freq , 0 );
		int Q , m = 0;
		sc( Q );
		vi a( n ) , used( n );
		REP( i , n ) sc( a[ i ] );
		S = 0 , m = 0;
		REP( it , Q ){
			int pos;
			sc( pos );
			pos --;
			vi p , e;
			primefact( a[ pos ] , p , e );
			vi DIV = get( p , e );
			
			for( int d : DIV ){
				if( d == 1 ) continue;
				S -= g( d );
				if( !used[ pos ] ) freq[ d ] ++;
				else freq[ d ] --;
				S += g( d );
			}
			if( used[ pos ] ) m --;
			else m ++;
			
			used[ pos ] ^= 1;
			cout << f( m ) + S << endl;
		}
		
	}
}

