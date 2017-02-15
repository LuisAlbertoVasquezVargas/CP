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

const int N = 500 + 5;
const int INF = INT_MAX/2;

//v , r , c
int A[ 3 ][ N + 1 ][ N + 1 ];
int R , C;
struct data{
	int x , y , val;
	data(){ x = y = val = INF; }
	data( int x , int y , int val ) : x( x ) , y( y ) , val( val ){}
};
data operator + ( const data &a , const data &b ){
	if( a.val < b.val ) return a;
	return b;
}
data T[ 4 * N + 5 ][ 4 * N + 5 ];
int n , m ;
data QueryY( int nodex , int nodey , int ay , int by , int ylo , int yhi ){
	if( ay > yhi || ylo > by ) return data();
	if( ay >= ylo && yhi >= by ) return T[ nodex ][ nodey ];
	int v1 = 2 * nodey + 1 , v2 = v1 + 1 , med = ( ay + by )/2;
	return QueryY( nodex , v1 , ay , med , ylo , yhi ) + QueryY( nodex , v2 , med + 1 , by , ylo , yhi );
}

data QueryX( int nodex , int ax , int bx , int xlo , int xhi , int ylo , int yhi ){
	if( ax > xhi || xlo > bx ) return data();
	if( ax >= xlo && xhi >= bx ) return QueryY( nodex , 0 , 0 , m - 1 , ylo , yhi );
	int v1 = 2 * nodex + 1 , v2 = v1 + 1 , med = ( ax + bx )/2;
	return QueryX( v1 , ax , med , xlo , xhi , ylo , yhi ) + QueryX( v2 , med + 1 , bx , xlo , xhi , ylo , yhi );
}

void updateY( int nodex , int ax , int bx , int nodey , int ay , int by , int x , int y , int val ){
	if( ay > y || y > by ) return;
	if( ay == by ){
		if( ax == bx )
			T[ nodex ][ nodey ] = data( x , y , val );
		else T[ nodex ][ nodey ] = T[ 2 * nodex + 1 ][ nodey ] + T[ 2 * nodex + 2 ][ nodey ];
		return;
	}
	int v1 = 2 * nodey + 1 , v2 = v1 + 1 , med = ( ay + by )/2;
	updateY( nodex , ax , bx , v1 , ay , med , x , y , val );
	updateY( nodex , ax , bx , v2 , med + 1 , by , x , y , val );
	T[ nodex ][ nodey ] = T[ nodex ][ v1 ] + T[ nodex ][ v2 ];
}
void updateX( int nodex , int ax , int bx , int x , int y , int val ){
	if( ax > x || x > bx ) return;
	if( ax == bx ){
		updateY( nodex , ax , bx , 0 , 0 , m - 1 , x , y , val );
		return;
	}
	int v1 = 2 *nodex + 1 , v2 = v1 + 1 , med = ( ax + bx )/2;
	updateX( v1 , ax , med , x , y , val );
	updateX( v2 , med + 1 , bx , x , y , val );
	updateY( nodex , ax , bx , 0 , 0 , m - 1 , x , y , val );
}
//pii q = QueryX( 0 , 0 , n - 1 , xlo , xhi , ylo , yhi );
//updateX( 0 , 0 , n - 1 , x , y , val );
void update( int x , int y , int val ){
	//DEBUG2( x , y );
	//DEBUG( val );
	updateX( 0 , 0 , n - 1 , x , y , val );
}
data getS( int lox , int loy , int hix , int hiy ){
	//DEBUG2( lox , hix );
	//DEBUG2( loy , hiy );
	return QueryX( 0 , 0 , n - 1 , lox , hix , loy , hiy );
}

void get( int x , int y , int &nx , int &ny ){
	int lox = max( 0 , x - A[ 1 ][ x ][ y ] );	
	int hix = min( R - 1 , x + A[ 1 ][ x ][ y ] );
	int loy = max( 0 , y - A[ 2 ][ x ][ y ] );	
	int hiy = min( C - 1 , y + A[ 2 ][ x ][ y ] );
	data d = getS( lox , loy , hix , hiy );
	//DEBUG( d.val );
	if( d.val > 0 ){
		nx = ny = -1;
		return;
	}
	nx = d.x , ny = d.y;
}
struct Node{
	int x , y , d;
	Node(){}
	Node( int x , int y , int d ) : x( x ) , y( y ) , d( d ){}
};
bool operator < ( const Node &a , const Node &b ){
	return a.d > b.d;
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
	REP( i , R ) REP( j , C ) update( i , j , 0 );

	vvi dist( R , vi( C , INF ) );
	priority_queue< Node > Q;
	Q.push( Node( sx , sy , A[ 0 ][ sx ][ sy ] ) );
	update( sx , sy , 1 );
	dist[ sx ][ sy ] = A[ 0 ][ sx ][ sy ];
	

	while( !Q.empty() ){
		Node p = Q.top();  Q.pop();
		int x = p.x , y = p.y;
		if( abs(x - tx) <= A[ 1 ][ x ][ y ] && abs(y - ty) <= A[ 2 ][ x ][ y ] ) 
			return dist[ x ][ y ];
		while( 1 ){
			int nx , ny;
			get( x , y , nx , ny );
			if( nx == -1 ) break;
			dist[ nx ][ ny ] = dist[ x ][ y ] + A[ 0 ][ nx ][ ny ];
			Q.push( Node( nx , ny , dist[ nx ][ ny ] ) );
			update( nx , ny , 1 );
		}
	}
	return -1;
}

int main(){
	int len;
	while( sc( R ) == 1 ){
		sc( C ) , sc( len );
		n = R , m = C;
		REP( k , 3 ) REP( i , R ) REP( j , C ) sc( A[ k ][ i ][ j ] );
		vi x( len ) , y( len );
		REP( i , len ) sc( x[ i ] ) , sc( y[ i ] ) , x[ i ] -- , y[ i ] --;
		vi vec;
		REP( i , len - 1 )
			vec.pb( solve( x[ i ] , y[ i ] , x[ i + 1 ] , y[ i + 1 ] ) );
		REP( i , SZ(vec) ) printf( "%d%c" , vec[ i ] , (i + 1 == SZ(vec) ? 10 : 32) );
	}
}




