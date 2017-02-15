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

#define INF (1LL<<60)
#define N 120
#define M 1020

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< string > vs;
typedef long double ld;

int n , m , sz;
int orig[ M + 5 ] , dest[ M + 5 ] ;
ll peso[ M + 5 ];
void add_edge( int u , int v , ll w ){
	orig[ sz ] = u ;
	dest[ sz ] = v;
	peso[ sz ] = w;
	sz++;
}
vll D;
bool relax( int k ){
	int u = orig[ k ] , v = dest[ k ] , w = peso[ k ];
	if( D[ u ] + w < D[ v ] ){
		D[ v ] = D[ u ] + w;
		return 1;
	}
	return 0;
}
void init(){
	sz = 0;
}
bool bellmanFord(){
	D = vll( n , INF );
	D[ 0 ] = 0;
	REP( it , n - 1 )
		REP( i , m )
			relax( i );
	REP( i , m ) if( relax( i ) ) return 0;
	return 1;
}
ld getDist( int a , int b , vi &x , vi &y ){
	ll dx = x[ a ]- x[ b ];
	ll dy = y[ a ] - y[ b ];
	return hypot( dx , dy );
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int R , C;
		cin >> R >> C;
		vi x( R ) , y( R );
		map< string , int > mapa;
		REP( i , R ) {
			string s;
			cin >> s >> x[ i ] >> y[ i ];
			mapa[ s ] = i + 1;
		}
	
		init();
	
		REP( it , C ){
			string S1 , heard , S2 , firing , before , S3;
			cin >> S1 >> heard >> S2 >> firing >> before >> S3;
			int p1 = mapa[ S1 ] - 1 , p2 = mapa[ S2 ] - 1 , p3 = mapa[ S3 ] - 1;
			ld w = getDist( p1 , p3 , x , y ) - getDist( p1 , p2 , x , y );
			ll W = floor( w );
			if( abs( W - w ) < 1e-8 )
				W --;
			add_edge( p3 + 1 , p2 + 1 , W );
			//S1 heard S2 firing before S3
		}
		REP( i , R ) add_edge( 0 , i , 0 );
		m = sz;
		n = R + 1;
		//test();
		if( !bellmanFord() ){
			puts( "IMPOSSIBLE" );
			continue;
		}
		puts( "D:" );
	}
}



