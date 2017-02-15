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

typedef vector< int > vi;
typedef unsigned long long ull;

ull POW( ull a , ull b ){
	ull ans = 1ULL;
	while( b ){
		if( b & 1 ) ans = (ans * a);
		b >>= 1;
		a = a * a;
	}
	return ans;
}
ull POT[ 25 ];
int main(){
	POT[ 0 ] = 1ULL;
	for( int i = 1 ; i <= 20 ; ++i ) POT[ i ] = POT[ i - 1 ] * 10ULL;
	int n;
	while( sc( n ) == 1 ){
		for( ull x = 1ULL ; x <= 9ULL ; ++x ){
			ull Xn = POW( x , n );
			if( Xn >= POT[ n - 1 ] ){
				cout << Xn << endl;
				//printf( "%llu\n" , Xn );
			}
		}
	}	
}
