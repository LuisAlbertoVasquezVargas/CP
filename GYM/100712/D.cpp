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

#define N 1000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

const int INF = INT_MAX/2;
char S[ N + 5 ];
bool used[ N + 4 ];
int memo[ N + 4 ];
int n , K;
int dp( int pos ){
	if( pos == n ) return 0;
	if( used[ pos ] ) return memo[ pos ];
	used[ pos ] = 1;
	
	int &dev = memo[ pos ] = (pos != n - 1) + dp( pos + 1 );
	int last = S[ pos ] , alt = 1;
	for( int j = pos + 1 ; j < n ; ++j ){
		if( S[ j ] == last ) alt = 0;
		if( j - pos + 1 > K ) break;
		if( !alt ) dev = min( dev , (j != n - 1) + dp( j + 1 ) );
		last ^= 1;
	}
	return dev;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( n ) , sc( K );
		scanf( "%s" , S );
		REP( i , n ) S[ i ] -= '0';
		clr( used , 0 );
		printf( "%d\n" , dp( 0 ) );
	}
}




