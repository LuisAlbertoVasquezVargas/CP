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

#define N 10000
#define cte 800
#define M 1600
#define INF (1<<29)

#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;

struct frac{
	ll num , den;
	frac(){ num = den = 0;}
	frac( ll a , ll b ){
		if( b == 0 ) num = 1 , den = 0;
		else if( a == 0 ) num = 0 , den = 1;
		else{
			if( b < 0 ) a = -a , b = -b;
			ll g = __gcd( abs( a ) , abs( b ) );
			num = a/g , den = b/g;
		}
	}
};
bool operator <( const frac &a , const frac &b ){
	return a.num * b.den < b.num * a.den;
}
bool operator >( const frac &a , const frac &b ){
	return a.num * b.den > b.num * a.den;
}
bool operator == ( const frac &A , const frac &B ){ return A.num == B.num && A.den == B.den;}
bool operator != ( const frac &A , const frac &B ){ return !(A == B);}
frac operator +( const frac &A , const frac &B ){ return frac( A.num * B.den + B.num * A.den , A.den * B.den ) ;}
frac operator -( const frac &A , const frac &B ){ return frac( A.num * B.den - B.num * A.den , A.den * B.den ) ;}

void solve( pii A , pii B , frac &C , frac &D , bool &ok ){
	if( A.fi >= B.fi && A.se >= B.se ){
		C = frac( 0 , 1 ) , D = frac( 1 , 1 );
		return;
	}
	if( A.fi < B.fi && A.se < B.se ){
		ok = 0;
		return;
	}
	frac I(A.fi - B.fi , (B.se - B.fi) - (A.se - A.fi) );
	if( A.fi > B.fi ){
		C = frac( 0 , 1 ) , D = I;
	}else{
		C = I , D = frac( 1 , 1 );
	}
}
void inter( frac &A , frac &B , frac C , frac D , bool &ok ){
	if( A > C ) swap( A , C ) , swap( B , D );
	if( C > B ){
		ok = 0;
		return;
	}
	frac E , F;
	E = C;
	F = min( D , B );
	A = E , B = F;
}
bool solve( vpii &v ){
	frac A( 0 , 1 ) , B( 1 , 1 );
	REP( i , SZ(v) - 1 ){
		pii a = v[ i ] , b = v[ i + 1 ];
		frac C , D;
		bool ok = 1;
		solve( a , b , C , D , ok );
		if( !ok ) return 0;
		inter( A , B , C , D , ok );
		if( !ok ) return 0;
	}	
	return 1;
}

int main(){
	int n;
	while( sc( n ) == 1 ){
		vpii v;
		REP( i , n ){
			int a , b;
			sc( a ) , sc( b );
			if( a > b ) swap( a , b );
			v.pb( mp( a , b ) );
		}
		puts( solve( v ) ? "YES" : "NO" );
	}
}


