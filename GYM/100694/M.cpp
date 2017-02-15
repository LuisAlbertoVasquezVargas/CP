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

#define DEBUG( x ) cerr << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long long ll;

int main(){
	int n , Q;
	while( sc( n ) == 1 ){
		sc( Q );
		n ++;
		REP( i , Q ){
			int a , b;
			sc( a ) , sc( b );
			int ans = (n/(a + b)) * 2;
			int m = n % (a + b);
			if( m ){
				ans ++;
				if( m > a ) ans ++;
			}
			ans --;
			printf( "%d%c" , ans , (i + 1 == Q) ? 10 : 32 );
		}
	}
}
