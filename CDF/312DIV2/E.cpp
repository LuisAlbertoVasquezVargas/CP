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

#define cte 100000
#define N 300000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< pii > vpii;

int get( vpii &v , int lo , int hi ){
	int n = SZ(v);
	hi = min( hi , n - 1 );
	lo = max( lo , 0 );
	int ans = 0;
	for( int i = lo ; i <= hi ; ++i ) ans += v[ i ].se;
	return ans;
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		vpii v;
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			v.pb( mp( x , y ) );
		}
		sort( all( v ) );
		int pos = lower_bound( all( v ) , mp( 0 , 0 ) );
		int L = pos;
		L = min( L , n - L );
		int ans = 0;
		ans = max( ans , get( v , pos - L , pos + L ) );
		ans = max( ans , get( v , pos - L - 1 , pos + L - 1 ) );
		printf( "%d\n" , ans );
	}
}

