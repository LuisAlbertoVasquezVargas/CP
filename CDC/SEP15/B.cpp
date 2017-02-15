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
typedef vector< pii > vpii;
typedef vector< int > vi;

int S , n;
int A[ N + 1 ];
bool f( int K ){
	int cnt = 0;
	for( int i = 0 , sum = 0 ; i < n ; ++i ){
		sum += A[ i ];
		if( sum < K ) continue;
		if( sum == K ) cnt = n - 1 - i;
		else cnt = n - i;
		break;
	}
	return K >= cnt - 1;
}

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( S ) , sc( n );
		REP( i , n ) sc( A[ i ] );
		sort( A , A + n );
		int lo = 0 , hi = n;
		if( f( lo ) ){
			puts( "0" );
			continue;
		}
		while( hi - lo > 1 ){
			int med = (lo + hi) >> 1;
			if( f( med ) ) hi = med;
			else lo = med;
		}
		printf( "%d\n" , hi );
	}
}



