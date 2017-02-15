#include<bits/stdc++.h>
using namespace std;
 
#define sc(x) scanf( "%d" , &x )
#define REP(i , n) for( int i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )
 
#define pb push_back
#define all(v) v.begin() , v.end()
#define SZ(v) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second
	
typedef long long ll;
typedef long double ld;
typedef vector< int , int > pii;
typedef vector< int > vi;
 
ld solveA( ld T1 , ld T2 , ld t1 , ld t2 ){
	if( T2 <= t1 ) return T1 * T2;
	ld S = ((t1 + t1 + T1)/2.0) * T1;
	if( T2 >= t1 + T1 ) return S;
	ld L = t1 + T1 - T2;
	return S - (L * L) /2.0;
}
ld solveB( ld T1 , ld T2 , ld t1 , ld t2 ){
	if( T1 - t2 <= 0 ) return 0.0;
	ld L = T1 - t2;
	if( L <= T2 ) return (L * L)/2.0;
	ld R = T2 - L;
	return (L * L)/2.0 - (R * R)/2.0;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int T1 , T2 , t1 , t2;
		sc( T1 ) , sc( T2 ) , sc( t1 ) , sc( t2 );
		ld coef = (ld) T1 * (ld) T2;
		ld ans = solveA( T1 , T2 , t1 , t2 ) - solveB( T1 , T2 , t1 , t2 );
		//printf( "%.10f\n" , (double) ans );
		ans /= coef;
		printf( "%.10f\n" , (double) ans );
		//printf( "%.10f\n" , 0.0 );		
	}
}
 
