#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 100
#define INF ( 1LL << 62 )

typedef long long ll;

char s[ 10 ];

int main(){
	int cases , n , to , sto , r , t;
	sc( cases );
	REP( tc , cases ){
		printf( "Case #%d:\n" , tc + 1 );
		sc( n );
		vector< priority_queue< ll > > Q( N + 1 );
		REP( i , n ){
			scanf( "%s" , s );
			if( s[ 0 ] == 'P' ){
				sc( to ) , sc( sto ) , sc( r );
				Q[ r ].push( sto - (ll)r * to );
			}else{
				sc( t );
				ll maxi = -INF , ind = -1;
				REP( i , N + 1 ) 
					if( Q[ i ].empty() ) continue;
					else
					{
						ll temp = Q[ i ].top() + i*t;
						if( temp >= maxi ) maxi = temp , ind = i;
					}
				Q[ ind ].pop();
				cout << maxi << " " << ind << '\n';
			}
		}
	}
}
