#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back
#define all( v ) v.begin() , v.end()

#define N 10
#define INF 2000
#define IT 50
#define Len 15
#define EPS (1e-8)

#define test puts( "test" );

typedef long double ld;
typedef long long ll;

int A[ N ] , B[ N ] , ind[ N ];
int n , tc = 0;
void impr( ld x ){ printf( "%.4f\n" , (double)x ); }

bool f( ld D ){
	ld curent = A[ ind[ 0 ] ] ;
	//impr( curent );
	for( int i = 1 ; i < n ; ++i ){
		if( curent + D > B[ ind[ i ] ] ) return 0;

		curent = max( curent + D , (ld) A[ ind[ i ] ] ); 
		//impr( curent );
	}
	return 1;
}
void doit( ld x ){
	cout << "Case " << ++tc << ": ";
	ld fractpart , intpart;
	fractpart = modf( x , &intpart );
	int a = (int)round( intpart );
	if( abs( a - x ) < EPS ){
		printf( "%d:00\n" , round(x) );
		return;
	}
	x = fractpart*60;
	//cout << " x : " <<x <<endl;
	fractpart = modf( x , &intpart );
	int b = (int)round( intpart );
	printf( "%d:%02d\n" , a , b );
}
int main()
{
	while( sc( n ) == 1 ){
		if( !n ) break;
		REP( i , n ) sc( A[ i ] ) , sc( B[ i ] );
		int L = 1e5 , R = -1e5;
		REP( i , n ) ind[ i ] = i , L = min( L , A[ i ] ) , R = ( R , B[ i ] );
		ld ans = 0;
		do{
			ld lo = 0 , hi = INF;
			if( !f( lo ) ) continue;
			REP( it , IT ){
				ld med = ( lo + hi )/2.0;
				if( f( med ) ) lo = med;
				else hi = med;
			}
			ans = max( ans , hi );
		}while( next_permutation( ind , ind + n ) );
		//impr( ans );
		doit( ans );
	}
}
