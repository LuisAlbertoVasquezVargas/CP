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

#define test puts("************test************");
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

struct Node{
	ll id , lo , hi;
	Node(){}
	Node( ll id , ll lo , ll hi ) : id( id ) , lo( lo ) , hi( hi ){}
};
bool cmphi ( const Node &a , const Node &b ){
	return a.hi < b.hi;
}
bool cmplo ( const Node &a , const Node &b ){
	return a.lo < b.lo;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int n , m;
	while( cin >> n >> m ){
		
		vll A( n ) , B( n );
		REP( i , n ) cin >> A[ i ] >> B[ i ];
		vll seg( m );
		REP( i , m ) cin >> seg[ i ];
		
		vector< Node > V , W;
		REP( i , m ) W.pb( Node( i , 0 , seg[ i ] ) );
		REP( i , n - 1 )
			V.pb( Node( i , A[ i + 1 ] - B[ i ] , B[ i + 1 ] - A[ i ] ) );
		
		sort( all( V ) , cmplo );
		sort( all( W ) , cmphi );
		vi vec( n - 1 , -1 );
		bool possible = 1;
		for( int i = 0 , j = 0 ; i < SZ(V) ; ++i ){
			while( j < SZ(W) && W[ j ].hi < V[ i ].lo ) j ++;
			if( j < SZ(W) && V[ i ].lo <= W[ j ].hi && W[ j ].hi <= V[ i ].hi ){
				vec[ V[ i ].id ] = W[ j ].id;
				j ++;
			}else possible = 0;
		}
		if( !possible ){
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		REP( i , SZ(vec) ) cout << vec[ i ] + 1 << ' ';
		cout << '\n';
	}
}



