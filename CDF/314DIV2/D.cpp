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

int K , A;
int f( int L , int R ){
	int len = (R - L) - 1;
	if( len == 0 ) return 0;
	if( len % (A + 1) == 0 ) return len / (A + 1);
	int ans = len / (A + 1);
	if( len % (A + 1) == A ) ans ++;	
	return ans;
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		sc( K ) , sc( A );
		int m;
		sc( m );
		set< int > SET;
		SET.insert( 0 );
		SET.insert( n + 1 );
		
		int cur = f( 0 , n + 1 );
		int pos = -1;
		REP( i , m ){
			int x;
			sc( x );
			set< int > :: iterator it = SET.upper_bound( x );
			int R = *it;
			it --;
			int L = *it;
			cur = cur - f( L , R ) + f( L , x ) + f( x , R );
			
			if( pos == -1 && cur < K ){
				pos = i + 1;
			}
			SET.insert( x );
		}
		printf( "%d\n" , pos );
	}
}



