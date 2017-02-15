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

typedef long long ll;
typedef vector< int > vi;
typedef pair< int , int > pii;

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi used( n );
		REP( i , n ){
			REP( j , n ){
				int x;
				sc( x );
				if( x <= 0 ) continue;
				if( x == 1 ) used[ i ] = 1;
				else if( x == 2 ) used[ j ] = 1;
				else if( x == 3 ) used[ i ] = used[ j ] = 1;
			}
		}
		vi v;
		REP( i , n ) if( !used[ i ] ) v.pb( i );
		printf( "%d\n" , SZ( v ) );
		REP( i , SZ( v ) ) printf( "%d%c" , v[ i ] + 1 , (i + 1 == SZ(v)) ? 10 : 32 );
	}
}
