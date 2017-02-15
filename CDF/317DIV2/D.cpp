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

#define N 300000
#define M 5000
#define INF (1LL<<60)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int A[ N + 1 ];
bool used[ M + 1 ][ M + 1 ];
ll memo[ M + 1 ][ M + 1 ];
int n , K ;
ll la , lb;
ll ga , gb;
ll dp( int a , int b ){
	if( a == ga && b == gb ) return 0;
	if( used[ a ][ b ] ) return memo[ a ][ b ];
	used[ a ][ b ] = 1;
	ll &dev = memo[ a ][ b ] = INF;
	int pos = a * la + b * lb;
	if( a + 1 <= ga ) dev = min( dev , A[ pos + la - 1 ] - A[ pos ] + dp( a + 1 , b ) );
	if( b + 1 <= gb ) dev = min( dev , A[ pos + lb - 1 ] - A[ pos ] + dp( a , b + 1 ) );
	return dev;
}

int main(){
	
	while( sc( n ) == 1 ){
		sc( K );
		REP( i , n ) sc( A[ i ] );
		la = (n - 1) / K + 1;
		lb = n / K;
		
		ga = (n % K);
		gb = K - (n % K);
		sort( A , A + n );
		clr( used , 0 );
		cout << dp( 0 , 0 ) << '\n';
	}	
}



