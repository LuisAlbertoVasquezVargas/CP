#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define N 100000
#define INF (1<<29)

typedef pair< int , int > pii;
typedef vector< int > vi;
struct Node{
	string s;
	int rank;
	Node(){}
	Node( string s , int rank ) : s( s ) , rank( rank ) {}
} V[ N + 5 ];

bool operator < ( const Node &a , const Node &b ){
	return a.s < b.s;
	//if( a.s != b.s )return a.s < b.s;
	//return a.rank > b.rank;
}

#define v1 ((node<<1)+1)
#define v2 (v1+1)
#define med ((a+b)>>1)
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

int n;
pii T[ 4*N ];

// valor del rank , indice
pii pull( pii a , pii b ){
	if( a.fi > b.fi ) return a;
	if( b.fi > a.fi ) return b;
	if( a.se < b.se ) return a;
	return b;
}
void build_tree( int node , int a , int b ){
	if( a == b ){
		T[ node ] = mp( V[ a ].rank , a ); 
		return;
	}
	build_tree( LEFT ) , build_tree( RIGHT );
	T[ node ] = pull( T[ v1 ] , T[ v2 ] );
}
void update( int node , int a , int b , int pos , int val ){
	if( pos > b || a > pos ) return;
	if( a == b ){
		T[ node ] = mp( val , a ); 
		return;
	}
	update( LEFT , pos , val ) ;
	update( RIGHT , pos , val );
	T[ node ] = pull( T[ v1 ] , T[ v2 ] );
}
pii query( int node , int a , int b , int lo , int hi ){
	if( lo > b || a > hi ) return mp( -INF , -INF );
	if( a >= lo && hi >= b ) return T[ node ];
	return pull( query( LEFT , lo , hi ) , query( RIGHT , lo , hi ) );
}
void build_tree(){ build_tree( 0 , 0 , n - 1 );}
int main(){
	ios :: sync_with_stdio( 0 );
	int Q , rank;
	string s;
	while( cin >> n ){
		REP( i , n ){
			cin >> s >> rank;
			V[ i ] = Node( s , rank );
		}
		V[ n ] = Node( "" , -INF );
		sort( V , V + n );

		build_tree();
		cin >> Q;
		/*
		REP( i , n ) cout << V[ i ].s << " " << V[ i ].rank << endl;
		cout << endl;
		*/
		REP( q , Q ){
			if( q ) cout << '\n';
			cin >> s;
			
			int L = lower_bound( V , V + n , Node( s  , -INF ) ) - V;
			int R = upper_bound( V , V + n , Node( s + string( 15 , 'z' + 1 ) , -INF ) ) - V;
			/*
			cout << L << " " << R - 1 << endl;
			for( int i = L ; i < R ; ++i ) cout << V[ i ].s << " " << V[ i ].rank << endl;
			cout << endl;
			*/
			vi vec;
			vi values;
			if( L == R ) continue;
			REP( k , 10 ){
				pii p = query( 0 , 0 , n - 1 , L , R - 1 );
				int ind = p.se;
				//cout << "ind " << ind <<  " value : " <<  p.fi << endl;
				if( p.fi < 0 ) break;
				vec.pb( ind );
				values.pb( V[ ind ].rank );
				update( 0 , 0 , n - 1 , ind , -INF );
			}
			int nv = vec.size();
			REP( k , nv ){
				cout << V[ vec[ k ] ].s << '\n';
				update( 0 , 0 , n - 1 , vec[ k ] , values[ k ] );
			}
		}
	}
}
