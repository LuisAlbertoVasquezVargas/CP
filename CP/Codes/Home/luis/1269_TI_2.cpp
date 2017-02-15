#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) v.size()

#define mp make_pair
#define fi first
#define se second

#define MAXNODES 100000

typedef pair< int , char > pic;
typedef vector< pic > vpic;
int nodes ;
vpic next[ MAXNODES + 5 ];
bool term[ MAXNODES + 5 ];
int len[ MAXNODES + 5 ] , T[ MAXNODES + 5 ];
void init(){
	nodes = 1;
	REP( i , MAXNODES ) next[ i ].clear();
	clr( term , 0 );
	clr( len , 0 );
}
int getNode( int p , int c ){
	REP( i , SZ( next[ p ] ) )
		if( next[ p ][ i ].se == c ) return next[ p ][ i ].fi;
	return -1;
}
void add( string &s ){
	int n = SZ( s ) , p = 0;
	REP( i , n ){
		char c = s[ i ];
		int q = getNode( p , c );
		if( q == -1 ){
			next[ p ].pb( mp( nodes , c ) );
			p = nodes ++;
		}else p = q;
	}
	term[ p ] = 1;
	len[ p ] = n;
}
void aho(){
	queue< int > Q;
	REP( i , SZ( next[ 0 ] ) )
		Q.push( next[ 0 ][ i ].fi ) , T[ next[ 0 ][ i ].fi ] = 0;
	while( !Q.empty() ){
		int u = Q.front() ; Q.pop();
		REP( i , SZ( next[ u ] ) ){
			int v = next[ u ][ i ].fi;
			char c = next[ u ][ i ].se;
			int j = T[ u ];
			while( j && getNode( j , c ) == -1 ) j = T[ j ];
			j = getNode( j , c );
			
			T[ v ] = j;
			Q.push( v );
			term[ v ] |= term[ T[ v ] ];
			len[ v ] = max( len[ v ] , len[ T[ v ] ] );
		}
	}
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	init();
	string dummy , a , b;
	int n , m;
	cin >> n;
	getline( cin , dummy );
	REP( i , n ){
		getline( cin , a );
		add( a );
	}
	aho();
	cin >> m;
	int I = INT_MAX , J = INT_MAX;
	getline( cin , dummy );
	REP( k , m ){
		getline( cin , b );
		int j = 0;
		REP( i , SZ( b ) ){
			char c = b[ i ];
			while( j && getNode( j , c ) == -1 ) j = T[ j ];
			j = getNode( j , c );
			if( term[ j ] ){
				if( I == INT_MAX ){
					I = k ; J = i - len[ j ] + 1;
				}else if( I == k ) J = min( J , i - len[ j ] + 1 );
			}
		}
	}
	if( I == INT_MAX ) cout << "Passed\n";
	else cout << I + 1 << " " << J + 1 << '\n';
}
