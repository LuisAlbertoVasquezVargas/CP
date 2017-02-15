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
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;
 

ld INF = 1e100;
ld n , p , s , v;
ld f( ld c ){
	ld base = log2( n );
	ld expo = pow( base , c * sqrt( 2 ) );
	if( expo >= INF ) return INF;
	return ((expo * n * log( base ) * sqrt( 2 ) ) / (p  * 1e9)) - (s/(v * c * c));
	//return n * 
}
ld eval( ld c ){
	ld base = log2( n );
	ld expo = pow( base , c * sqrt( 2 ) );
	return ((expo * n) / (p  * 1e9)) + (s/v) * (1.0 + 1.0/c);
}
int main(){
	while( cin >> n >> p >> s >> v ){
		ld lo = 0.1 , hi = 2 * 10e9;
		REP( it , 250 ){
			ld med = (lo + hi)/2.0;
			if( f( med ) >= 0 ) hi = med;
			else lo = med;
		}
		printf( "%.15f %.15f\n" , (double) eval( hi ) , (double)hi );
	}	
}


