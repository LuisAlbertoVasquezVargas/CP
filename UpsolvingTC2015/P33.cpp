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
typedef pair< int , int > pii;
typedef vector< int > vi;


int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		vi A( n + 5 );
		REP( it , m ){
			int a , b;
			sc( a ) , sc( b );
			A[ a ] ++ , A[ b ] --;
		}
		REP( i , n + 1 ) A[ i + 1 ] += A[ i ];
		//for( int i = 1 ; i <= n + 1 ; ++i ) DEBUG2( i , A[ i ] );
		assert( A[ n ] == 0 );
		int ans = 0;
		for( int i = 0 ; i <= n ; ++i ){
			if( !A[ i ] ){
				ans ++;
				continue;
			}
			int ind;
			for( int j = i ; j <= n ; ++j )
				if( A[ j ] ) ind = j;
				else break;
			ans += 3 * (ind - i + 1);
			i = ind;
		}
		printf( "%d\n" , ans );
	}	
}


