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

#define N 100005
#define EPS (1e-8)

typedef vector< int > vi;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef long long ll;
typedef long double ld;

struct Point{
    ll m , b;
    Point(){}
    Point( ll m , ll b ): m( m ) , b( b ) {}
    ld slope(){ return -1.0*b/m; }
};
Point operator - ( const Point &A , const Point &B ){ return Point( A.m - B.m , A.b - B.b ); }
int sz = 0;
Point H[ N + 5 ];
ll mm[ N + 5 ];
int mapa[ N + 5 ];
void add( ld m , ld b , int id ){
	Point P( m , b );
    while( sz >= 2 && ( P - H[ sz - 1 ] ).slope() - ( H[ sz - 1 ] - H[ sz - 2 ] ).slope() < EPS ) sz--;
    H[ sz ] = P;
    mapa[ sz ] = id;
    if( sz ) mm[ sz - 1 ] = ( P - H[ sz - 1 ] ).slope();
    sz ++;
}
ll eval( ll x , int &pos ){
	int ind = lower_bound( mm , mm + sz - 1 , (ld)x ) - mm;
	pos = mapa[ ind ];
	return x * H[ ind ].m + H[ ind ].b;
}
ll solve( int j , int n , vi &A ){
	if( j == 0 ) return (ll) n * A[ j ];
	ll ans = (ll) n * A[ j ];
	for( int i = 0 ; i < j ; ++i )
		ans = min( ans , n * A[ j ] + solve( i , n , A ) - (i + 1) * A[ j ] );
	return ans;
}
int main(){
	freopen( "iq.in" , "r" , stdin );
	freopen( "iq.out" , "w" , stdout );
	// the slops is always in decrecent form
	// DP( j ) = min ( i < j ) ( DP( i ) + b[ i ] a[ j ] )      b[ i ] > b[ j ] 
	int n;
	while( sc( n ) == 1 ){
		if( !n ) break;
		vpii v;
		REP( i , n ) {
			int x;
			sc( x );
			v.pb( mp( x , i ) );
		}
		sort( all( v ) );
		vi A( n );
		REP( i , n ) A[ i ] = v[ i ].fi;
		
		sz = 0;
		vector< ll > DP( n );
		vi pa( n );
		add( 0 , 0 , -1 );
		for( int j = 0 ; j < n ; ++j ){
			int id;
			DP[ j ] = eval( A[ j ] , id ) + (ll) n * A[ j ];
			pa[ j ] = id;
			add( -(j + 1) , DP[ j ] , j );
		}
		int u = n - 1;
		vi vec;
		while( u != -1 ){
			vec.pb( u );
			u = pa[ u ];
		}
		vec.pb( -1 );
		reverse( all( vec ) );
		cout << DP[ n - 1 ] << '\n';
		printf( "%d\n" , SZ(vec) - 1 );
		REP( i , SZ( vec ) - 1 ){
			int x = vec[ i ] + 1 , y = vec[ i + 1 ];
			printf( "%d" , y - x + 1 );
			for( int k = x ; k <= y ; ++k ){
				printf( " %d" , v[ k ].se + 1 );
			}
			puts( "" );
		}
	}
}



