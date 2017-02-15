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

#define test() cout << "hola que hace ?" << endl;
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

const int N = 500 ;
const int INF = INT_MAX/2;

//v , r , c
int A[ 3 ][ N + 5 ][ N + 5 ];
int R , C;
int tree[ N + 5 ][ N + 5 ];

int qqry( int idx , int idy ){
	int sum = 0;
	while( idx > 0 ){
		int y1 = idy;
		while( y1 > 0 ){
			sum += tree[ idx ][ y1 ];
			y1 -= (y1 & -y1);
		}
		idx -= (idx & -idx);
	}
	return sum;   
}
int query( int x , int y ){ return qqry( x + 1 , y + 1 );}
void uupd( int x , int y , int val ){
	while( x <= R + 1 ){
		int y1 = y;
		while( y1 <= C + 1 ){
			tree[ x ][ y1 ] += val;
			y1 += (y1 & -y1);   
		}
		x += (x & -x);
	}
}
void update( int x , int y , int val ){ uupd( x + 1 , y + 1 , val );}

struct Node{
	int x , y , d;
	Node(){}
	Node( int x , int y , int d ) : x( x ) , y( y ) , d( d ){}
};
bool operator < ( const Node &a , const Node &b ){
	return a.d > b.d;
}

int getS( int lox , int hix , int loy , int hiy ){
	return query( hix , hiy ) - query( hix , loy - 1 ) - query( lox - 1 , hiy ) + query( lox - 1 , loy - 1 );
}
void doit( int lox , int hix , int loy , int hiy , int S , int d , priority_queue< Node > &Q , vvi &dist ){
	if( lox == hix ){
		if( loy == hiy ){
			update( lox , loy , -1 );
			Q.push( Node( lox , loy , d + A[ 0 ][ lox ][ loy ] ) );
			dist[ lox ][ loy ] = min( dist[ lox ][ loy ] , d + A[ 0 ][ lox ][ loy ] );
			return;
		}
		int medy = (loy + hiy) >> 1;
		int s1 = getS( lox , hix , loy , medy ) , s2 = S - s1;
		if( s1 ) doit( lox , hix , loy , medy , s1 , d , Q , dist );
		if( s2 ) doit( lox , hix , medy + 1 , hiy , s2 , d , Q , dist );
		return;
	}
	int medx = (lox + hix) >> 1;
	int s1 = getS( lox , medx , loy , hiy ) , s2 = S - s1;
	if( s1 ) doit( lox , medx , loy , hiy , s1 , d , Q , dist );
	if( s2 ) doit( medx + 1 , hix , loy , hiy , s2 , d , Q , dist );
}
void get( int x , int y , int d , priority_queue< Node > &Q , vvi &dist ){
	int lox = max( 0 , x - A[ 1 ][ x ][ y ] );	
	int hix = min( R - 1 , x + A[ 1 ][ x ][ y ] );
	int loy = max( 0 , y - A[ 2 ][ x ][ y ] );	
	int hiy = min( C - 1 , y + A[ 2 ][ x ][ y ] );
	int S = getS( lox , hix , loy , hiy );
	if( S ) doit( lox , hix , loy , hiy , S , d , Q , dist );
}

void impr(){
	/*
	REP( i , R ) {
		REP( j , C ) cout << getS( i , j , i , j ) << " ";
		cout << endl;
	}
	*/
}
int solve( int sx , int sy , int tx , int ty ){
	if( sx == tx && sy == ty ) return 0;
	clr( tree , 0 );
	REP( i , R ) REP( j , C ) update( i , j , 1 );
	
	vvi dist( R , vi( C , INF ) );
	priority_queue< Node > Q;
	Q.push( Node( sx , sy , A[ 0 ][ sx ][ sy ] ) );
	update( sx , sy , 0 );
	dist[ sx ][ sy ] = A[ 0 ][ sx ][ sy ];
	
	while( !Q.empty() ){
		Node p = Q.top();  Q.pop();
		int x = p.x , y = p.y;
		if( abs(x - tx) <= A[ 1 ][ x ][ y ] && abs(y - ty) <= A[ 2 ][ x ][ y ] ) 
			return dist[ x ][ y ];
		get( x , y , dist[ x ][ y ] , Q , dist );
	}
	return -1;
}

int main(){
	int len;
	while( sc( R ) == 1 ){
		sc( C ) , sc( len );
		REP( k , 3 ) REP( i , R ) REP( j , C ) sc( A[ k ][ i ][ j ] );
		vi x( len ) , y( len );
		REP( i , len ) sc( x[ i ] ) , sc( y[ i ] ) , x[ i ] -- , y[ i ] --;
		vi vec;
		REP( i , len - 1 )
			vec.pb( solve( x[ i ] , y[ i ] , x[ i + 1 ] , y[ i + 1 ] ) );
		REP( i , SZ(vec) ) printf( "%d%c" , vec[ i ] , (i + 1 == SZ(vec) ? 10 : 32) );
	}
}




