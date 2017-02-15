#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 80
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;


ll pow( ll a , ll b , ll c ){
	ll ans = 1;
	while( b ){
		if( b & 1 ) ans = ( ans * a ) % c;
		b >>= 1;
		a = ( a * a )%c;
	}
	return ans;
}
ll C[ N + 5 ][ N + 5 ];
int sz;
ll k;
struct Matrix{
	ll M[ N + 5 ][ N + 5 ];
	Matrix(){
		clr( M , 0 );
		REP( i , sz ) M[ i ][ i ] = 1;
	}
	Matrix( int ttt ){
		clr( M , 0 );
		int x = sz - 1 , y = sz - 1;
		for( int it = 0 ; it <= k ; it ++ ){
			int iniy = y - ( 2* it + 1 );
			M[ x ][ iniy ] = 1;
			for( int u = 0 ; u <= it ; u ++ ){
				M[ x - 1 ][ iniy + 2*u ] = C[ it ][ u ];
				M[ x - 1 ][ iniy + 2*u + 1 ] = C[ it ][ u ] * pow( 2 , u , MOD );
			}	
			x -= 2;
		}
		
		REP( i , sz ) M[ 0 ][ i ] = M[ 1 ][ i ];
		M[ 0 ][ 0 ] = 1;
	}
	void impr(){
		REP( i , sz ) {
			REP( j , sz ) printf( "%6d" , M[ i ][ j ]);
			puts( "" );
		}
	}
};
Matrix operator * ( const Matrix & A , const Matrix &B ){
	Matrix C;
	REP( i , sz )REP( j , sz ){
		ll &dev = C.M[ i ][ j ] = 0;
		REP( k , sz ) dev = ( dev + ( A.M[ i ][ k ] * B.M[ k ][ j ] )%MOD )%MOD;
	}
	return C;
}
Matrix pow( Matrix a , ll b ){
	Matrix ans;
	while( b ){
		if( b & 1 ) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}
ll operator * ( Matrix A , vll v ){
	ll ans = 0;
	REP( i , sz ) ans = ( ans + ( A.M[ 0 ][ i ] * v[ i ] )%MOD )%MOD;
	return ans;
}
void impr( vll v ){
	int nv = v.size();
	REP( i , nv ) cout << v[ i ] << " " ;
	cout << endl;
}
ll eval( ll n ){
	if( n == 1 ) return 1;
	if( n == 2 ) return ( 1 + pow( 2 , k + 1 , MOD ) )%MOD;
	Matrix M( 1 );
	//M.impr();
	M = pow( M , n - 2 );
	
	vll v;
	REP( i , k + 1 ) v.pb( 1 ) , v.pb( pow( 2 , i + 1 , MOD ) );
	v.pb( 1 + pow( 2 , k + 1 , MOD ) );
	reverse( all( v ) );
	//M.impr();
	//impr( v );
	return M * v;
}
int main()
{
	REP( i , N + 1 ) C[ i ][ i ] = C[ i ][ 0 ] = 1;
	for( int i = 2 ; i <= N ; ++i )
		for( int j = 1 ; j < i ; ++j ) C[ i ][ j ] = ( C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ] )%MOD;
	ll n;
	while( cin >> n >> k ){
		sz = 2*( k + 1 ) + 1;
		cout << eval( n ) << '\n';
	}
}



