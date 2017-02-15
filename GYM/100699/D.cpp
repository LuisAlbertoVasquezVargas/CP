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
	int n;
	while( cin >> n ){
		vs T( n );
		REP( i , n ){
			T[ i ].resize( n + i + 1 , ' ' );
			T[ i ][ n + i ] = '\\';
			T[ i ][ n - 1 - i ] = '/';
		}
		REP( i , n ) cout << T[ i ] << '\n';
	}
}
