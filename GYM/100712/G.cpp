#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < (n) ; i++ )
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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , S;
		sc( n ) , sc( S );
		vi A( n );
		REP( i , n ) sc( A[ i ] );
		int ans = INT_MIN;
		REP( mask , 1 << n ){
			int sum = 0;
			REP( i , n )
				if( mask & (1 << i) ) sum += A[ i ];
			
			if( sum >= S ){
				bool ok = 1;
				REP( i , n )
					if( mask & (1 << i) ){
						if( sum - A[ i ] < S ) continue;
						ok = 0;
						break;
					}
				if( ok ) ans = max( ans , __builtin_popcount( mask ) );
			}
		}
		printf( "%d\n" , ans );
	}
}




