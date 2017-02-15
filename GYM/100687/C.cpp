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

int ceil( int a , int b ){
	if( !a ) return 0;
	return (a - 1)/b + 1;
}
int n , m , x , y , z;
bool doit( int a , int b , int c ){
	vi user = { m , a , b , c };
	vi cap = { 0 , x , y , z };
	vi coef = { 1 , 1 , 2 , 3 };
	///			1 , 1 , 2 , 2
	for( int i = 3 ; i >= 0 ; --i ){
		int &cur = user[ i ];
		for( int j = 3 ; j >= i ; --j ){
			int t = min( ceil( cur , coef[ i ] ) , cap[ j ] );
			cur -= t * coef[ i ];
			cap[ j ] -= t;
		}
	}
	return user == vi( 4 , 0 );
}
bool solve(){
	for( int a = 0 ; a <= n ; ++a )
		for( int b = 0 ; a + b <= n ; ++ b ){
			int c = n - (a + b);
			if( doit( a , b , c ) ) return 1;
		}
	return 0;
}
int main(){	
	while( cin >> n >> m >> x >> y >> z ){
		puts( solve() ? "Yes" : "No" );
	}
}


