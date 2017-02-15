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
	int n , m;
	while( cin >> n >> m ){
		pii best( INT_MIN , INT_MIN );
		for( int i = max( 1 , m - 1 ) ; i <= min( m + 1 , n ) ; ++i ){
			if( i < m ){
				best = max( best , mp( i , -i ) );
			}else if( i == m ){
				best = max( best , mp( 0 , -i ) );
			}else{
				best = max( best , mp( n - i + 1 , -i ) );
			}
		}
		printf( "%d\n" , -best.se );	
	}
}


