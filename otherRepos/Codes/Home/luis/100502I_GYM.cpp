#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define INF 1<<29

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;
typedef long double ld;
typedef vector< ld > vld;

struct frac{
    ll num , den;
	frac(){}
    frac( ll a , ll b ){
		assert( !(a == 0 && b == 0) );
		if( b == 0 ){
            num = 1 , den = 0;
        }else if( a == 0 ){
			num = 0 , den = 1;
		}else{
	        if( b < 0 ) a = -a , b = -b;
	        ll g = __gcd( abs( a ) , abs( b ) );
	        num = a/g , den = b/g;
    	}
    	
    }
};

bool operator <( const frac &a , const frac &b ){
	if( a.num != b.num ) return a.num < b.num;
	return a.den < b.den;
}
bool operator == ( const frac &A , const frac &B ){ return A.num == B.num && A.den == B.den;}

struct Point{
    ll x , y;
    Point( ll x , ll y ) : x( x ) , y( y ) {}
    ld dist(){  return hypot( (ld)x , (ld)y ); }
    ll dist2(){  return x * x + y * y; }
    frac slope(){
        return frac( y , x );
    }
};
bool operator < ( const Point &A , const Point &B ){ return A.x != B.x ? A.x < B.x : A.y < B.y; }
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
ll cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x;}
ll area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}
ll dot( const Point &A , const Point &B ){ return A.x * B.x + A.y * B.y;}
ll dist( const Point &A , const Point &B ){ return (B - A).dist();}
ll dist2( const Point &A , const Point &B ){ return (B - A).dist2();}
typedef pair< Point , Point > Line;
typedef pair< frac , Line > Line2;

bool isOrtogonal( Line L1 , Line L2 ){
    return dot( L1.fi - L1.se , L2.fi - L2.se ) == 0 ;
}
frac getDif( Line L1 , Line L2 ){
	assert( abs( area( L1.fi , L1.se , L2.fi ) ) == abs( area( L1.fi , L1.se , L2.se ) ) );
	ll S = abs( area( L1.fi , L1.se , L2.fi ) ) , D = dist2( L1.fi , L1.se ) ;
    return frac( S * S , D );
}
vector< frac > getAllDif( vector< Line > &L ){
    vector< frac > v;
    REP( i , SZ( L ) ) for( int j = i + 1 ; j < SZ( L ) ; ++j ) v.pb( getDif( L[ i ] , L[ j ] ) );
    sort( all( v ) );
    return v;
}
ll solve( vector< Line > &L1 , vector< Line > &L2 ){
    vector< frac > X = getAllDif( L1 ) , Y = getAllDif( L2 );
    ll ans = 0 ;
    REP( i , SZ( X ) ) ans += upper_bound( all( Y ) , X[ i ] ) - lower_bound( all( Y ) , X[ i ] );
    return ans;
}
int main(){
    int n;
    while( sc( n ) == 1 ){
        vector< Line2 > V;
        REP( i , n ){
            int x , y;
            sc( x ) , sc( y );
            Point A( x , y );
            sc( x ) , sc( y );
            Point B( x , y );
            Line L( A , B );
            V.pb( mp( (B - A).slope() , L ) );
        }
        sort( all( V ) );

        ll ans = 0;
        REP( i , SZ( V ) ){
            int ind;
            vector< Line > L1 , L2;
            for( int j = i ; j < SZ( V ) ; ++j )
                if( V[ i ].fi == V[ j ].fi ) ind = j , L1.pb( V[ j ].se );
                else break;
            for( int j = ind + 1 ; j < SZ( V ) ; ++j )
                if( isOrtogonal( V[ i ].se , V[ j ].se ) )
                    L2.pb( V[ j ].se );
        	ans += solve( L1 , L2 );
            i = ind;
        }
        cout << ans << '\n';
    }
}
