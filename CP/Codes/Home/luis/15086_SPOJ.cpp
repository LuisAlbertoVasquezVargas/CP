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

#define N 1000000
#define MAXVAL 1000000
#define EPS (1e-8)

typedef long long ll;
typedef long double ld;
typedef vector< int > vi;
typedef pair< int , int > pii;
typedef vector< pii > vpii;

struct Point{
    ll x , y;
    Point(){}
    Point( ll x , ll y ): x( x ) , y( y ) { }
};
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
int sz = 0;
Point H[ N + 5 ];
ll m[ N + 5 ];
inline bool valid( const Point &L2 , const Point &L1 , const Point &L ){
    return (ld)(L2.y - L.y)*(L1.x - L.x) <= (ld)(L1.y - L.y)*(L2.x - L.x) + EPS;
}
void add( Point P ){
    while( sz >= 2 && valid( H[ sz - 2 ] , H[ sz - 1 ] , P ) ) sz--;
    H[ sz ] = P;
	if( sz ) m[ sz - 1 ] = -( P.y - H[ sz - 1 ].y )/( P.x - H[ sz - 1 ].x );
    
    sz ++;
}
ll eval( ll x ){
	int pos = lower_bound( m , m + sz - 1 , x ) - m;
	return H[ pos ].x * x + H[ pos ].y;
}
ll DP[ N + 5 ];
ll w[ N + 5 ] , h[ N + 5 ];
int main(){
	int n , x , y;
	while( sc( n ) == 1 ){
		vpii v;
		REP( i , n ){
			sc( x )  , sc( y );
			v.pb( mp( y , x ) );
		}
		sort( all( v ) );
		set< pii > SET;
		REP( i , SZ( v ) ){
			int x = v[ i ].se , y = v[ i ].fi;
			set< pii > :: iterator it = SET.lower_bound( mp( x , 1e6 + 5 ) );
			SET.erase( SET.begin() , it );
			SET.insert( mp( x , y ) );
		}

		v = vpii( all( SET ) );
		n = SZ( SET );
		REP( i , n ) w[ i + 1 ] = v[ i ].fi , h[ i + 1 ] = v[ i ].se;
		sz = 0;
		DP[ 0 ] = 0;
		for( int i = 1 ; i <= n ; ++i ){
			add( Point( h[ i ] , DP[ i - 1 ] ) );
			DP[ i ] = eval( w[ i ] );
		}
		cout << DP[ n ] << '\n';
	}
}


