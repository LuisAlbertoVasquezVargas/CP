#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;
 
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
 
#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second
 
#define N 100000
 
typedef pair< int , int > pii;
typedef vector< int > vi;
 
vi G[ N + 5 ] , C[ N + 5 ];
inline void add( int u , int v , int w ){
	G[ u ].pb( v );
	C[ u ].pb( w );
}
 
int DP[ N + 5 ] , MAXI[ N + 5 ];
vi order;
void DFS( int u , int p = -1 ){
	order.pb( u );
	DP[ u ] = 1 , MAXI[ u ] = 0;
	for( auto v : G[ u ] ){
		if( v == p ) continue;
		DFS( v , u );
		DP[ u ] += DP[ v ];
		MAXI[ u ] = max( MAXI[ u ] , DP[ v ] );
	}
}
 
int target;
int L , R;

void fillVec( int u , int p , int d , int cnt , int &ans , vi &vec ){
	if( ans ) return;
	if( d <= R ){
		if( L <= d ){
			if( (cnt<<1) - d > 0 ) {
				ans = 1;
				return;
			}
		}
		vec[ d ] = max( vec[ d ] , cnt );
	}
	if( d >= R ) return;
	REP( i , SZ(G[ u ]) ){
		int v = G[ u ][ i ] , w = C[ u ][ i ];
		if( v == p ) continue;
		if( ans ) return;
		fillVec( v , u , d + 1 , cnt + (w <= target) , ans , vec );
	}
}
 
deque< pii > RMQ;
inline void insert( int x , int pos ){
	while( !RMQ.empty() && RMQ.back().fi < x ) RMQ.pop_back();
	RMQ.pb( mp( x , pos ) );
}
inline void erase( int x , int pos ){
	if( !RMQ.empty() && RMQ[ 0 ] == mp( x , pos ) ) RMQ.pop_front();
}
 
int solve( int root ){
	order.clear();
	DFS( root );
	root = -1;
	int n = SZ( order );
	for( auto u : order ){
		MAXI[ u ] = max( MAXI[ u ] , n - DP[ u ] );
		if( (MAXI[ u ] << 1) <= n ){
			root = u;
			break;
		}
	}
	vi vecAt( R + 1 , -1 );
	
	int ans = 0;
	for( auto v : G[ root ] ){
		int pos = find( all( G[ v ] ) , root ) - G[ v ].begin();
		int w = C[ v ][ pos ];
		G[ v ].erase( G[ v ].begin() + pos );
		C[ v ].erase( C[ v ].begin() + pos );
		vi vec( R + 1 , -1 );
	
		fillVec( v , -1 , 1 , w <= target , ans , vec );
		if( ans ){
			G[ v ].insert( G[ v ].begin() + pos , root );
			C[ v ].insert( C[ v ].begin() + pos , w );
			return 1;
		}
		ans |= solve( v );
		G[ v ].insert( G[ v ].begin() + pos , root );
		C[ v ].insert( C[ v ].begin() + pos , w );
		if( ans ) return 1;
		
		RMQ.clear();
		
		for( int a = R - 1 , lo = 0 , hi = -1 ; a >= 1 ; --a ){
			int nlo = max( 1 , L - a ) , nhi = R - a;
			while( hi + 1 <= nhi ){
				insert( (vec[ hi + 1 ] << 1) - (hi + 1) , hi + 1 );
				hi ++;
			}
			
			while( lo < nlo ){
				erase( (vec[ lo ] << 1) - lo , lo );
				lo ++;
			}
			
			if( RMQ[ 0 ].fi + (vecAt[ a ] <<1) - a > 0 ) return 1;
		}
		
		for( int k = 1 ; k <= R ; ++k )
			vecAt[ k ] = max( vecAt[ k ] , vec[ k ] );
	}
	return 0;
}
bool f( int x ){
	target = x;
	return solve( 0 );
}
int main(){
	int cases;
	scanf( "%d" , &cases );
	REP( tc , cases ){
		int n;
		scanf( "%d%d%d" , &n , &L , &R );
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
		vi W;
		REP( i , n - 1 ){
			int u , v , w;
			scanf( "%d%d%d" , &u , &v , &w );
			u-- , v --;
			add( u , v , w );
			add( v , u , w );
			W.pb( w );
		}
		sort( all( W ) );
		W.resize( unique( all( W ) ) - W.begin() );
		
		int lo = 0 , hi = SZ(W) - 1;
		if( !f( W[ hi ] ) ){
			puts( "-1" );
			continue;
		}
		if( f( W[ lo ] ) ){
			printf( "%d\n" , W[ lo ] );
			continue;
		}
		while( hi - lo > 1 ){
			int med = (lo + hi) >> 1;
			if( f( W[ med ] ) ) hi = med;
			else lo = med;
		}
		printf( "%d\n" , W[ hi ] );
	}	
}  



