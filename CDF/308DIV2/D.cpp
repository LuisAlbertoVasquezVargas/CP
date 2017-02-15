#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define INF (1<<29)
#define DEBUG( x ) cerr << #x << " " << (x) << endl;
#define EPS (1e-8)
#define PI acos(-1.0)
#define Vector Point

typedef vector< int > vi;
typedef vector< string > vs;
typedef long long ll;
typedef vector< ll > vll;
typedef long double ld;
typedef vector< ld > vld;

inline bool equals( ld x , ld y ){ return abs( x - y ) < EPS; }
inline bool Less( ld x , ld y ){ return x < y - EPS; }
inline bool LessOrEquals( ld x , ld y ){ return Less( x , y ) || equals( x , y ); }
struct Point{
	ld x , y;
	Point(){ x = y = 0; }
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	ld arg(){ return atan2( y , x ); }	
	ld get_angle(){ 
		ld t = arg();
		if( equals( t , PI ) ) return 0;
		if( Less( t , 0.0 ) ) return t + PI ; 
		return t;
	}
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
ll C3( ll n ){
	return (n * (n - 1) * (n - 2)) / 6LL;
}
ll C2( ll n ){
	return (n * (n - 1)) / 2LL;
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		vi X( n ) , Y( n );
		vector< Point > P;
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			X.pb( x ) , Y.pb( y );
			P.pb( Point( x , y ) );
		}
		ll ans = C3( n ) , cnt = 0;
		//DEBUG( C3( n ) );
		REP( i , n ){
			vld angles;
			REP( j , n )
				if( j != i ){
					Vector V = P[ j ] - P[ i ];
					angles.pb( V.get_angle() );
				}
			sort( all( angles ) );
			REP( a , SZ( angles ) ){
				int ind;
				for( int b = a ; b < SZ(angles) ; ++b )
					if( equals( angles[ a ] , angles[ b ] ) ) ind = b;
					else break;
				int len = ind - a + 1;
				cnt += C2( len );
				//DEBUG( C2( len ) );
				a = ind;
			}
		}
		cnt /= 3;
		ans -= cnt;
		cout << ans << '\n';
	}
}


