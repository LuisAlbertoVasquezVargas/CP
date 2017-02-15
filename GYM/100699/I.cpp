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
typedef vector< int > vi;

bool used[ N + 5 ];
vi memo[ N + 5 ];
int n;
int A[ N + 5 ];
vi dp( int pos ){
	
	if( pos == n ) return vi();
	if( used[ pos ] ) return memo[ pos ];
	used[ pos ] = 1;
	
	vi &dev = memo[ pos ] = vi();
	int best = 0;
	for( int i = 1 ; i <= 3 && pos + i <= n ; ++i ){
		best = max( best , A[ pos + i - 1 ] );
		if( i == 1 ) continue;
		vi w = dp( pos + i );
		w.pb( best );
		sort( all( w ) );
		reverse( all( w ) );
		if( w > dev ){
			dev = w;
		}
	}
	return dev;
}

int main(){
	while( sc( n ) == 1 ){
		REP( i , n ) sc( A[ i ] );
		clr( used , 0 );
		vi v = dp( 0 );
		REP( i , SZ(v) ) printf( "%d%c" , v[ i ] , (i + 1 == SZ(v)) ? 10 : 32 );
	}
}


