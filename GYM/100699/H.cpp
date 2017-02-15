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
typedef vector< int > vi;

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi X( n ) , Y( n );
		REP( i , n ) sc( X[ i ] ) , sc( Y[ i ] );
		
		vector< pair< ll , pair< ll , ll > > > V;
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++j ){
				ll dx = X[ j ] - X[ i ];
				ll dy = Y[ j ] - Y[ i ];
				
				ll sx = X[ j ] + X[ i ];
				ll sy = Y[ j ] + Y[ i ];
				V.pb( mp( dx * dx + dy * dy , mp( sx , sy ) ) );
			}
		sort( all( V ) );
		ll ans = 0;
		REP( i , SZ( V ) ){
			int ind;
			for( int j = i ; j < SZ(V) ; ++j )
				if( V[ i ] == V[ j ] ) ind = j;
				else break;
			ll len = ind - i + 1;
			ans += len * (len - 1LL);
			i = ind;
		}
		ans >>= 1;
		cout << ans << '\n';
	}
}



