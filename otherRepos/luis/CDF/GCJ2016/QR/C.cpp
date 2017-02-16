#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define all( v ) v.begin() , v.end()
#define SZ(v) ((int)v.size())
#define pb push_back

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;

const int N = 1e8;
int bits = 16;
int P[ N + 5 ];
vi primes;

void sieve(){
	clr( P , -1 );
	P[ 0 ] = P[ 1 ] = 0;
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 ){
			primes.pb( i );
			for( int j = i * i ; j <= N ; j += i )
				P[ j ] = i;
		}
}

bool checkPrime( ll n , ll &divi ){
	for( int i = 0 ; i < SZ(primes) && (ll)primes[ i ] * primes[ i ] <= n ; ++i ){
		if( n % primes[ i ] == 0 ){
			divi = primes[ i ];
			return 0;
		}
	}
	return 1;
}
bool validate( int mask , vll &vec ){
	for( int b = 2 ; b <= 10 ; ++b ){
		ll cur = 1 , number = 0;
		REP( i , bits ){
			if( mask & (1 << i) ) number += cur;
			cur *= b;
		}
		ll divi;
		if( checkPrime( number , divi ) ) return 0;
		vec[ b ] = divi;
	}
	return 1;
}
string get( int mask ){
	string s;
	REP( i , bits ){
		if( mask & (1 << i) ) s.pb( '1' );
		else s.pb( '0' ); 
	}
	reverse( all( s ) );
	return s;
}
int main(){
	sieve();
	int cases;
	sc( cases );
	cout << "Case #1:\n";
	int cnt;
	sc( bits ) , sc( cnt );
	REP( mask , (1<<bits) ){
		if( !(mask & (1 << 0)) ) continue;
		if( !(mask & (1 << (bits - 1))) ) continue;
		vll vec( 11 , -1 );
		if( !validate( mask , vec ) ) continue;
		
		cout << get( mask );
		for( int b = 2 ; b <= 10 ; b ++ )
			cout << " " << vec[ b ]; 
		cout << endl;
		cnt --;
		if( cnt == 0 ) break;
	}

}


