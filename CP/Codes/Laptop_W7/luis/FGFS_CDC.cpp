#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )

#define all( v ) v.begin() , v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define N 100005

typedef vector< int > vi;
typedef pair< int , int > pii;
typedef vector< pii > vpii;

int n , k ;
int A[ N ] , B[ N ] , P[ N ];
void input()
{
	sc( n ) , sc( k );
	REP( i , n ) sc( A[ i ] ) , sc( B[ i ] ) , sc( P[ i ] );
}
bool cmp( pii a , pii b ){
	return a.se < b.se;
}
void print( vpii v ){
	int nv = v.size();
	cout << endl;
	REP( i , nv ) cout << v[ i ].fi << " " << v[ i ].se << endl;
	
}
int solve( vpii &v ){
	//print( v );
	int ans = 0;
	int nv = v.size();
	if( nv == 0 ) return 0;
	sort( all( v ) , cmp );
	ans++;
	int F = v[ 0 ].se;
	for( int i = 1 ; i < nv ; ++i )
		if( v[ i ].fi >= F )
			ans++ , F = v[ i ].se;
	return ans;
}
void solve()
{
	vi p( P , P + n );
	sort( all( p ) );
	int sz = unique( all( p ) ) - p.begin();
	map< int , int > id;
	REP( i , sz ) id[ p[ i ] ] = i;
	vector< vpii > V( sz );
	REP( i , n ) V[ id[ P[ i ] ] ].pb( mp( A[ i ] , B[ i ] ) );
	int ans = 0;
	REP( i , sz ) ans += solve( V[ i ] );
	printf( "%d\n" , ans );
}
int main()
{
	int cases;
	sc( cases );
	while( cases -- ){
		input();
		solve();
	}
}
