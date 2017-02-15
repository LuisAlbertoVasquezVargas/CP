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

#define test() cout << "hola que hace ?" << endl;
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int main(){
	//freopen( "analogous.in" , "r" , stdin );
	//freopen( "analogous.out" , "w" , stdout );

	int n;
	while( sc( n ) == 1 ){
		if( !n ) break;
		if( n == 2 ){
			puts( "Yes" );
			puts( "1 4" );
			puts( "2 3" );
			continue;
		}
		puts( "No" );
	}
}





