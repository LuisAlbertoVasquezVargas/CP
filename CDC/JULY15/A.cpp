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

const int n = 6;
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		bool possible = 0;
		vector< string > V( n );
		REP( i , n ) cin >> V[ i ];
		
		REP( i , n ){
			vi vec;
			REP( j , n )
				if( (j != (i ^ 1)) && j != i && V[ i ] == V[ j ] ) vec.pb( j );
			int cnt = 0;
			vi vis( 4 );
			REP( j , SZ(vec) ){
				if( vis[ j ] ) continue;
				cnt ++;
				vis[ j ] = 1;
				for( int k = j + 1 ; k < SZ(vec) ; ++ k )
					if( (vec[ j ] ^ vec[ k ]) == 1 ) vis[ k ] = 1;
			}
			if( cnt >= 2 ) possible = 1;
		}
		cout << ( possible ? "YES" : "NO" ) << '\n';
	}
}



