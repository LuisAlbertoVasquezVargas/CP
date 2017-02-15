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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int N = 14;
const int EXP = 60;
const ll limit = 1000000000000000000LL;
int P[ N + 1 ];
ull A[ 14 ] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43};
ull F[ 14 ][ EXP + 5 ];
ull num , ans , L , CA;
bool valid( ull a , ull b ){
	ld aa = a , bb = b;
	if( aa * bb > 1e18 ) return 0;
	return a * b <= limit;
}
bool valid2( int pos , int exp ){
	ld aa = A[ pos ] , bb = exp;
	if(	pow( aa , bb ) > 1e18 ) return 0;
	return F[ pos ][ exp ] <= limit;
}

void f( int pos , int exp ){
	if( pos == N || exp == 0 ) {
		if( CA == L )
			ans = min( ans , num );
		return;
	}
	
	ull temp1 = num;
	ull temp2 = CA;
	f( pos , exp - 1 );
	num = temp1;
	CA = temp2;
	
	temp1 = num;
	temp2 = CA;
	if( valid2( pos , exp ) && valid( num , F[ pos ][ exp ] ) && valid( CA , exp + 1 ) ){
		num *= F[ pos ][ exp ];
		CA *= (exp + 1);
		f( pos + 1 , exp );
	}
	num = temp1;
	CA = temp2;
}
int main(){
	REP( i , N ) F[ i ][ 0 ] = 1;
	REP( i , N ) for( int k = 1 ; k <= EXP ; ++k ) F[ i ][ k ] = F[ i ][ k - 1 ] * A[ i ];
	while( cin >> L ){
		CA = num = 1;
		ans = LLONG_MAX;
		f( 0 , EXP );
		cout << ans << '\n';
	}
}
