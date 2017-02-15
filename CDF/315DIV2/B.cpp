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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi used( n );
		vi A( n , -1 );
		REP( i , n ) {
			int x;
			sc( x );
			x --;
			if( x < n && !used[ x ] ){
				used[ x ] = 1;
				A[ i ] = x;
			}
		}
		for( int i = 0 , j = 0 ; i < n ; ++i )
			if( A[ i ] == -1 ){
				while( used[ j ] ) j ++;
				A[ i ] = j;
				j ++;
			}
		REP( i , n ) printf( "%d%c" , A[ i ] + 1 , (i + 1 == n) ? 10 : 32 );
	}
}


