#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )

#define mp make_pair
#define fi first
#define se second

#define test puts( "*****************test*******************" );

typedef pair< int , int > pii;

#define N 1000
#define INF (1<<30)

struct Node{
	int maxi , mini;
	Node(){
		maxi = -INF;
		mini = INF;
	}
	Node( int val ){
		maxi = mini = val;
	}
};
Node operator + ( const Node &a , const Node &b ){
	Node c;
	c.maxi = max( a.maxi , b.maxi );
	c.mini = min( a.mini , b.mini );
	return c;
}

Node T[ 4 * N + 5 ][ 4 * N + 5 ];
int n , m ;

Node QueryY( int nodex , int nodey , int ay , int by , int ylo , int yhi ){
	if( ay > yhi || ylo > by ) return Node();
	if( ay >= ylo && yhi >= by ) return T[ nodex ][ nodey ];
	int v1 = 2 * nodey + 1 , v2 = v1 + 1 , med = ( ay + by )/2;
	return 	QueryY( nodex , v1 , ay , med , ylo , yhi ) + 
			QueryY( nodex , v2 , med + 1 , by , ylo , yhi );
}

Node QueryX( int nodex , int ax , int bx , int xlo , int xhi , int ylo , int yhi ){
	if( ax > xhi || xlo > bx ) return Node();
	if( ax >= xlo && xhi >= bx ) return QueryY( nodex , 0 , 0 , m - 1 , ylo , yhi );
	int v1 = 2 * nodex + 1 , v2 = v1 + 1 , med = ( ax + bx )/2;
	return 	QueryX( v1 , ax , med , xlo , xhi , ylo , yhi ) + 
			QueryX( v2 , med + 1 , bx , xlo , xhi , ylo , yhi );
}

void updateY( int nodex , int ax , int bx , int nodey , int ay , int by , int x , int y , int val ){
	if( ay > y || y > by ) return;
	if( ay == by ){
		if( ax == bx )
			T[ nodex ][ nodey ] = Node( val );
		else T[ nodex ][ nodey ] = T[ 2 * nodex + 1 ][ nodey ] + T[ 2 * nodex + 2 ][ nodey ];
		return;
	}
	int v1 = 2 * nodey + 1 , v2 = v1 + 1 , med =( ay + by )/2;
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
	int v1 = 2 * nodex + 1 , v2 = v1 + 1 , med = ( ax + bx )/2;
	updateX( v1 , ax , med , x , y , val );
	updateX( v2 , med + 1 , bx , x , y , val );
	updateY( nodex , ax , bx , 0 , 0 , m - 1 , x , y , val );
}

int main(){
	ios_base :: sync_with_stdio( 0 );	
	cin >> n >> m;
	REP( i , n )REP( j , m ){
		int val ;
		cin >> val;
		updateX( 0 , 0 , n - 1 , i , j , val );
	}
	int Q;
	cin >> Q;
	while( Q-- ){
		char c;
		cin >> c;
		if( c == 'q' ){
			int xlo , ylo , xhi , yhi;
			cin >> xlo >> ylo >> xhi >> yhi;
			xlo -- , ylo-- , xhi -- , yhi--;
			Node q = QueryX( 0 , 0 , n - 1 , xlo , xhi , ylo , yhi );
			cout << q.maxi << " " << q.mini << '\n';
		}else{
			int x , y , val;
			cin >> x >> y >> val;
			x-- , y--;
			updateX( 0 , 0 , n - 1 , x , y , val );
		}
	}
}
