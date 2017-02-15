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

#define N 100

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int A[ N + 1 ][ N + 1 ];

pii solve( vpii v ){
	return *max_element( all( v ) );
}

int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , m ) REP( j , n ) sc( A[ i ][ j ] );
		vi F( n );
		REP( i , m ){
			vpii temp;
			REP( j , n ) temp.pb( mp( A[ i ][ j ] , -j ) );
			int id = -solve( temp ).se;
			F[ id ] ++;
		}
		vpii vec;
		REP( i , n ) vec.pb( mp( F[ i ] , -i ) );
		pii ans = solve( vec );
		printf( "%d\n" , (-ans.se) + 1 );
	}	
}


