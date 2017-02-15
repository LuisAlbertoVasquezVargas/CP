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
typedef vector< string > vs;


int main(){
	ios_base :: sync_with_stdio( 0 );
	int n;
	while( cin >> n ){
		vs T( n );
		REP( i , n ) cin >> T[ i ];
		int ans = 0;
		REP( a , 26 )REP( b , 26 ){
			int cnt = 0;
			REP( i , n ){
				if( a == b ){
					if( count( all( T[ i ] ) , 'a' + a ) == SZ(T[ i ]) )
						cnt += SZ( T[ i ] );
					continue;
				}
				if( count( all( T[ i ] ) , 'a' + a ) + count( all( T[ i ] ) , 'a' + b ) == SZ(T[ i ]) ) 
					cnt += SZ( T[ i ] );
			}
			ans = max( ans , cnt );
		}
		cout << ans << '\n';
	}
}


