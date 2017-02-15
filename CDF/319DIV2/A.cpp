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
typedef vector< pii > vpii;

int main(){
	int n , x;
	while( sc( n ) == 1 ){
		sc( x );
		int ans = 0;
		for( int d = 1 ; d * d <= x ; ++d ){
			if( x % d == 0 ){
				int a = d , b = x / d;
				if( a <= n && b <= n ){	
					if( a == b ) ans ++;
					else ans += 2;
				}
			}
		}
		printf( "%d\n" , ans );
	}
}
