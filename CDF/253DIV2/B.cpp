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

int main(){
	string s;
	int K;
	while( cin >> s >> K ){
		int ans = 2 * (K / 2);
		REP( i , SZ( s ) ){
			for( int L = 1 ; 2 * L <= SZ(s) + K - i ; ++L ){
				if( i + L >= SZ(s) ){
					ans = max( ans , 2 * L );
					continue;
				}
				string a = s.substr( i , L );
				string b = s.substr( i + L , L );
				a.resize( SZ(b) );
				if( a == b ) ans = max( ans , 2 * L );
			}
		}
		printf( "%d\n" , ans );
	}
}



