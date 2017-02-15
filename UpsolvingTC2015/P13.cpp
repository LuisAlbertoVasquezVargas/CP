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

#define N 20
#define MOD 9999991

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int L[ N + 1 ] , R[ N + 1 ] , pa[ N + 1 ];
bool used[ 1 << N ];
int memo[ 1 << N ];
int n;
int dp( int mask ){
	//DEBUG( mask );
	if( __builtin_popcount( mask ) == n ) return 1;
	if( used[ mask ] ) return memo[ mask ];
	used[ mask ] = 1;
	
	int &dev = memo[ mask ] = 0;
	for( int i = 1 ; i < n ; ++i )
		if( ((1 << pa[ i ]) & mask) && !(mask & (1 << i)) ){
			dev += dp( mask | (1 << i) );
			if( dev >= MOD ) dev -= MOD;
		}
	return dev;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		
		sc( n );
		vi p( n );
		REP( i , n ) sc( p[ i ] );

		clr( pa , -1 );
		clr( L , -1 );
		clr( R , -1 );
			
		for( int i = 1 ; i < n ; ++ i ){
			int cur = 0;
			while( 1 ){
				if( p[ i ] < p[ cur ] ){
					if( L[ cur ] == -1 ){
						L[ cur ] = i;
						pa[ i ] = cur;
						break;
					}
					cur = L[ cur ];
				}else{
					if( R[ cur ] == -1 ){
						R[ cur ] = i;
						pa[ i ] = cur;
						break;
					}
					cur = R[ cur ];
				}
			}
		}
		/*
		REP( i , n ) DEBUG2( i , pa[ i ] );
		REP( i , n ) DEBUG2( i , L[ i ] );
		REP( i , n ) DEBUG2( i , R[ i ] );
		*/
		clr( used , 0 );
		printf( "%d\n" , dp( 1 << 0 ) );
	}
}



