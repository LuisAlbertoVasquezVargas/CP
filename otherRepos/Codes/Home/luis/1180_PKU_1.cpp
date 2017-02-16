#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define N 100000
#define EPS (1e-8)
#define INF (1000000000000000000LL)

typedef long long ll;
typedef long double ld;

struct line{
    ll m , b ;
    line(){}
    line( ll m , ll b ) : m( m ) , b( b ) {}
};

line H[N + 5];
int sz,pos;

bool check(line &l1, line &l2, line &l3){
    return (l3.b - l2.b) * (l1.m - l3.m) >= (l3.b - l1.b) * (l2.m - l3.m);
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
ll ST[ N + 5 ] , SF[ N + 5 ] , DP[ N + 5 ];
int main(){
	int n , S , x;
	sc( n ) , sc( S );
	REP( i , n ){
		sc( x );
		ST[ i + 1 ] = ST[ i ] + x;
		sc( x );
		SF[ i + 1 ] = SF[ i ] + x;
	}
	sz = 0;
	DP[ n + 1 ] = 0;
	for( int i = n ; i >= 1 ; --i ){
		/*
		DP[ i ] = 1LL<<62;
		for( int j = i ; j <= n ; ++j ) DP[ i ] = min( DP[ i ] , DP[ j + 1 ] + (ll)  S * ( SF[ n ] - SF[ i - 1 ] ) + ST[ j ] * ( SF[ j ]  - SF[ i - 1 ] ) );
		*/
		add( ST[ i ] , DP[ i + 1 ] + ST[ i ] * SF[ i ] );
		DP[ i ] = query( -SF[ i - 1 ] ) + (ll)  S * ( SF[ n ] - SF[ i - 1 ] );
		
	}
	cout << DP[ 1 ] << '\n';
}


