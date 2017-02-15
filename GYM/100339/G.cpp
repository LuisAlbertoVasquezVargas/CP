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

#define N 100
#define cte 20000
#define M 40001
#define INF (1<<29)

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int n;
int A[ N + 1 ];
bool used[ N + 1 ][ M + 5 ];
int memo[ N + 1 ][ M + 5 ];
vi dx = { 1 , -1 }; 
int dp( int pos , int sum ){
	assert( cte + sum >= 0 );
	if( pos == n ) return (sum == 0) ? 0 : (-INF);
	if( used[ pos ][ cte + sum ] ) return memo[ pos ][ cte + sum ];
	used[ pos ][ cte + sum ] = 1;
	int &dev = memo[ pos ][ cte + sum ] = dp( pos + 1 , sum ); 
	REP( k , 2 ) dev = max( dev , 1 + dp( pos + 1 , sum + dx[ k ] * A[ pos ] ) );
	return dev;
}
void rec( int pos , int sum , vvi &T ){
	if( pos == n ) return ;
	int dev = dp( pos , sum );
	if( dev == dp( pos + 1 , sum ) ){
		rec( pos + 1 , sum , T );
		return;
	}
	REP( k , 2 ) 
		if( dev == 1 + dp( pos + 1 , sum + dx[ k ] * A[ pos ] ) ){
			T[ k ].pb( A[ pos ] );
			rec( pos + 1 , sum + dx[ k ] * A[ pos ] , T );
			return;
		}
}
int main(){
	
	freopen( "polygon.in" , "r" , stdin );
	freopen( "polygon.out" , "w" , stdout );
	
	while( sc( n ) == 1 ){
		REP( i , n ) sc( A[ i ] );
		clr( used , 0 );
		printf( "%d\n" , dp( 0 , 0 ) );
		vvi T( 2 );
		rec( 0 , 0 , T );
		int x = 0 , y = 0;
		REP( k , 2 ){
			for( auto d : T[ k ] ){
				int nx = x + dx[ k ] * d;
				int ny = y + 1;
				printf( "%d %d\n" , x , y );
				printf( "%d %d\n" , nx , y );
				x = nx , y = ny;
			}
		}
	}
}



