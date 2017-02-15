#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define INF (1<<20)
#define N 200000

#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long long ll;

int main(){
	int n , K;
	while( sc( n ) == 1 ){
		sc( K );
		vvi T( K );
		set< pair< int , int > > SET; //(x , id)
		REP( i , K ) SET.insert( mp( 0 , i ) );
		
		REP( i , n ){
			int x;
			sc( x );
			auto it = SET.begin();
			SET.erase( it );
			int pos = (*it).se;
			T[ pos ].pb( x );
			int p = 0 , len = SZ( T[ pos ] );
			if( len ){
				if( SZ(T[ pos ]) == 1 ) p = 2 * T[ pos ][ 0 ];
				else p = T[ pos ][ len - 1 ] + T[ pos ][ len - 2 ];
			}
			SET.insert( mp( len * p , pos ) );
			printf( "%d%c" , pos + 1 , (i + 1 == n) ? 10 : 32 );
		}
		
	}
}


