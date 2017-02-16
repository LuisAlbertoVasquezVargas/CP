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
typedef double ld;
typedef vector< int > vi;

#define INF 100000000000LL
#define N (30 * 30)
#define M 1000000

int X[ M + 5 ] , Y[ M + 5 ] , W[ M + 5 ];
int orig[ M + 5 ] , dest[ M + 5 ] ;
ld peso[ M + 5 ];
ld D[ N + 5 ];
int maxi , n , m , S;

bool relax( int k ){
	int u = orig[ k ] , v = dest[ k ] ;
	ld w = peso[ k ];
	if( D[ u ] + w < D[ v ] ){
		D[ v ] = D[ u ] + w;
		return 1;
	}
	return 0;
}

bool check( ld target ){
	REP( i , n ) D[ i ] = INF;	
	REP( i , m ){
		int u = X[ i ] , v = Y[ i ];
		ld w = W[ i ];
		//orig[ i ] = u;
		//dest[ i ] = v;
		if( u == S ) peso[ i ] = 0;
		else peso[ i ] = target - w;
	}
	D[ S ] = 0.0;
	REP( it , n - 1 )
		REP( i , m )
			relax( i );
	REP( i , m ) if( relax( i ) ) return 1;
	return 0;
}
// 16 , 26 pasa
ld search(){
	ld lo = 0.0 , hi = maxi;
	if( !check( lo ) ) return -1;
	REP( it , 15 ){
		ld mi = ( hi + lo )/2;
		if( check( mi ) ) lo = mi;
		else hi = mi;
	}
	return lo;
}

char s[ 10000 + 5 ];
int main(){
	int len;
	while( sc( len ) == 1 ){
		if( !len ) break;
		n = 26 * 26 + 1;
		m = 0;
		maxi = INT_MIN;
		REP( it , len ){
			scanf( "%s" , s );
			int leng = strlen( s );
			int p1 = s[ 0 ] - 'a';
			int p2 = s[ 1 ] - 'a';
			int p3 = s[ leng - 2 ] - 'a';
			int p4 = s[ leng - 1 ] - 'a';
			int x = p1 * 26 + p2, y = p3 * 26 + p4 , w = leng;

			orig[ m ] = X[ m ] = x;
			dest[ m ] = Y[ m ] = y;
			peso[ m ] = W[ m ] = w;
			maxi = max( maxi , w );
			m ++;
		}
		S = n - 1;
		REP( i , S ) {
			orig[ m ] = X[ m ] = S;
			dest[ m ] = Y[ m ] = i;
			peso[ m ] = W[ m ] = 0;
			m ++;
		}
		ld ans = search();
		if( abs( ans - (-1) ) < 1e-6 ) puts( "No solution." );
		else printf( "%.2f\n" , (double)ans );
	}
}

