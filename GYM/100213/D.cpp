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

#define test puts("************test************");
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 50000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int A[ N + 5 ];
int main(){
	freopen( "integer.in" , "r" , stdin );
	freopen( "integer.out" , "w" , stdout );
	int n;
	while( sc( n ) == 1 ){
		REP( i , n ) sc( A[ i ] );
		map< int , int > mapa;
		REP( i , n ) mapa[ A[ i ] - i ] ++;
		int maxi = 0 , ind;
		REP( i , n ){
			int cur = mapa[ A[ i ] - i ];
			if( cur > maxi ){
				maxi = cur;
				ind = i;
			}
		}
		printf( "%d\n" , n - maxi );
		REP( i , n ) printf( "%d%c" , i + A[ ind ] - ind , (i + 1 == n ? 10 : 32) );
	}
}


