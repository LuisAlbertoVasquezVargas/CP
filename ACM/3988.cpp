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

vi id;
int Find( int x ){ return id[ x ] = ( id[ x ] == x ? x : Find( id[ x ] ) );}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ) id[ pu ] = pv;
}
struct Edge{
	int u , v , w;
	Edge(){}
	Edge( int u , int v , int w ) : u( u ) , v( v ) , w( w ) {}
};
bool operator < ( const Edge &e1 , const Edge &e2 ){
	return e1.w < e2.w;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int n , m;
		cin >> n >> m;
		id = vi( n );
		REP( i , n ) id[ i ] = i;
		map< string , int > ID;
		int it = 0;
		vector< Edge > E;
		REP( i , m ){
			string a , b;
			int w;
			cin >> a >> b >> w;
			if( !ID.count( a ) ) ID[ a ] = it ++;
			if( !ID.count( b ) ) ID[ b ] = it ++;
			int u = ID[ a ] , v = ID[ b ];
			E.pb( Edge( u , v , w ) );
		}
		sort( all( E ) );
		int ans = 0;
		for( auto e : E ){
			int u = e.u , v = e.v , w = e.w;
			if( Find( u ) != Find( v ) ) Union( u , v ) , ans += w;
		}
		if( tc ) puts( "" );
		printf( "%d\n" , ans );
	}
}


