#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>

using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 100005

typedef int ll;
typedef vector< ll > vll;

void karatsuba( ll *aa, int len1, ll *bb, int len2, ll c[]) {
	if (len1 == 1) {
		REP( i , len2 ) c[ i ] = aa[ 0 ] * bb[ i ];
	}
	else {
		int deg = len1 >> 1;
		int m = len1 + len2 - deg - deg-1;
		ll A[ m ], B[ m ], C[ m ];
		 
		fill( A , A + m , 0 );
		karatsuba( aa , deg , bb , deg , A );
		 
		int m1 = len1 - deg;
		ll s1[ m1 ]; 
		REP( i , m1 ) s1[ i ] = ( i < deg ? aa[ i ] : 0 ) + aa[ i + deg ];
		int m2 = len2 - deg;
		ll s2[ m2 ];
		REP( i , m2 ) s2[ i ] = ( i < deg ? bb[ i ] : 0 ) + bb[ i + deg ];
		 
		fill( C , C + m , 0 );
		karatsuba( aa + deg , m1 , bb + deg , m2 , C );
		fill( B , B + m , 0);
		karatsuba( s1 , m1 , s2 , m2 , B );
		 
		REP( i , m ) {
			c[ i ] += A[ i ];
			c[ i + deg ] += B[ i ] - A[ i ] - C[ i ];
			c[ i + deg + deg ] += C[ i ];
		}
	}
}
ll s[ N + 5 ] , t[ N + 5 ];
ll p[ 2*N + 5 ];
int main()
{
	int ns , nt;
	/*cin >> ns;
	REP( i , ns ) cin >> s[ i ];
	cin >> nt;
	REP( i , nt ) cin >> t[ i ];*/
	nt = ns = 1000 ;
	REP( i , nt ) s[ i ] = t[ i ] = 9;
	karatsuba( s , ns , t , nt , p );
	REP( i , ns + nt ) cout << (int)p[ i ] << " ";
	cout << endl;
}
