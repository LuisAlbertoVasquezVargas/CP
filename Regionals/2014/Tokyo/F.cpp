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
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 500
#define M 50000
#define INF 12345678

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< pii > vpii;

int orig[ M + 5 ] , dest[ M + 5 ] , peso[ M + 5 ];
int id[ N + 5 ];
int n;
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] ) );}
void init(){
	REP( i , n ) id[ i ] = i;
}
struct Edge{
	int u , v , w , ind;
	Edge(){}
	Edge( int u , int v , int w , int ind ) : u( u ) , v( v ) , w( w ) , ind( ind ) {}
};
bool operator < ( const Edge &a , const Edge &b ){ return a.w < b.w ;}
int getMST( vector< Edge > &E ){
	init();
	int ans = 0;
	REP( i , SZ( E ) ){
		int pu = Find( E[ i ].u ) , pv = Find( E[ i ].v );
		if( pu != pv ){
			ans += E[ i ].w;
			id[ pu ] = pv;
		}
	}
	return ans;
}

int main(){
	int m;
	while( sc( n ) == 1 ){
		sc( m );
		vector< Edge > E;
		REP( i , m ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			u -- , v --;
			orig[ i ] = u;
			dest[ i ] = v;
			peso[ i ] = w;
			E.pb( Edge( u , v , w , i ) );
		}
		vi IND;
		init();
		sort( all( E ) );
		int MST = 0;
		REP( i , SZ( E ) ){
			int pu = Find( E[ i ].u ) , pv = Find( E[ i ].v );
			if( pu != pv ){
				MST += E[ i ].w;
				id[ pu ] = pv;
				IND.pb( E[ i ].ind );
			}
		}
		int a = 0 , b = 0;
		for( auto ind : IND ){
			vector< Edge > E2;
			REP( i , m ) 
				if( E[ i ].ind != ind ) E2.pb( E[ i ] );
			int mst = getMST( E2 );
			int u = orig[ ind ] , v = dest[ ind ] , w = peso[ ind ];
			if( Find( u ) != Find( v ) ){
				a ++ , b += w;
			}else{
				if( mst > MST ) a ++ , b += w;
			}
		}
		printf( "%d %d\n" , a , b );
	}	
}


