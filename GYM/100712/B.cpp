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
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;

char S[ N + 5 ];
string cad = "RPS";

int get( int pos , int lo , int hi , vvi &AC ){
	if( lo > hi ) return 0;
	return AC[ pos ][ hi + 1 ] - AC[ pos ][ lo ];
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		scanf( "%s" , S );
		
		vvi AC( 3 , vi(n + 1) );
		REP( i , n ) REP( k , 3 ) AC[ k ][ i + 1 ] = AC[ k ][ i ] + (S[ i ] == cad[k]);
		
		int freq = 0;
		for( int x = 0 ; x <= n ; ++x )
			for( int y = 0 ; x + y <= n ; ++y ){
				int lox = 0 , hix = x - 1;
				int loy = hix + 1 , hiy = x + y - 1;
				int loz = hiy + 1 , hiz = n - 1;
				int cura = 0;
				cura += get( 2 , lox , hix , AC );
				cura += get( 0 , loy , hiy , AC );
				cura += get( 1 , loz , hiz , AC );
				
				int curb = 0;
				curb += get( 1 , lox , hix , AC );
				curb += get( 2 , loy , hiy , AC );
				curb += get( 0 , loz , hiz , AC );
				
				if( cura > curb ) freq ++;
			}
		printf( "%d\n" , freq );
	}
}





