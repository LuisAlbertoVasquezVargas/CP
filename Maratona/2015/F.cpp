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

#define N 10

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< int > vi;

int main(){
	vector< ull > F( N + 1 );
	F[ 0 ] = 1;
	for( ull i = 1 ; i <= N ; ++i ) F[ i ] = (i) * F[ i - 1 ];
	//for( auto x : F ) cout << x << endl;
	int n;
	while( sc( n ) == 1 ){
		int ans = 0;
		while( n ){
			int pos = upper_bound( all( F ) , n ) - F.begin();
			pos --;
			n -= F[ pos ];
			ans ++;
		}
		printf( "%d\n" , ans );
	}
}
