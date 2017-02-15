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

#define N 10000

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

int main(){
	int n , K;
	while( sc( n ) == 1 ){
		sc( K );
		int m = (1 << n) , ans = 0;
		REP( mask , 1 << m ){
			int cur = 0;
			REP( i , m )
				if( mask & (1 << i) ) cur ^= i;
			if( __builtin_popcount( cur ) == K ) ans ++;
		}
		printf( "%d\n" , ans );
	}
}





