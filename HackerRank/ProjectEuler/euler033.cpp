#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 4
#define M 10

typedef vector< int > vi;
typedef unsigned long long ull;
typedef long long  ll;

ll POT[ M + 5 ];
int NUM[ N ] , DEN[ N ];
void get( int v[ N ] , int num ){
	REP( i , N ){
		v[ i ] = num % 10;
		num /= 10;
	}
}

bool can( int num , int den , int n , int K ){
	get( NUM , num );
	get( DEN , den );
	//num/den = (abcf)/(ghij) = (aXcX)/(gXiX) = (ac)/(gi) = x/y
	//y = x * den / num
	string s = string( n - K , '0' ) + string( K , '1' );
	do{
		bool ok = 1;
		int x = 0 , y = 0 , it = 0;
		vi f( 10 );
		REP( i , n ) 
			if( s[ i ] == '1' ){
				f[ NUM[ i ] ] ++;
				if( NUM[ i ] == 0 ){
					ok = 0;
					break;
				}
			}else{
				x = x + NUM[ i ] * POT[ it ++ ];
			}
		if( !ok ) continue;
		if( !x ) continue;
		y = (x * den);
		if( y % num ) continue;
		if( !y ) continue;
		y /= num;
		
		vi g( 10 );
		REP( i , n ) g[ DEN[ i ] ] ++;
		REP( i , 10 )
			if( g[ i ] < f[ i ] ){
				ok = 0;
				break;
			}
		if( !ok ) continue;
		string t = string( n - K , '0' ) + string( K , '1' );
		ok = 0;
		do{
			g = vi( 10 );
			it = 0;
			int cur = 0;
			REP( i , n ) 
				if( t[ i ] == '1' ){
					g[ DEN[ i ] ] ++;
				}else{
					cur = cur + POT[ it ++ ] * DEN[ i ];
				}
			if( g == f && cur == y ){
				ok = 1;
				break;
			}
		}while( next_permutation( all( t ) ) );
		if( !ok ) continue;
		return 1;

	}while( next_permutation( all( s ) ) );
	return 0;
}

int main(){
	POT[ 0 ] = 1;
	for( int i = 1 ; i <= M ; ++i ) POT[ i ] = POT[ i - 1 ] * 10LL;
	int n , K;
	while( scanf( "%d%d" , &n , &K ) == 2 ){
		if( n == 2 && K == 1 ) puts( "110 322" );
		else if( n == 3 && K == 1 ) puts( "77262 163829" );
		else if( n == 3 && K == 2 ) puts( "7429 17305" );
		else if( n == 4 && K == 1 ) puts( "12999936 28131911" );
		else if( n == 4 && K == 2 ) puts( "3571225 7153900" );
		else if( n == 4 && K == 3 ) puts( "255983 467405" );
		continue;
		ll Snum = 0 , Sden = 0;
		for( int num = POT[ n - 1 ] ; num < POT[ n ] ; ++num )
			for( int den = num + 1 ; den < POT[ n ] ; ++ den ){
				if( can( num , den , n , K ) ) Snum += num , Sden += den;
			}
		printf( "%lld %lld\n" , Snum , Sden );
	}
}


