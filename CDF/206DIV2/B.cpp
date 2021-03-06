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

int solve( vi &v , int a , int b ){
	int ans = 0;
	REP( i , SZ(v) )
		ans += min( v[ i ] * a , b );
	return ans;
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	int c1 , c2 , c3 , c4;
	while( cin >> c1 >> c2 >> c3 >> c4 ){
		int n , m;
		cin >> n >> m;
		vi a( n ) , b( m );
		REP( i , n ) cin >> a[ i ];
		REP( i , m ) cin >> b[ i ];
		int ans = c4;
		ans = min( ans , 2 * c3 );
		int v1 = solve( a , c1 , c2 );
		int v2 = solve( b , c1 , c2 );
		ans = min( ans , v1 + v2 );
		ans = min( ans , v1 + c3 );
		ans = min( ans , v2 + c3 );
		printf( "%d\n" , ans );
	}
}


