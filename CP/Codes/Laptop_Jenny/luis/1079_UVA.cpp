#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back
#define all( v ) v.begin() , v.end()

#define N 10
#define INF 50
#define IT 100

#define test puts( "test" );

typedef long double ld;

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
	ld fractpart , intpart;
	fractpart = modf( x , &intpart );
	//cout << x << " " << intpart << endl;
	//impr( intpart ) , impr( fractpart );
	int a = (int) round( intpart );
	x = fractpart*60;
	fractpart = modf( x , &intpart );
	int b = (int) round( intpart );
	printf("Case %d: %d:%02d\n", ++tc , a , b );
	/*
	int res = (int)round( 60*x );
	printf("Case %d: %d:", ++tc, res/60);
	if (res % 60 < 10) printf("0%d\n", res%60);
	else printf("%d\n", res%60);
	*/
}
int main()
{
    while( sc( n ) == 1 ){
        if( !n ) break;
        REP( i , n ) sc( A[ i ] ) , sc( B[ i ] );
        REP( i , n ) ind[ i ] = i ;
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
