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

#define N 1000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const ll INF = LLONG_MAX/2;
int n;
int a[ N + 1 ] , b[ N + 1 ] , c[ N + 1 ];
ll DP[ N + 5 ][ 2 ][ 3 ];

int main(){
	while( sc( n ) == 1 ){
		REP( i , n ) sc( a[ i ] ) , sc( b[ i ] ) , sc( c[ i ] );
		REP( op , 3 ) REP( last , 2 ) DP[ n ][ last ][ op ] = (op == 1 ? (-INF) : 0);
		for( int pos = n - 1 ; pos >= 0 ; pos -- ){
			REP( last , 2 ) REP( op , 3 ){
				DP[ pos ][ last ][ op ] = -INF;
				if( !last ){
					if( op != 1 )
						DP[ pos ][ last ][ op ] = max( DP[ pos ][ last ][ op ] , DP[ pos + 1 ][ 0 ][ 2 ]  );
					if( op != 0 ){
						DP[ pos ][ last ][ op ] = max( DP[ pos ][ last ][ op ] , a[ pos ] + DP[ pos + 1 ][ 1 ][ 0 ]  );
						DP[ pos ][ last ][ op ] = max( DP[ pos ][ last ][ op ] , b[ pos ] + DP[ pos + 1 ][ 1 ][ 1 ]  );
					}
				}else{
					if( op != 1 )
						DP[ pos ][ last ][ op ] = max( DP[ pos ][ last ][ op ] , DP[ pos + 1 ][ 0 ][ 2 ]  );
					if( op != 0 ){
						DP[ pos ][ last ][ op ] = max( DP[ pos ][ last ][ op ] , b[ pos ] + DP[ pos + 1 ][ 1 ][ 0 ]  );
						DP[ pos ][ last ][ op ] = max( DP[ pos ][ last ][ op ] , c[ pos ] + DP[ pos + 1 ][ 1 ][ 1 ]  );
					}						
				}
			}
		}
		printf( "%lld\n" , DP[ 0 ][ 0 ][ 2 ] );
	}
}




