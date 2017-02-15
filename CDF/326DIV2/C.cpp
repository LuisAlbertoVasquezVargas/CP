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

#define N 4000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int F[ N + 5 ];
int last;
int getMini(){
	while( last <= N ){
		if( F[ last ] ) return last;
		last ++;
	}
	return -1;
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		clr( F , 0 );
		REP( i , n ){
			int x;
			sc( x );
			F[ x ] ++;
		}
		last = 0;
		int ans = 0;
		while( 1 ){
			int mini = getMini();
			if( mini == -1 ) break;
			if( F[ mini ] == 1 ){
				ans ++;
				F[ mini ] = 0;
				continue;
			}
			F[ mini + 1 ] += (F[ mini ] >> 1);
			F[ mini ] &= 1;
		}
		printf( "%d\n" , ans );
	}
}



