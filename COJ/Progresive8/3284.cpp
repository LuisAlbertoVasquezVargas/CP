#include<bits/stdc++.h>
using namespace std;
 
#define sc(x) scanf( "%d" , &x )
#define REP(i , n) for( int i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )
 
#define pb push_back
#define all(v) v.begin() , v.end()
#define SZ(v) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second

#define DEBUG( x ) cerr << #x << " " << x << endl;

#define N 5000

typedef long long ll;
typedef long double ld;

bool used[ N + 5 ];
ld memo[ N + 5 ];
ld dp( int pos ){
	if( pos == 0 ) return 0;
	if( used[ pos ] ) return memo[ pos ];
	used[ pos ] = 1;
	ld &dev = memo[ pos ] = 0;
	int len = min( pos , 10 );
	for( int i = 1 ; i <= len ; ++i )
		dev += ( 1.0 / (ld)len ) * ( 1.0 + dp( pos - i ));
	return dev;
}

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		printf( "%.10f\n" , (double) dp( n ) );
	}
}


