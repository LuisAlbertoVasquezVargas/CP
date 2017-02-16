#include<bits/stdc++.h>
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

#define MAX 300000

typedef vector< int > vi;
typedef long long ll;

inline bool equals( ll x , ll y ){ return x == y; }
inline bool Less( ll x , ll y ){ return x < y; }
inline bool LessOrEquals( ll x , ll y ){ return x <= y; }
struct Point{
    ll x , y;
    Point(){ x = y = 0; }
    Point( ll x , ll y ) : x( x ) , y( y ) {}
    ll dist(){ return max( abs( x ) , abs( y )); }
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
bool operator ==(const Point &A, const Point &B){ return equals( A.x , B.x ) && equals( A.y , B.y );}
ll dist( const Point &A , const Point &B ){ return (B - A).dist();}
bool XYorder( Point P1 , Point P2 ){
    if( !equals( P1.x , P2.x ) ) return Less( P1.x , P2.x );
    return Less( P1.y , P2.y );
}
bool YXorder(Point P1, Point P2){
	if( !equals( P1.y , P2.y ) ) return Less( P1.y , P2.y );
	return Less( P1.x , P2.x );
}
ll closest_recursive( vector < Point > vx , vector < Point > vy ){
    if( SZ( vx ) == 1 ) return 1e16;
    if( SZ( vx ) == 2 ) return dist( vx[ 0 ] , vx[ 1  ] );
    Point cut = vx[ SZ( vx ) >> 1 ];
    
    vector <Point> vxL, vxR;
    REP( i , SZ( vx ) )
        if( Less( vx[i].x , cut.x ) || ( equals( vx[i].x , cut.x ) && LessOrEquals( vx[i].y , cut.y ) ) )
            vxL.pb( vx[ i ] );
        else vxR.pb( vx[ i ] );
    
    vector < Point > vyL, vyR;
    REP( i , SZ( vy ) )
    	if( Less( vy[i].x , cut.x ) || ( equals( vy[i].x , cut.x ) && LessOrEquals( vy[i].y , cut.y ) ) )
            vyL.pb( vy[ i ] );
        else vyR.pb( vy[ i ] );
    
    ll dL = closest_recursive( vxL , vyL );
    ll dR = closest_recursive( vxR , vyR );
    ll d = min( dL , dR );
    
    vector <Point> b;
    REP( i , SZ( vy ) )
        if( abs( vy[ i ].x - cut.x ) <= d )
            b.push_back( vy[ i ] );
    
    REP( i , SZ( b ) )
        for(int j = i + 1 ; j < SZ( b ) && (b[ j ].y - b[ i ].y) <= d ; j++)
            d = min( d , dist( b[ i ] , b[ j ] ) );
    
    return d;
}
ll closest(vector <Point> points )
{
    vector <Point> vx = points, vy = points;
    sort( all( vx ) , XYorder );
    sort( all( vy ) , YXorder);
    REP( i , SZ( vx ) - 1 )
        if( vx[ i ] == vx[ i + 1 ] )
            return 0;
    return closest_recursive( vx , vy );
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		vector< Point > P;
		REP( i , n ) {
			int x , y;
			sc( x ) , sc( y );
			P.pb( Point( x , y ) );
		}
		ll ans = closest( P );
		printf( "%lld\n" , ans );
	}
}


