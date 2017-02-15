#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define SZ(v) ((int)(v).size())
#define all(v)  v.begin() , v.end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define test puts("************test************");
#define DEBUG( x ) cerr << #x << " " << x << endl;

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long double ld;
typedef vector< ld > vld;

int main(){
	
	freopen( "academy.in" , "r" , stdin );
	freopen( "academy.out" , "w" , stdout );
	
	int n , A , B;
	while( sc( n ) == 1 ){
		sc( A ) , sc( B );
		vi p( n + 1 ) , q( n + 1 , 1 ) , s( n + 1 , 1 );
		REP(i , n) sc( p[ i ] ) , sc( q[ i ] ) , sc( s[ i ] );
		ld best = 1e100;
		int id = -1;
		ld g = 0;
		vld vec( n );
		REP( i , n + 1 ){
			
			ld lvl = (ld) p[ i ] / (ld) s[ i ];
			ld cur = lvl * (ld)B;
			vld w( n + 1 , 0.0 );
			REP( j , n + 1 ){
				ld temp = (ld) p[ j ] - lvl * (ld)s[ j ];
				if( temp <= 0 ) continue;
				cur += (temp / (ld)q[ j ]) * (ld)A;
				w[ j ] = (temp / (ld)q[ j ]);
			}
			if( cur < best ){
				best = cur;
				id = i;
				g = lvl;
				vec = w;
			}
		}
		printf( "%.15f\n" , (double) best );
		printf( "%.15f\n" , (double) g );
		REP( i , n ) printf( "%.15f%c" , (double) vec[ i ] , (i + 1 == n) ? 10 : 32 );
	}
}

