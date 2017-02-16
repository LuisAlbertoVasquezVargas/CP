#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 2005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

vi E[ N ];
bool M[ N ][ N ];
void add_edge( int u , int v ){
	E[ u ].pb( v );
	E[ v ].pb( u );
}
int main(){
	int n , k , lvl;
	while( cin >> k ){
		clr( M , 0 );
		n = 1;
		lvl = 0;
		REP( i , N ) E[ i ].clear();
		vi v;
		while( k ){
			if( k & 1 ) v.pb( 1 );
			else v.pb( 0 );
			k >>= 1;
		}
		int nv = v.size();
		reverse( all( v ) );
		for( int i = 1 ; i < nv ; ++i ){
			k = v[ i ];
			//cout << k << endl;
			add_edge( n , n + 1 );
			add_edge( n , n + 2 );
			add_edge( n + 1 , n + 3 );
			add_edge( n + 2 , n + 3 );
			n += 3;
			lvl += 2;
			if( k & 1 ){
				add_edge( n , n + lvl + 1 );
				add_edge( 1 , n + 1 );
				REP( i , lvl ) add_edge( n + 1 + i , n + 2 + i );
				n += lvl + 1;
				lvl ++;
			}
			//k >>= 1;
		}
		add_edge( n , 0 );
		n++;
		cout << n << endl;
		REP( i , n ) FOR( v , E[ i ] ) M[ i ][ *v ] = M[ *v ][ i ] = 1;
		printf( "%d\n" , n );
		REP( i , n )REP( j , n ) printf( "%c%s" , M[ i ][ j ] ? 'Y':'N' , j + 1 == n ? "\n":"" );
		//REP( i , n )REP( j , n ) if( i < j && M[ i ][ j ] ) cout << i << " " << j << endl;
		cout << n << endl;
 	}
}


