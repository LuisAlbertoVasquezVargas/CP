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

const int N = 500;
const int INF = INT_MAX/2;

//v , r , c
int A[ 3 ][ N + 1 ][ N + 1 ];
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


int getS( int lox , int loy , int hix , int hiy ){
	return query( hix , hiy ) - query( hix , loy - 1 ) - query( lox - 1 , hiy ) + query( lox - 1 , loy - 1 );
}
void get2( int x , int loy , int hiy , int &nx , int &ny ){
	nx = x;
	if( getS( x , hiy , x , hiy ) ){
		ny = hiy;
		return;
	}
	int lo = loy , hi = hiy;
	while( hi - lo > 1 ){
		int med = (lo + hi) >> 1;
		if( getS( x , med , x , hiy ) == 0 ) hi = med;
		else lo = med;
	}
	ny = lo;
}
void get( int x , int y , int &nx , int &ny ){
	int lox = max( 0 , x - A[ 1 ][ x ][ y ] );	
	int hix = min( R - 1 , x + A[ 1 ][ x ][ y ] );
	int loy = max( 0 , y - A[ 2 ][ x ][ y ] );	
	int hiy = min( C - 1 , y + A[ 2 ][ x ][ y ] );
	
	if( !getS( lox , loy , hix , hiy ) ){
		nx = ny = -1;
		return;
	}
	if( getS( hix , loy , hix , hiy ) ){
		get2( hix , loy , hiy , nx , ny );
		return;
	}
	int lo = lox , hi = hix;
	while( hi - lo > 1 ){
		int med = ((lo + hi) >> 1);
		if( getS( med , loy , hix , hiy ) == 0 ) hi = med;
		else lo = med;
	}
	get2( lo , loy , hiy , nx , ny );
	
}
struct Node{
	int x , y , d;
	Node(){}
	Node( int x , int y , int d ) : x( x ) , y( y ) , d( d ){}
};
bool operator < ( const Node &a , const Node &b ){
	if( a.d != b.d ) return a.d > b.d;
	//return a.t > b.t;
}
void impr(){
	REP( i , R ) {
		REP( j , C ) cout << getS( i , j , i , j ) << " ";
		cout << endl;
	}
}
int solve( int sx , int sy , int tx , int ty ){
	
	clr( tree , 0 );
	REP( i , R ) REP( j , C ) update( i , j , +1 );
	/*
	test();
	DEBUG2( sx , sy );
	impr();
	test();
	*/
	int timer = 0;
	vvi dist( R , vi( C , INF ) );
	priority_queue< Node > Q;
	Q.push( Node( sx , sy , 0 ) );
	update( sx , sy , -1 );
	dist[ sx ][ sy ] = 0;
	
	//impr();
	while( !Q.empty() ){
		Node p = Q.top();  Q.pop();
		int x = p.x , y = p.y;
		if( x == tx && y == ty ) return dist[ tx ][ ty ];
		while( 1 ){
			int nx , ny;
			get( x , y , nx , ny );
			if( nx == -1 ) break;
			//if( dist[ nx ][ ny ] != INF ) continue;
			//DEBUG2( x ,y );
			//DEBUG2( nx , ny );
			if( dist[ nx ][ ny ] > dist[ x ][ y ] + A[ 0 ][ x ][ y ] ){
				dist[ nx ][ ny ] = dist[ x ][ y ] + A[ 0 ][ x ][ y ];
				Q.push( Node( nx , ny , dist[ nx ][ ny ] ) );
				update( nx , ny , -1 );
			}
			//impr();
		}
	}
	return -1;
}

int main(){
	int n;
	while( sc( R ) == 1 ){
		sc( C ) , sc( n );
		REP( k , 3 ) REP( i , R ) REP( j , C ) sc( A[ k ][ i ][ j ] );
		vi x( n ) , y( n );
		REP( i , n ) sc( x[ i ] ) , sc( y[ i ] ) , x[ i ] -- , y[ i ] --;
		vi vec;
		REP( i , n - 1 )
			vec.pb( solve( x[ i ] , y[ i ] , x[ i + 1 ] , y[ i + 1 ] ) );
		REP( i , SZ(vec) ) printf( "%d%c" , vec[ i ] , (i + 1 == SZ(vec) ? 10 : 32) );
	}
}




