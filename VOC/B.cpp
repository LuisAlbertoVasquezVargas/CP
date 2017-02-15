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

#define N 1000
#define MOD 1000000007

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;


ll C[ N + 5 ][ N + 5 ];
void init(){
	REP( i , N + 1 ) C[ i ][ i ] = C[ i ][ 0 ] = 1;
    for( int i = 2 ; i <= N ; ++i )
         for( int j = 1 ; j <= i ; ++j )
            C[ i ][ j ] = ( C[ i - 1 ][ j ] + C[ i - 1 ][ j - 1 ] )%MOD;
}
const int n = 26;

int main(){
	init();
	string s;
	while( getline( cin , s ) ){
		vi F( n );
		REP( i , SZ( s ) ) F[ s[ i ] - 'A' ] ++;
		ll ans = 1;
		for( int i = 0 , sum = 0 ; i < n ; ++i ){
			ans *= C[ sum + F[ i ] ][ F[ i ] ];
			ans %= MOD;
			sum += F[ i ];
		}
		cout << ans << '\n';
	}
}


