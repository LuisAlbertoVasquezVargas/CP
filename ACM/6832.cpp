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
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define INF 1234567

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< pii > vpii;

int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		int s = 0;
		REP( i , n ){
			int x;
			sc( x );
			if( x ) s |= (1 << i);
		}
		int t1 = 0 , t2 = 0 , col = 0 , cur = 0;
		REP( i , m ){
			int len;
			sc( len );
			REP( j , len ){
				if( col ) t1 |= (1 << cur);
				else t2 |= (1 << cur);
				cur ++;
			}
			col ^= 1;
		}
		queue< int > Q;
		vi dist( (1 << n) , INF );
		Q.push( s );
		dist[ s ] = 0;
		
		while( !Q.empty() ){
			int u = Q.front(); Q.pop();
			REP( i , n - 1 ){
				int v = u;
				int a = (1 << (i)) & v;
				int b = (1 << (i + 1)) & v;
				if( a ) v ^= a;
				if( b ) v ^= b;
				
				if( a ) v ^= (1 << (i + 1));
				if( b ) v ^= (1 << (i));
				if( dist[ v ] > dist[ u ] + 1 ){
					dist[ v ] = dist[ u ] + 1;
					Q.push( v );
				}
			}
		}
		printf( "%d\n" , min( dist[ t1 ] , dist[ t2 ] ) );
	}
}


