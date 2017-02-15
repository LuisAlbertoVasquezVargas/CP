#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 500000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

vpii T[ N + 1 ];
vi G[ N + 1 ];
int myHypot( int x , int y ){
	return x * x + y * y;
}
//int delta[ 10 ];
vi delta = { 5 , 4 , 4 , 4 , 3 , 0 };
int used[ N + 1 ];
int main(){
	/*
	REP( d , 5 + 1 )
		delta[ d ] = floor( sqrt( 5 * 5 - d * d ) );
	*/
	int n;
	while( sc( n ) == 1 ){
		vi X( n ) , Y( n );
		REP( i , n ) sc( X[ i ] ) , sc( Y[ i ] );
		
		REP( i , N + 1 ) T[ i ].clear();
		REP( i , n ) T[ X[ i ] ].pb( mp( Y[ i ] , i ) );
		REP( i , n ){
			if( used[ X[ i ] ] ) continue;
			used[ X[ i ] ] = 1;
			sort( all( T[ X[ i ] ] ) );
		}
		REP( i , n ) used[ X[ i ] ] = 0;
		
		REP( i , n ) G[ i ].clear();
		REP( u , n ){
			int x = X[ u ] , y = Y[ u ];
			for( int dx = -5 ; dx <= 5 ; dx ++ ){
				int nx = x + dx;
				// |ny - y| <= sqrt( 5 ^ 2 - (nx - x)^2 )
				// ny <= y + 
				if( nx >= 1 && nx <= N ){
					auto it1 = lower_bound( all( T[ nx ] ) , mp( y - delta[ abs(dx) ] , INT_MIN ) );
					auto it2 = upper_bound( all( T[ nx ] ) , mp( y + delta[ abs(dx) ] , INT_MAX ) );
					for( auto it = it1 ; it < it2 ; ++it ){
						int ny = (*it).fi;
						int v = (*it).se;
						if( myHypot( nx - x , ny - y ) <= 25 ){
							//DEBUG2( u , v );
							G[ u ].pb( v );
							G[ v ].pb( u );
						}
					}
				}
			}
		}
		queue< int > Q;
		vi col( n , -1 );
		int ans = 0;
		REP( s , n ){
			if( col[ s ] != -1 ) continue;
			vi cnt( 2 );
			Q.push( s );
			col[ s ] = 0;
			cnt[ col[ s ] ] ++;
			
			while( !Q.empty() ){
				int u = Q.front(); Q.pop();
				for( auto v : G[ u ] ){
					if( col[ v ] == -1 ){
						Q.push( v );
						col[ v ] = col[ u ] ^ 1;
						cnt[ col[ v ] ] ++;
					}
				}
			}
			ans += min( cnt[ 0 ] , cnt[ 1 ] );
		}
		printf( "%d\n" , ans );
	}
}



