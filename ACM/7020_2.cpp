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

struct Point{
	typedef Point Vector;
	ll x , y;
	Point(){};
	Point( ld x , ld y ) : x( x ) , y( y ){}
};
typedef Point Vector;
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator * ( const Point &A , const ld &K ){ return Point( A.x * K , A.y * K );}
ll dot( const Point &A , const Point &B ){ return A.x * B.x + A.y * B.y; }

bool f( const Point &A , const Point &B , const Point &P ){
	return dot( (B - A) , (P - A) ) >= 0 && dot( (A - B) , (P - B) ) > 0;
}
bool solve( vector< Point > &P ){
	int n = SZ( P );
	REP( i , n - 1 ){
		for( int j = i + 2 ; j < n ; ++j ){
			if( f( P[ i ] , P[ i + 1 ] , P[ j ] ) ) return 0;
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


