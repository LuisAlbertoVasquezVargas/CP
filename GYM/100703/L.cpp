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

#define test() cout << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;


#define MOD1 100003LL
#define MOD2 100019LL
#define MOD3 1000000007LL
#define MOD4 1000000009LL

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef vector< vvpii > vvvpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;

int main(){
	int n;
	while( sc( n ) == 1 ){
		vvi T( 3 , vi( n ) );
		REP( j , 3 ) REP( i , n ) sc( T[ j ][ i ] );
		int a = 0 , b = 0;
		REP( i , n ){
			int x = abs( T[ 2 ][ i ] - T[ 0 ][ i ] );
			int y = abs( T[ 2 ][ i ] - T[ 1 ][ i ] );
			if( x < y ) a ++;
			if( y < x ) b ++;
		}
		
		printf( "%d %d\n" , a , b );
	}
}



