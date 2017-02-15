#include<bits/stdc++.h>
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
		vi A( n );
		REP( i , n ){
			int x;
			sc( x );
			A[ i ] = x;
		}
		map< int , int > mapa;
		int maxi = 0;
		REP( i , n ) {
			mapa[ A[ i ] - i ] ++;
			maxi = max( maxi , mapa[ A[ i ] - i ] );
		}
		int ind = -1;
		REP( i , n )
			if( mapa[ A[ i ] - i ] == maxi ){
				ind  = i;
				break;
			}
		printf( "%d\n" , n - mapa[ A[ ind ] - ind ] );
		REP( i , n ) printf( "%d%c" , A[ ind ] - ind + i, (i + 1 == n ? 10 : 32) );
	}
}



