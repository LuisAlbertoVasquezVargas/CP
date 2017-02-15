#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
 
#define sc(x) scanf( "%d" , &x )
#define REP(i , n) for( int i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )
 
#define pb push_back
#define all(v) v.begin() , v.end()
#define SZ(v) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;

ll MOD;

struct Matrix{
	ll M[ 2 ][ 2 ];
	Matrix(){
		M[ 0 ][ 0 ] = M[ 0 ][ 1 ] = M[ 1 ][ 0 ] = (1 %MOD);
		M[ 1 ][ 1 ] = (0 %MOD);
	}
	Matrix( ll t ){
		M[ 0 ][ 0 ] = M[ 1 ][ 1 ] = (1%MOD);
		M[ 0 ][ 1 ] = M[ 1 ][ 0 ] = (0%MOD);
	}
};
Matrix operator * ( const Matrix &a , const Matrix &b ){
	Matrix C;
	REP( i , 2 )REP( j , 2 ){
		ll dev = 0;
		REP( k , 2 ) dev = ( dev + a.M[ i ][ k ] * b.M[ k ][ j ] )%MOD;
		C.M[ i ][ j ] = dev%MOD;
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

ll pow( ll a , ll b , ll c ){
    ll ans = 1;	
    while( b ){
        if( b & 1 ) ans = ( ans * a )%c;
        a = ( a * a )%c;
        b >>= 1;
    }	
    return ans;
}
ll getFib( ll n ){
	Matrix A;
	A = pow( A , n );
	return A.M[ 0 ][ 0 ]%MOD;
}
int main(){
	//cout << (1LL << 40) << endl;
	ll n , L;
	ull K;
	while( cin >> n >> K >> L >> MOD ){
		ll ans = 1;
		ll A = getFib( n + 1 );
		ll B = (pow( 2LL , n , MOD ) - A + MOD)%MOD;
		bool ok = 1;
		for( int i = L ; i <= 63 ; ++i )
			if( K & (1ULL << i) ){
				ok = 0;
				break;
			}
		if( !ok ){
			cout << '0' << '\n';
			continue;
		}
		REP( i , L ){
			if( K & (1ULL << i) ){
				ans = (ans * B)%MOD;
			}else{
				ans = (ans * A)%MOD;
			}
		}
		cout << (ans % MOD) << '\n';
	}
}


