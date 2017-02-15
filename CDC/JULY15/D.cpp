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

#define N 100000
#define M 500
#define MAXVAL 200
#define INF (1<<20)

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int n;
int A[ N + 5 ] , C[ N + 5 ];
int T[ MAXVAL + 5 ][ N + 5 ];
void clear(){
	for( int i = 1 ; i <= MAXVAL ; ++i ) REP( j , n ) T[ i ][ j ] = 0; 
}
void update( int L , int R , int x ){
	T[ x ][ L ] ++;
	T[ x ][ R + 1 ] --;
}
void doit(){
	for( int x = 1 ; x <= MAXVAL ; ++x ){
		for( int i = 1 ; i < n ; ++i )
			T[ x ][ i ] += T[ x ][ i - 1 ];
	}
	REP( i , n ) C[ i ] = INF;
	REP( i , n ){
		for( int x = 1 ; x <= MAXVAL ; ++x )
			if( T[ x ][ i ] > 0 ){
				C[ i ] = x;
				break;
			}
	}
}

ll DP[ M + 5 ][ 2 ];
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int K , m;
		sc( n ) , sc( K ) , sc( m );
		REP( i , n ) sc( A[ i ] );
		
		clear();
		REP( i , m ){
			int L , R , x;
			sc( L ) , sc( R ) , sc( x );
			L -- , R --;
			update( L , R , x );
		}
		doit();
		ll S = 0;
		vi a , b;
		REP( i , n ){
			if( A[ i ] >= 0 ) S += A[ i ];
			else {
				if( C[ i ] == INF ) S += A[ i ];
				else{
					a.pb( A[ i ] );
					b.pb( C[ i ] );
				}
			}
		}
		n = SZ( a );
		REP( i , n ) A[ i ] = a[ i ] , C[ i ] = b[ i ];
		
		for( int pos = n ; pos >= 0 ; --pos )
			for( int cur = 0 ; cur <= K ; ++cur ){
				if( pos == n ) {
					DP[ cur ][ pos & 1 ] = 0;
					continue;
				}
				DP[ cur ][ pos & 1 ] = A[ pos ] + DP[ cur ][ (pos + 1)&1 ];
				if( cur - C[ pos ] >= 0 ) 
					DP[ cur ][ pos & 1 ] = max( DP[ cur ][ pos & 1 ] , DP[ cur - C[ pos ] ][ (pos + 1)&1 ] );
			}
		
		//assert( 0 );	
		printf( "%lld\n" , S + DP[ K ][ 0 ] );
	}
}



