#include<cstdio>
#include<cassert>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
 
#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )
 
#define pb push_back
#define SZ( v ) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second
 
#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;
 
#define N 30000
 
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int n;
vpii V[ N + 5 ];
void update( int x , int ylo , int yhi ){
	if( !(0 <= x && x < n) ) return;
	if( ylo >= n ) return;
	if( yhi < 0 ) return;
	ylo = max( ylo , 0 );
	yhi = min( yhi , n - 1 );
	if( ylo > yhi ) return;
	//DEBUG( x );
	//DEBUG2( ylo , yhi );
	V[ x ].pb( mp( ylo , yhi ) );
}
#define v1 ((node<<1)+1)
#define v2 (v1+1)
#define med ((a+b)>>1)
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

int T[ 4 * N + 5 ] ;
bool flag[ 4 * N + 5 ];
void push( int node , int a , int b ){
	if( !flag[ node ] ) return;
	T[ node ] = ( b - a + 1 ) - T[ node ];
	if( a != b ){
		flag[ v1 ] ^= 1;
		flag[ v2 ] ^= 1;
	}
	flag[ node ] = 0;
}
int query( int node , int a , int b , int lo , int hi ){
	push( node , a , b );
	if( lo > b || a > hi ) return 0;
	if( a >= lo && hi >= b ) return T[ node ];
	return query( LEFT , lo , hi ) + query( RIGHT , lo , hi );
}
void update( int node , int a , int b , int lo , int hi ){
	push( node , a , b );
	if( lo > b || a > hi ) return;
	if( a >= lo && hi >= b ) {
		flag[ node ] = 1;
		push( node , a , b );
		return;
	}
	update( LEFT , lo , hi );
	update( RIGHT , lo , hi );
	T[ node ] = T[ v1 ] + T[ v2 ];
}

int main(){
	while( sc( n ) == 1 ){
		REP( i , n ) V[ i ].clear();
		clr( flag , 0 );
		clr( T , 0 );
		int Q;
		sc( Q );
		REP( it , Q ){
			int x , y , p , ori;
			sc( x ) , sc( y ) , sc( p ) , sc( ori );
			//assert( x >= 0 && x < n );
			//assert( y >= 0 && y < n );
			//DEBUG2( x , y );
			//3 (0:SW, 1:SE, 2:NE, 3:NW).
			if( ori == 0 ){
				//***
				///**
				////*
				REP( i , p )
					update( x + i , y - (p - 1) + i , y );
			}else if( ori == 1 ){
				//***
				//**
				//*
				REP( i , p )
					update( x + i , y , y + (p - 1) - i );

			}else if( ori == 2 ){
				//*
				//**
				//***
				REP( i , p )
					update( x - i , y , y + (p - 1) - i );
			}else{
				////*
				///**
				//***
				REP( i , p ) 
					update( x - i , y - (p - 1) + i , y );
			}
			/*
			REP( i , n ) {
				REP( j , 10 ){
					bool ok = T[ i ][ 0 ] & (1 << j);
					cout << ok ;
				}
				cout << endl;
			}
			*/
		}
		
		int ans = 0;
		REP( i , n ){
			REP( k , 2 ){
				REP( it , SZ( V[ i ] )){
					pii p = V[ i ][ it ];
					update( 0 , 0 , n - 1 , p.fi , p.se );
				}
				if( k == 0 ) ans += query( 0 , 0 , n - 1 , 0 , n - 1 );
			}
		}
		printf( "%d\n" , ans );
	}
}



