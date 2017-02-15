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

#define N 2000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int get( int num ){
	if( num % 10 <= 4 ) return (num/10)*10;
	return (num/10)*10 + 10;
}
const ll INF = LLONG_MAX/3;
ll memo[ N + 5 ][ 25 ];
bool used[ N + 5 ][ 25 ];
int n;
ll AC[ N + 5 ];
int A[ N + 5 ];
ll dp( int pos , int d ){
	if( pos == n ) return 0;
	if( used[ pos ][ d ] ) return memo[ pos ][ d ];
	used[ pos ][ d ] = 1;
	ll &dev = memo[ pos ][ d ] = INF;
	for( int j = pos ; j < n ; ++j ){
		if( d - 1 >= 0 ) dev = min( dev , (ll)get(AC[j + 1] - AC[ pos ]) + dp(j + 1 , d - 1) );
	}
	return dev;
}

int main(){
	int D;
	while( sc( n ) == 1 ){
		sc( D );
		REP( i , n ) sc( A[ i ] );
		REP( i , n ) AC[ i + 1 ] = AC[ i ] + A[ i ];
		clr( used , 0 );
		cout << dp( 0 , D + 1 ) << '\n';
	}
}




