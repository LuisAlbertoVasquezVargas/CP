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

#define DEBUG( x ) cerr << #x << " " << x << endl;

#define N 5000

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;

int main(){
	int n , K;
	while( sc( n ) == 1 ){
		sc( K );
		ll T = (ll)n * (ll)(n + 1);
		T /= 2;
		if( T % K ){
			puts( "NO" );
			continue;
		}
		T /= K;
		vvi vec( K );
		vi cap( K , T );
		for( int cur = n ; cur >= 1 ; --cur ){
			int maxi = INT_MIN , id = -1;
			REP( i , K )
				if( cap[ i ] >= cur && cap[ i ] > maxi ){
					maxi = cap[ i ];
					id = i;
				}
			if( id == -1 ){
				puts( "NO" );
				return 0;
			}
			cap[ id ] -= cur;
			vec[ id ].pb( cur );
		}
		for( auto ans : vec ) {
			printf( "%d\n" , SZ(ans) );
			REP( i , SZ(ans) ) printf( "%d%c" , ans[ i ] , (i + 1 == SZ(ans)) ? 10 : 32  );
		}
	}
}


