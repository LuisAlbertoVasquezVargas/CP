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
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;

vi dx = { 0 , 0 , 1 , -1 };
vi dy = { 1 , -1 , 0 , 0 };

bool valid( int a , int b ){ return a >= 0 && a < b; }
void doit( vvi &A , int K ){
	vvi B( A );
	int n = SZ( A ) , m = SZ( A[ 0 ] );
	REP( x , n ) REP( y, m ){
		REP( k , 4 ){
			int nx = x + dx[ k ];
			int ny = y + dy[ k ];
			if( valid( nx , n ) && valid( ny , m ) ){
				if( A[ nx ][ ny ] == (A[ x ][ y ] + 1)%K ){
					B[ nx ][ ny ] = A[ x ][ y ];
				}
			}
		}
	}
	A = B;
}
void impr( vi &A ){
	REP( i , SZ( A ) ) printf( "%d%c" , A[ i ] , (i + 1 == SZ(A) ? 10 : 32));
}
void impr( vvi &A ){
	for( auto x : A ) impr( x );
}
int main(){
	int n , R , C , K;
	while( sc( n ) == 1 ){
		sc( R ) , sc( C ) , sc( K );
		if( !n && !R && !C && !K ) break;
		vvi A( R , vi( C ) );
		REP( i , R ) REP( j , C ) sc( A[ i ][ j ] );
		REP( i , K ) doit( A , n );
		impr(A);
	}
}


