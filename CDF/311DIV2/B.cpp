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

#define N 200000

typedef long long ll;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

int A[ N + 5 ];
int n , W;
bool f( ld x ){
	if( 3.0 * x * (ld) n > (ld) W ) return 0;
	vi cur = { n , n };
	vi delta = { 2 , 1 };
	//2 x , x
	REP( i , 2 * n ){
		REP( j , 2 ){
			if( cur[ j ] ){
				if( A[ i ] >= (ld) delta[ j ] * x ){
					cur[ j ] --;
					break;
				}
			}
		}
	}
	return cur == vi( 2 , 0 );
}
int main(){
	
	while( sc( n ) == 1 ){
		sc( W );
		REP( i , 2 * n ) sc( A[ i ] );
		
		ld lo = 0 , hi = 1e9 + 5;
		REP( it , 100 ){
			ld med = (lo + hi)/2.0;
			if( f( med ) )lo = med;
			else hi = med;
		}
		printf( "%.15f\n" , (double)(3.0 * lo * (ld) n) );
	}
}

