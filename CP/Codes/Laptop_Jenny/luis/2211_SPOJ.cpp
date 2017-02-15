#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

#define NMAX 100000

typedef long long ll;
typedef pair<int,int> pii;

/********************************************************************
* Segment Tree # call len[1] and borders[1] to know *
* the total segment length and the total borders . *
********************************************************************/

#define v1 ( ( node << 1 ) )
#define v2 ( v1 + 1 )
#define med ( ( a + b ) >> 1 )
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

ll T[ 4*NMAX ]; // segment tree
int len[ 4*NMAX ] , borders[ 4*NMAX ] , br[ 4*NMAX ] , bl[ 4*NMAX ];
int N, off, r; //off = offset, r = log2(off)
int Y[ NMAX ];
void initialize( int _N ) { //_N is number os segments (not endpoints)
	N = _N; off = 1; r = 0; 
	while ( off < N ) off <<= 1 , ++r;
	REP( i , 2*off ) T[ i ] = len[ i ] = borders[ i ] = br[ i ] = bl[ i ] = 0;
}
void update( int node , int b , int e ) {
	if ( T[ node ] ) {
		len[ node ] = Y[ e + 1 ] - Y[ b ]; // or just E#B+1;
		borders[ node ] = 2; br[ node ] = bl[ node ] = 1;
	} else if ( node < off ) {
		len[ node ] = len[ 2*node ] + len[ 2*node + 1 ];
		borders[ node ] = 2*borders[ 2*node ] + 2*borders[ 2*node + 1 ] - 2*br[ 2*node ]*bl[ 2*node + 1 ];
		bl[ node ] = bl[ 2*node ]; br[ node ] = bl[ 2*node + 1 ];
	} else {
		len[ node ] = borders[ node ] = br[ node ] = bl[ node ] = 0;
	}
}
//b e
void add( int node , int a , int b , int B , int E ) {
	if ( b < B || E < a ) return; // or B==E ?
	else if ( B <= a && b <= E ) T[ node ]++;
	else {
		add( LEFT , B , E  );
		add( RIGHT , B , E );
	}
	update( node , a , b );
}
void add( int B , int E ){
	add( 1 , 0 , off - 1 , B , E );
}
void erase( int node , int a , int b , int B , int E )
{
	if ( b < B || E < a ) return; // or B==E ?
	else if ( B <= a && b <= E ) T[ node ]--;
	else {
		erase( LEFT , B , E );
		erase( RIGHT , B , E );
	}
	update( node , a , b );
}
void erase( int B , int E ){
	erase( 1 , 0 , off - 1 , B , E );
}
/********************************************************************
* Rectangle Union *
********************************************************************/

int x[ NMAX ][ 2 ] , y[ NMAX ][ 2 ]; 
int nrect;

typedef pii event;
int union_area() {
	if ( nrect == 0 ) return 0;
	vector< event > E;
	int m = 0;
	REP( i , nrect ) {
		E.pb( event( x[ i ][ 0 ] , i ) );
		E.pb( event( x[ i ][ 1 ] , ~i ) );
		Y[ m++ ] = y[ i ][ 0 ] ; Y[ m++ ] = y[ i ][ 1 ];
	}
	sort( all( E ) );
	sort( Y , Y + m );
	m = unique( Y , Y + m ) - Y;
	int last = E[ 0 ].fi;
	int ans = 0;
	initialize( m - 1 );
	REP( i , 2*nrect ) {
		int k = E[ i ].se; 
		bool in = ( k >= 0 ); 
		if ( !in ) k = ~k;
		ans += ( E[ i ].fi - last ) * len[ 1 ];
		int a = lower_bound( Y , Y + m , y[ k ][ 0 ] ) - Y;
		int b = lower_bound( Y , Y + m , y[ k ][ 1 ] ) - Y;
		if ( in ) add( a , b - 1 ); 
		else erase( a , b - 1 );
		last = E[ i ].fi;
	}
	return ans;
}
int main(){
	sc( nrect );
	REP( i , nrect )
		REP( j , 2 ) sc( x[ i ][ j ] ) , sc( y[ i ][ j ] );
	printf( "%d\n" , union_area() );
}

