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
typedef vector< ld > vld;
typedef pair< int , int > pii;
typedef vector< int > vi;

const ld EPS = 1e-6;
bool equals( const ld &x , const ld &y ){ return abs( x - y ) < EPS;}
inline bool Less( const ld &x , const ld &y ){ return x < y - EPS;}
inline bool LessOrEquals( const ld &x , const ld &y ){ return x < y + EPS;}
struct Point{
    ld x , y;
    Point(){ x = y = 0;}
    Point( ld x , ld y ) : x( x ) , y( y ){}
    Point ort(){ return Point( -y , x );}
    ld dist(){ return hypot( x , y );}
    ld dist2(){ return x * x + y * y ;}
    Point unit(){ ld r = dist(); return equals( r , 0 ) ? Point() : Point( x / r , y / r );}
};
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator * ( const Point &A , const ld &K ){ return Point( A.x * K , A.y * K );}
ld dist( const Point &A , const Point &B ){
	return (A - B).dist();
}
typedef Point Vector;
vector <Point> circleCircleIntersection(Point O1, ld r1, Point O2, ld r2)
{
    vector <Point> X;
    ld d = dist(O1, O2);
    if(d > r1 + r2 || d < max(r2, r1) - min(r2, r1)) return X;
    else
    {
        ld a = (r1*r1 - r2*r2 + d*d) / (2.0*d);
        ld b = d - a;
        ld c = sqrt(abs(r1*r1 - a*a));
        Vector V = (O2-O1).unit();
        Point H = O1 + V * a;
        X.push_back(H + V.ort() * c);
        if(c > EPS) X.push_back(H - V.ort() * c);
    }
    return X;
}
 
int main(){
	int n;
	while( sc( n ) == 1 ){
		vector< Point > P;
		vld R;
		REP( i , n ){
			int x , y , r;
			sc( x ) , sc( y ) , sc( r );
			P.pb( Point( x , y ) );
			R.pb( r );
		}
		vector< Point > I( P );
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++j ){
				vector <Point> cur = circleCircleIntersection( P[ i ] , R[ i ] , P[ j ] , R[ j ] );
				for( auto p : cur ) I.pb( p );
			}
		int ans = 1 ;
		for( auto q : I ){
			int cnt = 0;
			REP( i , SZ( P ) ){
				Point p = P[ i ];
				if( LessOrEquals( dist( p , q ) , R[ i ] ) ) cnt ++;
			}
			ans = max( ans , cnt );
		}
		printf( "%d\n" , ans );
	}
}


