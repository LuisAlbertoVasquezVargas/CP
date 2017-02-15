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

#define N 10000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int n;
char S[ N + 5 ];
bool val( int pos ){
	if( pos - 1 >= 0 && S[ pos - 1 ] == '*' ) return 1;
	if( pos + 1 < n && S[ pos + 1 ] == '*' ) return 1;
	return 0;
}
int f( int x ){
	if( x == 0 ) return 0;
	return (x - 1)/3 + 1;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( n );
		scanf( "%s" , S );
		int ans = 0;
		REP( i , n ){
			if( S[ i ] == '*' ) continue;
			int ind;
			for( int j = i ; j < n ; ++j )
				if( S[ j ] == '.' ) ind = j;
				else break;
			int cur = ind - i + 1;
			if( val( i ) ) cur --;
			if( val( ind ) ) cur --;
			if( val( i ) && val( ind ) && i == ind ) cur ++;
			ans += f( cur );
			i = ind;
		}
		printf( "%d\n" , ans );
	}
}


