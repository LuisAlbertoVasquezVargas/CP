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

#define N 9

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int n = 9;
const int m = 3;
const int FULL = (1 << n) - 1;
string S[ N + 1 ];
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		REP( i , n ) cin >> S[ i ];
		REP( i , n ) REP( j , n ) S[ i ][ j ] -= '1';
		bool valid = 1;
		REP( i , n ){
			int mask = 0;
			REP( j , n ) mask |= (1 << S[ i ][ j ]);
			if( mask == FULL ) continue;
			valid = 0;
			break;
		}
		REP( j , n ){
			int mask = 0;
			REP( i , n ) mask |= (1 << S[ i ][ j ]);
			if( mask == FULL ) continue;
			valid = 0;
			break;
		}
		for( int i = 0 ; i < n ; i += m )
			for( int j = 0 ; j < n ; j += m ){
				int mask = 0;
				REP( a , m ) REP( b , m )
					mask |= (1 << S[ i + a ][ j + b ]);
				if( mask == FULL ) continue;
				valid = 0;
				break;
			}
		cout << (valid ? "Valid" : "Invalid" ) << '\n';
	}
}




