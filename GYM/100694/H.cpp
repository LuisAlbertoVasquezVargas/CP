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
typedef long long ll;
typedef vector< ll > vll;

int main(){
	int n;
	while( sc( n ) == 1 ){
		int maxi = 0;
		REP( i , 2 ){
			REP( j , n ){
				int x;
				sc( x );
				if(i == 0) maxi = max( maxi , x );
			}
		}
		int K;
		sc( K );
		int ans = 0;
		REP( i , K ){
			int x;
			sc( x );
			ans += x;
		}
		ans += K * maxi;
		printf( "%d\n" , ans );
	}
}


