#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 1000000
#define INF (1<<20)

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int , int > pii;

#define EPS (1e-8)
#define PI acos(-1.0)

#define Vector Point

typedef long double ld;

inline bool equals( ld x , ld y ){ return abs( x - y ) < EPS; }
inline bool Less( ld x , ld y ){ return x < y - EPS; }
inline bool LessOrEquals( ld x , ld y ){ return Less( x , y ) || equals( x , y ); }

struct Point{
	ld x , y;
	Point(){ x = y = 0; }
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	ld arg(){ return atan2( y , x ); }	

	ld dist2(){ return x * x + y * y; }
	ld dist(){  return hypot( x , y ); }
	Point unit(){ ld k  = dist() ; return abs( k ) < EPS ? Point():Point( x/k , y/k ); }
	Point ort(){ return Point( -y , x ); }
	void print(){ printf( "punto : %.4f %.4f\n" , double(x) , double(y) );}
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator *( const Point &A , const ld &k ){ return Point( A.x*k , A.y*k ); }
bool cmp( Point A , Point B ){ 
	ld a = A.arg() , b = B.arg();
	if( !equals( a , b ) ) return a < b ; 
	return A.dist() < B.dist();
}

ld dot( const Point &A , const Point &B ){ return A.x*B.x + A.y*B.y ; }
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }

bool collinear( vector< Point > P ){
	REP( i , SZ(P) )
		REP( j , SZ(P) )
			if( !equals( area( Point() , P[ i ] , P[ j ] ) , 0.0 ) ) return 0;
	return 1;
}
int main(){
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int n;
		cin >> n;
		vector< Point > PP;
		REP( i , n ){
			ld x , y;
			cin >> x >> y;
			PP.pb( Point( x , y ) );
		}
		if( collinear( PP ) ){
			Point p( 0 , 0 );
			REP( i , n ){
				p.x = max( p.x , abs( PP[ i ].x ) );
				p.y = max( p.y , abs( PP[ i ].y ) );
			}
			if( tc ) puts( "" );
			printf( "%.2lf\n" , (double) (p.dist() + 2.0) );
			continue;
		}
		sort( all( PP ) , cmp );
		
		ld ans = 1e60;
		REP( it , n ){
			vector< Point > P;
			REP( i , n ) P.pb( PP[ (it + i)%n ] );
			Point H[ n << 1 ];
			int k = 0;
			H[ k ++ ] = Point( 0 , 0 );
			H[ k ++ ] = P[ 0 ];
			REP( i , n ){
				while( k > 2 && area( H[ k - 2 ] , H[ k - 1 ] , P[ i ] ) < EPS ) k--;
				H[ k++ ] = P[ i ];
			}
			ld S = 0;
			REP( i , k )
				S += (H[ i ] - H[(i + 1)%k]).dist();
			ans = min( ans , S );
		}
		ans += 2;
		if( tc ) puts( "" );
		printf( "%.2lf\n" , (double) ans );
	}
}


