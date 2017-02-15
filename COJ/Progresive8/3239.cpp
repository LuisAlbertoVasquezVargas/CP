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

#define N 100000

typedef long long ll;
typedef pair< ll , ll > pii;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector< ll > vll;
typedef vector< vll > vvll;
typedef vector< vvi > vvvi;

char S[ N + 5 ];
int last[ 26 ];
int ans[ N + 5 ];

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		scanf( "%d%s" , &n , S );
		REP( i , n ) S[ i ] -= 'a';
		REP( i , 26 ) last[ i ] = INT_MAX;
		for( int i = n - 1 ; i >= 0 ; --i ){
			int mini = INT_MAX;
			for( int k = S[ i ] + 1 ; k < 26 ; ++k ) 
				mini = min( mini , last[ k ] );
			if( mini == INT_MAX ) ans[ i ] = -1;
			else ans[ i ] = mini + 1;
			last[ S[ i ] ] = i;
		}
		REP( i , n ) printf( "%d%c" , ans[ i ] , (i + 1 == n) ? 10 : 32 );
	}
}


