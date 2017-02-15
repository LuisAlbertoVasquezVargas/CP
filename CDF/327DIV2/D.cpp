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
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double ld;

ld const EPS = 1e-8;
struct Point{
	ld x , y;
	Point(){ x = y = 0; }
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	ld dist(){  return hypot( x , y ); }
	Point unit(){ ld k  = dist() ; return abs( k ) < EPS ? Point():Point( x/k , y/k ); }
	Point ort(){ return Point( -y , x ); }
};
typedef Point Vector;
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator * ( const Point &A , const ld &k ){ return Point( A.x * k , A.y * k ); }

ld dot( const Point &A , const Point &B ){ return A.x * B.x + A.y * B.y ; }

ld solveLinear( ld a , ld b , ld tope ){
	ld x = -b/a;
	if( x >= tope - EPS ) return 0;
	return -1;
}
ld solveQuad( ld a , ld b , ld c , ld tope ){
	//DEBUG( a );
	if( abs( a ) < EPS ) return solveLinear( b , c , tope );
	ld disc = b * b - 4 * a * c;
	if( disc < -EPS ) return -1;
	if( disc < 0 ) disc = 0;
	
	ld x1 = ( -b + sqrt( disc ) ) / (2.0 * a) ;
	ld x2 = ( -b - sqrt( disc ) ) / (2.0 * a) ;
	//DEBUG2( x1 , x2 );
	if( x1 >= tope - EPS && x2 >= tope - EPS ){
		return min( x1 , x2 );
	}
	if( x1 >= tope - EPS ) return x1;
	if( x2 >= tope - EPS ) return x2;
	return -1;
}
void print( ld x ){
	printf( "%.15f\n" , (double)x );
}
int main(){
	int x1 , y1 , x2 , y2;
	while( cin >> x1 >> y1 >> x2 >> y2 ){
		int vmax , T;
		cin >> vmax >> T;
		int vx , vy , wx , wy;
		cin >> vx >> vy >> wx >> wy;
		
		Point A( x1 , y1 ) , B( x2 , y2 );
		Vector V( vx , vy ) , W( wx , wy );
		//V = V.unit() , W = W.unit();
		ld cost1 = dot( (B - A).unit() , V.unit() );
		ld modV = V.dist();
		ld dAB = (B - A).dist();
		ld temp = solveQuad( (ld)vmax * vmax  - modV * modV , 2.0 * modV * dAB * cost1 , - dAB * dAB , 0 );
		if( temp >= 0 && temp < T ){
			print( temp );
			continue;
		}
		Point C = A + (V * T);
		ld cost2 = dot( (B - C).unit() , W.unit() );
		ld dCB = (B - C).dist();
		ld modW = W.dist();
		temp = solveQuad( (ld)vmax * vmax  - modW * modW , 2.0 * modW * dCB * cost2 + 2.0 * T * modW * modW  , - dCB * dCB -  modW * modW * T * T - 2.0 * modW * dCB * cost2 * T , T );
		//DEBUG( T );
		print( temp );
	}
}





