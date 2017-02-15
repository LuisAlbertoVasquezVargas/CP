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
	int n , m;
	while( sc( m ) == 1 ){
		sc( n );
		int cte = 0;
		for( int x = 0 ; x <= m ; ++x )
			for( int y = x ; y <= m ; ++y )
				for( int z = y ; z <= m ; ++z )
					if( x * x + y * y == z * z ) cte ++;
		ll ans = (ll)(cte) * (n - 1);
		DEBUG( cte );
		cout << ans << '\n';
		//DEBUG2( 8128/ans , 8128%ans );
	}
}



