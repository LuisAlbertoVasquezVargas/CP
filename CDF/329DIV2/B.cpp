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

typedef long long ll;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< pll > vpll;

ll eval( ll m , ll b , ll x ){
	return m * x + b;
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		int x1 , x2;
		sc( x1 ) , sc( x2 );
		vpll V;
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			V.pb( mp( eval( x , y , x1 ) , eval( x , y , x2 ) ) );
		}
		sort( all( V ) );
		bool ok = 1;
		REP( i , SZ(V) - 1 )
			if( V[ i ].se > V[ i + 1 ].se ){
				ok = 0;
				break;
			}
		puts( !ok ? "YES" : "NO" );
	}
}




