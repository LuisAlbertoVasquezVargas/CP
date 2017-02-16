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

#define N 100005
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

#define MAX_V 2005
#define MAX_E 1000005

int E , s , t ;
int cap[ 2*MAX_E ] , to[ 2*MAX_E ] , next[ 2*MAX_E ];
int last[ MAX_V ] ;
bool visited[ MAX_V ];
int dist[ MAX_V ] , q[ MAX_V ] , now[ MAX_V ];
void clear(){
    clr( last , -1 ); 
    E = 0;
}
void add_edge(int u, int v, int uv, int vu = 0 ){
    to[ E ] = v, cap[ E ] = uv, next[ E ] = last[ u ]; last[ u ] = E++;
    to[ E ] = u, cap[ E ] = vu, next[ E ] = last[ v ]; last[ v ] = E++;
}
bool bfs(){
	clr( dist , -1 );
	int head = 0 , tail = 0;
	q[ tail ] = t; ++tail;
	dist[ t ] = 0;
	while( head < tail ){
		int v = q[ head ]; ++head;
		for( int e = last[ v ] ; e != -1 ; e = next[ e ] ){
			if( cap[ e^1 ] > 0 && dist[ to[ e ] ] == -1 ){
				q[ tail ] = to[ e ]; ++tail;
				dist[ to[ e ] ] = dist[ v] + 1;
			}
		}
	}
	return dist[ s ] != -1;
}

int dfs( int v , int f ){
	if( v == t ) return f;
	for( int &e = now[ v ] ; e != -1 ; e = next[ e ] ){
		if( cap[ e ] > 0 && dist[ to[ e ] ] == dist[ v ] - 1 ){
			int ret = dfs( to[ e ] , min( f , cap[ e ] ) );
			if( ret > 0 ){
				cap[ e ] -= ret;
				cap[ e^1 ] += ret;
				return ret;
			}
		}
	}
	return 0;
}

int max_flow( int source , int sink){
	s = source; t = sink;
	int f = 0;
	int x;
	while( bfs() ){
		REP( i , MAX_V ) now[i] = last[i];
		while( 1 ){
			x = dfs( s , INT_MAX );
			if( x == 0 ) break;
			f += x;
		}
	}
	return f;
}
int vis[ MAX_V ];
void bfs( int s ){
	queue< int > Q;
	vis[ s ] = 1;
	Q.push( s );
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		for( int e = last[ u ] ; e != -1 ; e = next[ e ] ){
			int v = to[ e ];
			if( !vis[ v ] && cap[ e ] > 0 ){
				vis[ v ] = 1;
				Q.push( v );
			}
		}
	}
}
int main()
{
	int n , m , e ;
	while( sc( n ) == 1 ){
		sc( m ) , sc( e );
		if( !n ) break;
		clear();
		REP( i , e ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			add_edge( u , n + v , 1 );
		}
		REP( u , n )
			add_edge( n + m , u , 1 );
		REP( v , m )
			add_edge( n + v , n + m + 1 , 1 );
		printf( "%d" , max_flow( n + m , n + m + 1 ) );
		clr( vis , 0 );
		bfs( n + m );
		REP( u , n )
			if( !vis[ u ] ) printf( " r%d" , u + 1 );
		REP( v , m ) 
			if( vis[ v + n ] ) printf( " c%d" , v + 1 );
		puts( "" );
	}
}


