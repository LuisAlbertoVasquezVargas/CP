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

#define N 20
#define M 4
#define T 10

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int n , t;
bool used[ N + 1 ][ M + 1 ][ M + 1 ][ T + 1 ][ T + 1 ];
ll memo[ N + 1 ][ M + 1 ][ M + 1 ][ T + 1 ][ T + 1 ];
ll dp( int pos , int last1 , int last2 , int c1 , int c2 ){
	if( pos == n ) return c1 == t && c2 == t - 1;
	if( used[ pos ][ last1 ][ last2 ][ c1 ][ c2 ] ) return memo[ pos ][ last1 ][ last2 ][ c1 ][ c2 ];
	used[ pos ][ last1 ][ last2 ][ c1 ][ c2 ] = 1;
	ll &dev = memo[ pos ][ last1 ][ last2 ][ c1 ][ c2 ] = 0;
	for( int k = 1 ; k <= 4 ; ++k ){
		if( k == last2 ) continue;
		bool valid = ((pos - 1 >= 1) && (pos - 1 <= n - 2));
		dev += dp( pos + 1 , last2 , k , c1 + (valid?(last1 < last2 && last2 > k):0) , c2 + (valid?(last1 > last2 && last2 < k):0) );
	}
	return dev;
}
int main(){
	while( sc( n ) == 1 ){
		sc( t );
		clr( used , 0 );
		cout << dp( 0 , 0 , 0 , 0 , 0 ) << '\n';
	}
}
