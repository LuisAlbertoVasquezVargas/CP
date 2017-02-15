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
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

const ld PI = acos( -1.0 );
const ld t = PI / 3.0;
const ld cost = cos( t );
const ld sint = sin( t );
struct Point{
	ld x , y;
	Point(){ x = y = 0; }
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	Point ort(){ return Point( -y , x ); }
	Point rot(){
	///// co -so (x)
	////  so    co (y)
		return Point( cost * x - sint * y , sint * x + cost * y );
	}
};
typedef Point Vector;
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator *( const Point &A , const ld &k ){ return Point( A.x * k , A.y * k ); }

ld cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }


ld area( vector<Point> &Poly ){
	int nP = Poly.size();
	ld ans = 0;
	REP( i , nP )ans += area( Point() , Poly[i] , Poly[(i+1)%nP] );
	return abs( ans );
}
ld cte = 1.1547005383792514621177360822912305593491;
int main(){
	int A[ 6 ];
	while( cin >> A[ 0 ] ){
		REP( i , 6 ){
			if( !i ) continue;
			cin >> A[ i ];
		}
		vector< Point > vec;
		Vector u( cost , sint );
		Point P;
		REP( i , 6 ){
			P = P + (u * A[ i ]);
			vec.pb( P );
			u = u.rot();
		}
		ld S = area( vec );
		//printf( "%.40f\n" , (double) (S * cte) );
		cout << (ll) round( (S * cte) ) << '\n';
	}
}


