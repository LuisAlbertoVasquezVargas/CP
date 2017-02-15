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

#define INF (1<<29)
#define N 100
#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef vector< string > vs;
typedef long long ll;
typedef vector< ll > vll;

int main(){
	int n;
	while( sc( n ) == 1 ){
		int ans = 0;
		REP( i , n ){
			int X1 , Y1 , X2 , Y2;
			sc( X1 ) , sc( Y1 ) , sc( X2 ) , sc( Y2 );
			if( X1 > X2 ) swap( X1 , X2 );
			if( Y1 > Y2 ) swap( Y1 , Y2 );
			ans += (X2 - X1 + 1) * (Y2 - Y1 + 1);
		}
		printf( "%d\n" , ans );
	}
}


