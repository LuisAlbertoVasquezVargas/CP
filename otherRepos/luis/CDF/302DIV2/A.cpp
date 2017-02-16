#include<bits/stdc++.h>
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

typedef vector< int > vi;

int main(){
	int K;
	string s;
	while( cin >> K >> s ){
		vector< string > V;
		vi vis( 500 );
		for( int i = 0 ; i < SZ( s ) ; ++i ){
			int ind;
			vis[ s[ i ] ] = 1;
			for( int j = i ; j < SZ( s ) ; ++j ){
				if( vis[ s[ j ] ] ) ind = j;
				else break;
			}
			//cout << i << ind - i + 1 << endl;
			V.pb( s.substr( i , ind - i + 1 ) );
			i = ind;
		}
		if( SZ( V ) < K ){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		REP( i , K - 1 ) cout << V[ i ] << '\n';
		for( int i = K - 1 ; i < SZ( V ) ; ++i ) cout << V[ i ] ;
		cout << '\n';
	}
}


