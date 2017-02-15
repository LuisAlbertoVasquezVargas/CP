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

#define N (24)
#define cte (11)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int F[ N + 5 ];

int main(){
	int n;
	while( sc( n ) == 1 ){
		clr( F , 0 );
		REP( i , n ){
			int x;
			sc( x );
			F[ cte + x ] ^= 1;
		}
		vi v;
		for( int i = -11 ; i <= 12 ; ++i )
			if( F[ cte + i ] ) v.pb( i );
		int len = 0;
		for( int i = 0 ; i < SZ(v) ; i += 2 ){
			int dif = abs(v[i + 1] - v[i]);
			len += dif;
		}
		printf( "%d\n" , min( len , 24 - len ) );
	}
}


