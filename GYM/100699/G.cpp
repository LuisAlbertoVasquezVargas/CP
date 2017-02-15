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
typedef pair< int , int > pii;
typedef vector< int > vi;


map< vi , ll > memo;
ll dp( vi v ){
	if( v[ 0 ] + v[ 1 ] + v[ 2 ] == 0 ) return 1;
	if( memo.count( v ) ) return memo[ v ];
	ll &dev = memo[ v ] = 0;
	int last = v[ 3 ];
	REP( i , 3 )
		if( last != i && v[ i ] ){
			vi w = v;
			w[ 3 ] = i;
			w[ i ] --;
			dev += dp( w );
		}
	return dev;
}
int main(){
	int n;
	while( cin >> n ){
		vi v( 4 , n );
		v[ 3 ] = 3;
		cout << dp( v ) << '\n';
	}	
}



