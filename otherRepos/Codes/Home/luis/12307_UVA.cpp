#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)v.size())

#define EPS (1e-8)
typedef long double ld;
bool equals( ld x , ld y ){ return abs( x - y ) < EPS; }
bool Less( ld x , ld y ){ return x < y - EPS; }
bool LessEqual( ld x , ld y ){ return x < y + EPS; }
struct Point{
	ld x , y;
	Point(){}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	Point ort(){ return Point( -y , x ); }
	ld dist(){ return sqrt( abs( x * x + y * y ) ); }
};
typedef Point Vector;
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator *( const Point &A , const ld &k ){ return Point( A.x * k , A.y * k );}
bool operator < ( const Point &A , const Point &B ){
	if( !equals( A.x , B.x ) ) return Less( A.x , B.x );
	return Less( A.y , B.y );
}
ld dist( const Point &A , const Point &B ){ return ( B - A ).dist();}
ld cross( Point A , Point B ){ return A.x * B.y - A.y * B.x;}
ld area( Point A , Point B , Point C ){ return cross( B - A , C - A ); }

Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){ 
	return A + ( B - A ) * ( cross( C - A , D - C ) / cross( B - A , D - C ) );
}
bool parallel( Vector A , Vector B ){
	return equals( cross( A , B )  , 0.0 );
}
ld proyection( Point A , Point B , Point C ){
	Point I = lineIntersection( A , B , C , C + (B - A).ort() );
	bool op1 = area( A , A + (B - A).ort() , B ) > 0;
	bool op2 = area( A , A + (B - A).ort() , I ) > 0;
	if( op1 ^ op2 ) return -dist( I , A );
	return dist( I , A );
}
ld high( Point A , Point B , Point C ){
	Point I = lineIntersection( A , B , C , C + (B - A).ort() );
	return dist( I , C );
}
vector< Point > convexHull( vector< Point > P ){
	Point H[ SZ(P) << 1 ];
	sort( all( P ) );
	int sz = 0;
	REP( i , SZ( P ) ){
		while( sz >= 2 && area( H[ sz - 2 ] , H[ sz - 1 ] , P[ i ] ) < EPS ) sz --;
		H[ sz ++ ] = P[ i ];
	}
	for( int i = SZ( P ) - 2 , m = sz ; i >= 0 ; --i ){
		while( sz > m && area( H[ sz - 2 ] , H[ sz - 1 ] , P[ i ] ) < EPS ) sz --;
		H[ sz ++ ] = P[ i ];
	}
	return vector< Point > ( H , H + sz - 1 );
}
int n;
int next( int p ){ return (p == n - 1) ? 0 : (p + 1);}
int prev( int p ){ return p == 0 ? (n - 1) : (p - 1);}
int main(){
	while( sc( n ) == 1 ){
		if( !n ) break;
		vector< Point > P;
		REP( i , n ){
			double x , y;
			scanf( "%lf %lf" , &x , &y );
			P.pb( Point( x , y ) );
		}
		P = convexHull( P );
		n = SZ( P );

		ld ans1 = 1e100 , ans2 = 1e100;

		for( int p = 0 , q = 1 , r = 1 , t = -1 ; p < n ; ++p ){
			while( LessEqual( high( P[ p ] , P[ next( p ) ] , P[ q ] ) , high( P[ p ] , P[ next( p ) ] ,  P[ next( q ) ] ) ) ) q = next( q );
			if( t == -1 ) t = q;
			while( LessEqual( proyection( P[ p ] , P[ next( p ) ] , P[ r ] ) , proyection( P[ p ] , P[ next( p ) ] ,  P[ next( r ) ] ) ) )
				r = next( r );
			while( LessEqual( proyection( P[ p ] , P[ next( p ) ] , P[ next( t ) ] ) , proyection( P[ p ] , P[ next( p ) ] ,  P[ t ] ) ) )
				t = next( t );

			Point A , B , C;
			Vector V = P[ next( p ) ] - P[ p ];
			Vector W = V.ort();

			A = lineIntersection( P[ p ] , P[ p ] + V , P[ t ] , P[ t ] + W );
			B = lineIntersection( P[ p ] , P[ p ] + V , P[ r ] , P[ r ] + W );
			C = lineIntersection( P[ q ] , P[ q ] + V , P[ r ] , P[ r ] + W );
			ans1 = min( ans1 , abs( area( A , B , C ) ) );
			ans2 = min( ans2 , abs( dist( A , B ) + dist( B , C ) ) );

		}
		printf( "%.2f %.2f\n" , (double)ans1 , (double)(2.0*ans2) );
	}
}

