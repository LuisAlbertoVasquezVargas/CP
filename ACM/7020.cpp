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
typedef double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

ld EPS = 1e-8;
struct Point{
	typedef Point Vector;
	ld x , y;
	Point(){};
	Point( ld x , ld y ) : x( x ) , y( y ){}
	Point ort(){ return Point( -y , x );}
	Point unit(){
		ld d = hypot( x , y );
		return Point( x/d , y/d );
	}
};
typedef Point Vector;
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator * ( const Point &A , const ld &K ){ return Point( A.x * K , A.y * K );}
ld dot( const Point &A , const Point &B ){ return A.x * B.x + A.y * B.y; }

bool f( const Point &A , const Point &B , const Point &P ){
	return dot( (B - A) , (P - A) ) > -EPS && dot( (A - B) , (P - B) ) > EPS;
}
bool g( const Point &A , const Point &B , const Point &P ){
	return dot( (B - A) , (P - A) ) > -EPS && dot( (A - B) , (P - B) ) > -EPS;
}
bool solve( vector< Point > &P ){
	int n = SZ( P );
	REP( i , n - 1 ){
		Point A = P[ i ] , B = P[ i + 1 ];
		for( int j = i + 2 ; j < n ; ++j ){
			Point C = P[ j ];
			if( f( A , B , C ) ) return 0;
		}

	}
	return 1;
}

int main(){
	int n;
	while( sc( n ) == 1 ){
		if( !n ) break;
		vector< Point > P;
		REP( i , n ){
			int x , y ;
			sc( x ) , sc( y );
			P.pb( Point( x , y ) );
		}
		puts( solve( P ) ? "Fair" : "Unfair" );
	}
}


