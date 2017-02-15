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

#define test() cerr << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;


typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef vector< vvpii > vvvpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector< vvvi > vvvvi;

ll MOD;

struct Matrix{
	ll M[ 2 ][ 2 ];
	Matrix(){
		M[ 0 ][ 0 ] = 3;
		M[ 0 ][ 1 ] = 2;
		M[ 1 ][ 0 ] = 0;
		M[ 1 ][ 1 ] = 1;
	}
	Matrix( ll t ){
		M[ 0 ][ 0 ] = M[ 1 ][ 1 ] = 1;
		M[ 0 ][ 1 ] = M[ 1 ][ 0 ] = 0;
	}
};
Matrix operator * ( const Matrix &a , const Matrix &b ){
	Matrix C;
	REP( i , 2 )REP( j , 2 ){
		ll dev = 0;
		REP( k , 2 ) dev = ( dev + a.M[ i ][ k ] * b.M[ k ][ j ] )%MOD;
		C.M[ i ][ j ] = dev;
	}
	return C;
}
Matrix pow( Matrix a , ll b ){
	Matrix ans( 1 );
	while( b ){
		if( b & 1 ) ans = ans * a;
		a = a * a;
		b >>= 1 ;
	}
	return ans;
}
int main(){
	ll n ;
	while( cin >> n >> MOD ){
		Matrix mat;
		mat = pow( mat , n );
		cout << mat.M[ 0 ][ 1 ] << '\n';
	}
}


