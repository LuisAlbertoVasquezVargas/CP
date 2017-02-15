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

#define test puts("************test************");
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 100
#define L 50
#define INF (1<<20)


typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
//16 000 000
int n;
int S[ N + 5 ] , P[ N + 5 ] , M[ N + 5 ];
string cad;
bool used[ L + 1 ][ L + 1 ][ L + 1 ][ L + 1 ];
int memo[ L + 1 ][ L + 1 ][ L + 1 ][ L + 1 ];
int ctePower , cteStr;
int dp( int pos , int health , int str , int power ){
	if( pos == n ) return 0;
	if( used[ pos ][ health ][ cteStr + str ][ ctePower + power ] ) 
		return memo[ pos ][ health ][ cteStr + str ][ ctePower + power ];
	used[ pos ][ health ][ cteStr + str ][ ctePower + power ] = 1;
	int &dev = memo[ pos ][ health ][ cteStr + str ][ ctePower + power ] = INF;
	if( str >= S[ pos ] ){
		int nhealth = health - max( 2 * S[ pos ] - str , 0 );
		if( nhealth > 0 )
			dev = min( dev , dp( pos + 1 , nhealth , str + 1 , power ) );
	}
	if( power >= P[ pos ] ){
		dev = min( dev , M[ pos ] + dp( pos + 1 , health , str , power + 1 ) );
	}
	return dev;
}
void rec( int pos , int health , int str , int power ){
	if( pos == n ) return;
	int dev = dp( pos , health , str , power );
	if( str >= S[ pos ] ){
		int nhealth = health - max( 2 * S[ pos ] - str , 0 );
		if( nhealth > 0 )
			if( dev == dp( pos + 1 , nhealth , str + 1 , power ) ){
				cad.pb( 'D' );
				rec( pos + 1 , nhealth , str + 1 , power );
				return;
			}
	}
	if( power >= P[ pos ] ){
		cad.pb( 'E' );
		rec( pos + 1 , health , str , power + 1 );
		return;
	}
	assert( 0 );
}
int main(){
	
	freopen( "princess.in" , "r" , stdin );
	freopen( "princess.out" , "w" , stdout );
	
	int health , str , power , mana;
	while( sc( n ) == 1 ){
		sc( health ) , sc( str ) , sc( power ) , sc( mana );
		ctePower = -power;
		cteStr = -str;
		REP( i , n ) sc( S[ i ] ) , sc( P[ i ] ) , sc( M[ i ] );
		clr( used , 0 );
		int minMana = dp( 0 , health , str , power );
		if( minMana <= mana ){
			cad.clear();
			rec( 0 , health , str , power );
			printf( "%s\n" , cad.c_str() );
		}else puts( "UNLUCKY" );
	}
}



