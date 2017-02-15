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

#define N 1000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;

char S[ N + 5 ];
int F[ 3 ];
ll comb( ll n ){
	return (n * (n - 1)) >> 1;
}
int main(){
	while( scanf( "%s" , S ) == 1 ){
		int n = strlen( S );
		ll ans = 0;
		for( int i = 0 ; i < n ; ++i ){
			if( !isdigit( S[ i ] ) ) continue;
			int ind;
			clr( F , 0 );
			int ac = 0;
			F[ ac ] ++;
			for( int j = i ; j < n ; ++j )
				if( isdigit( S[ j ] ) ){
					int x = S[ j ] - '0';
					ac = (ac * 10 + x)%3;
					F[ ac ] ++;
					ind = j;
				}else break;
			REP( i , 3 ) ans += comb( F[ i ] );
			i = ind;
		}
		printf( "%lld\n" , ans );
	}
}


