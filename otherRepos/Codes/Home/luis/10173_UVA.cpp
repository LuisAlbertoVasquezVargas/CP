#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define all( v ) v.begin() , v.end()

#define test puts( "****************test************" );
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define EPS (1e-8)
#define INF (1e100)

typedef pair< int , int > pii;
typedef long double ld;
typedef vector< int > vi;
typedef vector< pii > vpii;
struct Point
{
	ld x , y;
	Point(){}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	Point ort(){ return Point( -y , x ); }
	ld dist(){ return sqrt( x*x + y*y ); }
	void read(){ cin >> x >> y;}
};
bool operator < ( const Point &A , const Point &B ){ return abs( A.x - B.x ) < EPS ? A.y < B.y - EPS : A.x < B.x - EPS;}
Point operator * ( const Point &A , const ld k ){ return Point( A.x * k , A.y * k );}
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){ 
	return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}
typedef vector< Point >Polygon;

Polygon convexHull( Polygon P )
{
	sort( all( P ) );
	int nP = P.size() , k = 0;
	Point H[ nP << 1 ];
	REP( i , nP )
	{
		while( k >= 2 && area( H[ k - 2 ] , H[ k - 1 ] , P[ i ] ) < EPS ) k--;
		H[ k++ ] = P[ i ];
	}
	for( int i = nP - 2 , sz = k; i >= 0 ; --i )
	{
		while( k > sz && area( H[ k - 2 ] , H[ k - 1 ] , P[ i ] ) < EPS ) k--;
		H[ k++ ] = P[ i ];
	}
	if( k == 0 ) return Polygon();
	return Polygon( H , H + k - 1 );
}

int main()
{
	int n ;
	while( cin >> n )
	{
		if( n == 0 )break;
		Polygon P( n );
		REP( i , n ) P[ i ].read();
		P = convexHull( P );
		int nP = P.size();
		if( nP <= 2 )
		{
			puts( "0.0000" );
			continue;
		}
		vpii antipodalPairs;
		for( int i = 0 , j = 2 ; i < nP ; ++i )
		{
			while( area( P[ i ] , P[ ( i + 1 )%nP ] , P[ ( j + 1 )%nP ] ) > area( P[ i ] , P[ ( i + 1 )%nP ] , P[ j ] ) + EPS ) j = ( j + 1 )%nP;			
			antipodalPairs.pb( mp( i , j ) );
		}
		int pairs = antipodalPairs.size();
		ld best = INF;
		
		REP( k , pairs )
		{
			//test
			/// i  , i + 1 , j 
			int i = antipodalPairs[ k ].fi , j = antipodalPairs[ k ].se;
			Point A = P[ i ] , B = P[ ( i + 1 )%nP ] , X , Y , Z;
			Z = lineIntersection( A , B , P[ j ] , P[ j ] + ( B - A ).ort() );
			ld maxi = -INF , mini = INF;
			REP( u , nP )
			{
				//if( u == i || u == ( i + 1 )%nP ) continue;
				Point C = lineIntersection( A , B , P[ u ] , P[ u ] + ( B - A ).ort() );
				ld t = ( A - B ).x != 0 ? ( C - B ).x/( A - B ).x : ( C - B ).y/( A - B ).y;
				//cout << t << endl;
				if( t > maxi )
					maxi = t , X = C;
				if( t < mini )
					mini = t , Y = C;
			}
			//test
			ld H = ( Y - X ).dist();
			ld W = ( Z - P[ j ] ).dist();
			/*cout << A.x << " " << A.y << endl;
			cout << B.x << " " << B.y << endl;
			cout << P[ j ].x << " " << P[ j ].y << endl;
			cout << X.x << " " << X.y << endl;
			cout << Y.x << " " << Y.y << endl;
			cout << W << " " << H  << endl;*/
			best = min( best , W*H );
		}
		printf( "%.4f\n" , double( best ) );
	}
}
