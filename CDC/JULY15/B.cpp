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

ll ceil( ll a , ll b ){
	if( a == 0 ) return 0;
	return (a - 1LL)/ b + 1LL;
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		REP( i , n ){
			int x;
			sc( x );
			ll y = x;
			while( y % 10 == 0 ) y /= 10;
			int e = 0;
			while( y % 5 == 0 ) e ++ , y /= 5;
			e = ceil( e , 2LL ) * 2LL;
			printf( "%lld\n" , (ll)x * (1LL << e) );
		}
	}
}


