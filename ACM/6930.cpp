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

#define N 1000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

struct frac{
	ll num , den;
	frac(){ num = den = 0;}
	frac( ll a , ll b ){
		if( b == 0 ) num = 1 , den = 0;
		else if( a == 0 ) num = 0 , den = 1;
		else{
			if( b < 0 ) a = -a , b = -b;
			ll g = __gcd( abs( a ) , abs( b ) );
			num = a/g , den = b/g;
		}
	}
};
bool operator <( const frac &a , const frac &b ){
	return a.num * b.den < b.num * a.den;
}
bool operator >( const frac &a , const frac &b ){
	return a.num * b.den > b.num * a.den;
}
bool operator == ( const frac &A , const frac &B ){ return A.num == B.num && A.den == B.den;}
bool operator != ( const frac &A , const frac &B ){ return !(A == B);}
frac operator +( const frac &A , const frac &B ){ return frac( A.num * B.den + B.num * A.den , A.den * B.den ) ;}
frac operator -( const frac &A , const frac &B ){ return frac( A.num * B.den - B.num * A.den , A.den * B.den ) ;}

frac operator *( const frac &A , const frac &B ){ return frac( A.num * B.num , A.den * B.den ) ;}
frac operator /( const frac &A , const frac &B ){ return frac( A.num * B.den , A.den * B.num ) ;}
frac abs( frac &A ){ return frac( abs( A.num ) , abs( A.den ) );}


int X[ N + 5 ] , Y[ N + 5 ] , R[ N + 5 ];
vi G[ N + 5 ];
int vis[ N + 5 ];
frac F[ N + 5 ];
bool dir[ N + 5 ];
void dfs( int u , frac vel , bool rot ){
	vis[ u ] = 1;
	F[ u ] = vel;
	dir[ u ] = rot;
	for( auto v : G[ u ] )
		if( !vis[ v ] ) dfs( v , vel * frac( R[ u ] , R[ v ] ) , rot ^ 1 );
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		REP( i , n ) sc( X[ i ] ) , sc( Y[ i ] ) , sc( R[ i ] );
		
		REP( i , n ) G[ i ].clear();
		REP( i , n )
			for( int j = i + 1 ; j < n ; ++j ){
				int dx = X[ i ] - X[ j ];
				int dy = Y[ i ] - Y[ j ];
				int s = R[ i ] + R[ j ];
				if( dx * dx + dy * dy == s * s ){
					G[ i ].pb( j );
					G[ j ].pb( i );
				}
			}
		
		REP( i , n ) vis[ i ] = 0;
		dfs( 0 , frac( 1 , 1 ) , 0 );
		
		REP( i , n ){
			if( !vis[ i ] ){
				puts( "not moving" );
				continue;
			}
			if( F[ i ].den == 1 ){
				printf( "%lld %s\n" , F[ i ].num , (!dir[ i ]) ? "clockwise" : "counterclockwise" );
				continue;
			}
			printf( "%lld/%lld %s\n" , F[ i ].num , F[ i ].den , (!dir[ i ]) ? "clockwise" : "counterclockwise" );
		}
	}
}






