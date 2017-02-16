#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<ctime>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)v.size())

#define N 50
#define M 3000
#define EPS (1e-8)

typedef double ld;

inline bool LessEqual( const ld &x , const ld &y ){ return x < y + EPS;}
inline bool Less( const ld &x , const ld &y ){ return x < y - EPS;}
inline bool equals( const ld &x , const ld &y ){ return abs( x - y ) < EPS; }
struct Point{
	ld x , y;
	Point(){}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	Point ort(){ return Point( -y , x );}
	ld dist(){ return hypot( x , y ); }
	ld dist2(){ return  x * x + y * y; }
	Point unit(){ ld r = dist(); return Point( x/r , y/r );}
};
typedef Point Vector;
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator * ( const Point &A , const ld &K ){ return Point( A.x * K , A.y * K );}
ld dist( const Point &A , const Point &B ){ return (B - A).dist(); }
ld dot( const Point &A , const Point &B ){ return A.x * B.x + A.y * B.y;}
ld cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x;}
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}

Point P[ (N<<1) + 5 ];
ld dAB[ N + 5 ] , dBC[ N + 5 ] , dCA[ N + 5 ];
ld W[ N + 5 ][ M + 5 ];
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}
bool between( const Point &A , const Point &B , const Point &P ){
	return 	min( A.x , B.x ) < P.x + EPS && P.x < max( A.x , B.x ) + EPS &&
			min( A.y , B.y ) < P.y + EPS && P.y < max( A.y , B.y ) + EPS;
}
bool onSegment( const Point &A , const Point &B , const Point &P ){
	return abs( area( A , B , P ) ) < EPS && between( A , B , P );
}
vector< Point > lineCircleIntersection( Point A , Point B , Point O , ld R ){
	Vector V = ( B - A ).ort();
	Point H = lineIntersection( A , B , O , O + V );
	if( R < dist( O , H ) - EPS ) return vector< Point >();
	if( abs( R - dist( O , H ) ) < EPS ) return vector< Point >( 1 , H );
	vector< Point > ans;
	Point P , Q;
	Vector W = ( B - A ).unit();
	ld d = sqrt( R * R - ( O - H ).dist2() );
	P = H + W*d , Q = H - W*d;
	ans.pb( P ) , ans.pb( Q );
	return ans;
}
ld solve( const Point &A , const Point &B , const Point O , const ld &R ){
	vector< Point > V = lineCircleIntersection( A , B , O , R );
	ld maxi = 0;
	REP( i , SZ( V ) )
		if( onSegment( A , B , V[ i ] ) ) maxi = max( maxi , dist( O  , B ) + dist( V[ i ] , B ) - R );
	return maxi;
}

int last[ N + 5 ];
ld DP[ N + 5 ][ M + 5 ];
//ld DP[ 2 ][ M + 5 ];
int main(){
	double timer = clock();
	int n , m , x , y, tc = 0;	
	while( sc( n ) == 1 ){
		sc( m );
		if( n == 0 && m == 0 ) break;
		REP( i , (n<<1) + 1 ){
			sc( x ) , sc( y );
			P[ i ] = Point( x , y ); 
		}
		
		REP( i , n ){
			Point A = P[ (i<<1) ] , B = P[ (i<<1) + 1 ] , C = P[ (i<<1) + 2 ];
			dAB[ i ] = dist( A , B ) , dBC[ i ] = dist( B , C ) , dCA[ i ] = dist( C , A );
			ld cost = dot( (C - B).unit()  , (A - B).unit() );
			ld x = 1.0/sqrt( 2.0 * ( 1 - cost ) );
			ld L = min( dBC[ i ]  , dAB[ i ] );
			if( LessEqual( x , L ) ) W[ i ][ 1 ] = 2.0*x - 1.0;
			else W[ i ][ 1 ] = max( solve( A , B , C , 1 ) , solve( C , B , A , 1 ) );
			for( int k = 2 ; k <= m ; ++k ){
				if( LessEqual( x * k , L ) ) W[ i ][ k ] = W[ i ][ 1 ] * k;
				else W[ i ][ k ] = max( solve( A , B , C , k ) , solve( C , B , A , k ) );
			}
			last[ i ] = 0;
			for( int k = m ; k >= 1 ; --k ){
				if( W[ i ][ k ] > EPS ) {
					last[ i ] = k;
					break;
				}
			}
		}
		for( int cnt = 0 ; cnt <= m ; ++cnt )
			DP[ n ][ cnt ] = 0;
		for( int pos = n - 1 ; pos >= 0 ; --pos ){
			for( int cnt = 0 ; cnt <= m ; ++cnt ){
				DP[ pos ][ cnt ] = DP[ (pos + 1) ][ cnt ];
				for( int k = 1 ; k <= last[ pos ] && k <= cnt; ++k )
					DP[ pos ][ cnt ] = max( DP[ pos ][ cnt ] , W[ pos ][ k ] + DP[ (pos + 1) ][ cnt - k ] );
			}
		}
		
		int ans = 0 , pos = 0 , cnt = m;
		
		while( 1 ){
			if( pos == n ) break;
			ld &dev = DP[ pos ][ cnt ];
			if( equals( dev , DP[ pos + 1 ][ cnt ] ) ) {
				pos ++;
				continue;
			}
			for( int k = 1 ; k <= last[ pos ] && k <= cnt; ++k )
				if( equals( dev , W[ pos ][ k ] + DP[ pos + 1 ][ cnt - k ] ) ){
					ans += k;
					pos ++;
					cnt -= k;
					break;
				}
		}
		printf( "Case %d: %d meters used saving %.2f meters\n" , ++tc , ans , (double)DP[ 0 ][ m ] );
		
	}
	
	timer = clock() - timer;
	//printf( "%.10f\n" , timer/CLOCKS_PER_SEC );
	
}

