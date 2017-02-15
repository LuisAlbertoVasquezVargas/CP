#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long long ll;

int main(){
	ios_base :: sync_with_stdio( 0 );
	int n;
	while( cin >> n ){
		string s , t;
		cin >> s >> t;
		vvi T( 26 , vi( 26 ) ) , id( T );
		int hamming = 0;
		REP( i , n ){
			char x = s[ i ] - 'a';
			char y = t[ i ] - 'a';
			if( x != y ) hamming ++;
			T[ x ][ y ] ++;
			id[ x ][ y ] = i + 1;
		}
		int a = -1 , b = -1 , best = 0;
		REP( x , 26 )REP( y , 26 )REP( z , 26 )
			if( x != y && x != z ){
				if( T[ x ][ z ] && T[ y ][ x ] ){
					a = id[ x ][ z ];
					b = id[ y ][ x ];
					best = 1;
				}
			}
			
		REP( x , 26 )REP( y , 26 )
			if( x != y ){
				if( T[ x ][ y ] && T[ y ][ x ] ){
					a = id[ x ][ y ];
					b = id[ y ][ x ];
					best = 2;
				}
			}
		cout << hamming - best << '\n';
		cout << a << " " << b << '\n';
	}
}


