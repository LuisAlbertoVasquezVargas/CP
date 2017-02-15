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

#define N 100000
#define MOD 1000000007LL

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;

/*
vi a;
vvi memo , used;
int dp( int pos , int last ){
	if( pos < 0 ) return 0;
	if( used[ pos ][ last ] ) return memo[ pos ][ last ];
	used[ pos ][ last ] = 1;
	int &dev = memo[ pos ][ last ] = dp( pos - 1 , last );
	if( a[ pos ] <= last ) dev = max( dev , 1 + dp( pos - 1 , a[ pos ] ) );
	return dev;
}
vi doit( vi v ){
	memo = used = vvi( SZ( v ) + 1 , vi( SZ( v ) + 1 ) );
	a = v;
	vi vec( SZ( v ) );
	REP( i , SZ(v) ) vec[ i ] = dp( i , a[ i ] );
	return vec;
}
int dp2( int pos , int last ){
	if( pos >= SZ(a) ) return 0;
	if( used[ pos ][ last ] ) return memo[ pos ][ last ];
	used[ pos ][ last ] = 1;
	int &dev = memo[ pos ][ last ] = dp2( pos + 1 , last );
	if( a[ pos ] <= last ) dev = max( dev , 1 + dp2( pos + 1 , a[ pos ] ) );
	return dev;
}
vi doit2( vi v ){
	memo = used = vvi( SZ( v ) + 1 , vi( SZ( v ) + 1 ) );
	a = v;
	vi vec( SZ( v ) );
	REP( i , SZ(v) ) vec[ i ] = dp2( i , a[ i ] );
	return vec;
}
void impr( vi &v ){
	for( auto x : v ) cout << x << " "; cout << endl;
}
bool f( vi v ){
	int n = SZ( v );
	vi m1 = doit( v );
	vi m2 = doit2( v );
	
	impr( v );
	impr( m1 );
	impr( m2 );
	REP( i , n ) cout << m1[ i ] + m2[ i ] - 1 << " " ; cout << endl;
	test();
	
	REP( i , n )
		if( m1[ i ] + m2[ i ] - 1 != v[ i ] + 1 ) return 0;
	
	return 1;
}

int solve( int n ){
	vi v( n );
	int ans = 0;
	REP( i , n ) v[ i ] = i;
	do{
		if( f( v ) ) ans ++;
	}while( next_permutation( all( v ) ) );
	return ans;
}
*/
ull AC[ N + 5 ];
int main(){
	//cout << 3 << " " << solve( 3 ) << endl;
	//for( int i = 1 ; i <= 10 ; ++i ) cout << i << " " << solve( i ) << endl;
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vpii v;
		REP( i , n ){
			int x , f;
			sc( x ) , sc( f );
			v.pb( mp( x , f ) );
		}
		sort( all( v ) );
		REP( i , n ) AC[ i + 1 ] = AC[ i ] + (ull)v[ i ].se;
		ull ans1 = 0;
		REP( i , n ) ans1 += AC[ i + 1 ] * (ull) v[ i ].se;
		ull ans2 = 1;
		REP( i , n - 1 ) ans2 = (ans2 * (ull)(v[ i ].se + 1 ))%MOD;
		cout << "Case " << tc + 1 << ": " << ans1 << " " << ans2 << '\n';
	}	
}


