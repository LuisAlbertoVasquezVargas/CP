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

struct line{
    ll m , b ;
    line(){}
    line( ll m , ll b ) : m( m ) , b( b ) {}
};

line H[N + 5];
int sz,pos;

bool check(line &l1, line &l2, line &l3){
    return (ld)(l3.b - l2.b) * (l1.m - l3.m) >= (ld)(l3.b - l1.b) * (l2.m - l3.m);
}

void add( ll a , ll b){
    line l( a , b );
    while( sz >= 2 && !check( H[sz - 2] , H[sz - 1] , l ) ) --sz;
    H[ sz ++ ] = l;
}

ll eval( int ind , ll x ){
    return H[ind].m * x + H[ind].b;
}

ll query( ll x ){
    while(pos + 1 < sz && eval(pos,x) > eval(pos + 1,x)) ++pos;
    return eval(pos,x);
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
			add( h[ i ] , DP[ i - 1 ] );
			DP[ i ] = query( w[ i ] );
		}
		cout << DP[ n ] << '\n';
	}
}


