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

#define test() cerr << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define INF (1<<30)

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

struct flowGraph{
	int n , m , s , t , E;
	vi from , to , cap , NEXT;//maxe * 2
	vi last , now , dist;// maxv
	flowGraph(){}
	flowGraph( int n , int m , int s , int t ) : n( n ) , m( m ) , s( s ) , t( t ) {
		from = to = cap = NEXT = vi( 2 * m + 5 );
		last = now = dist = vi( n + 5 );
		E = 0;
		last = vi( n + 5 , -1 );
	}
	void add( int u , int v , int uv , int vu = 0 ){
		from[ E ] = u ; to[ E ] = v ; cap[ E ] = uv ; NEXT[ E ] = last[ u ] ; last[ u ] = E ++;
		from[ E ] = v ; to[ E ] = u ; cap[ E ] = vu ; NEXT[ E ] = last[ v ] ; last[ v ] = E ++;
	}
	bool bfs(){
		REP( i , n ) dist[ i ] = INF;
		queue< int > Q;
		dist[ t ] = 0;
		Q.push( t );
		while( !Q.empty() ){
			int u = Q.front() ; Q.pop();
			for( int e = last[ u ] ; e != -1 ; e = NEXT[ e ] ){
				int v = to[ e ];
				if( cap[ e ^ 1 ] && dist[ v ] >= INF ){
					dist[ v ] = dist[ u ] + 1;
					Q.push( v );
				}
			}
		}
		return dist[ s ] < INF;
	}
	int dfs( int u , int f ){
		if( u == t ) return f;
		for( int &e = now[ u ] ; e != -1 ; e = NEXT[ e ] ){
			int v = to[ e ];
			if( cap[ e ] && dist[ u ] == dist[ v ] + 1 ){
				int ret = dfs( v  , min( f , cap[ e ] ) );
				if( ret ){
					cap[ e ] -= ret;
					cap[ e ^ 1 ] += ret;
					return ret;
				}
			}
		}
		return 0;
	}
	ll maxFlow(){
		ll flow = 0;
		while( bfs() ){
		
			REP( i , n ) now[ i ] = last[ i ];
			while( 1 ){
				int f = dfs( s , INF );
				if( !f ) break;
				flow += f;
			}
		}
		return flow;
	}
};
void solve( int n , int m , int s , int t , int &best , vector< deque< int > > &v , vvi &F , int x , int y ){
	flowGraph G( n , m , s , t );
	REP( i , 10 ) REP( j , 10 )
		if( i + j == 9 ) G.add( i , 10 + j , INF );
	int E = G.E;
	REP( i , 10 ) G.add( s , i , F[ 0 ][ i ] );
	REP( i , 10 ) G.add( 10 + i , t , F[ 1 ][ i ] );


	int cur = G.maxFlow();
	/*
	DEBUG2( x , y );
	DEBUG( cur );
	*/
	cur ++;
	vvi FF = F;
	vector< deque< int > > w( 2 );
	w[ 0 ].pb( x );
	w[ 1 ].pb( y );
	for( int e = 1 ; e < E ; e += 2 ){
		if( G.cap[ e ] ){
			int a = G.to[ e ] , b = G.from[ e ] - 10;
			assert( 0 <= a && a <= 9 );
			assert( 0 <= b && b <= 9 );
			//DEBUG2( a , b );
			int ww = G.cap[ e ];
			FF[ 0 ][ a ] -= ww;
			FF[ 1 ][ b ] -= ww;
			REP( k , ww ){
				w[ 0 ].push_front( a );
				w[ 1 ].push_front( b );
			}
		}
	}
	while( FF[ 0 ][ 0 ] > 0 && FF[ 1 ][ 0 ] > 0 ){
		FF[ 0 ][ 0 ] --;
		FF[ 1 ][ 0 ] --;
		REP( k , 2 ) w[ k ].push_back( 0 );
		cur ++;
	}
	REP( k , 2 ){
		for( int a = 0 ; a <= 9 ; ++a )
			REP( i , FF[ k ][ a ] ) w[ k ].push_front( a );
	}
	if( best < cur ){
		best = cur;
		v = w;
	}
}

void solve2( int &best , vector< deque< int > > &v , vvi &F ){
	
	int cur = 0;
	cur ++;
	vvi FF = F;
	vector< deque< int > > w( 2 );
	while( FF[ 0 ][ 0 ] > 0 && FF[ 1 ][ 0 ] > 0 ){
		FF[ 0 ][ 0 ] --;
		FF[ 1 ][ 0 ] --;
		REP( k , 2 ) w[ k ].push_back( 0 );
		cur ++;
	}
	REP( k , 2 ){
		for( int a = 0 ; a <= 9 ; ++a )
			REP( i , FF[ k ][ a ] ) w[ k ].push_front( a );
	}
	if( best < cur ){
		best = cur;
		v = w;
	}
}


void solve3( int n , int m , int s , int t , int &best , vector< deque< int > > &v , vvi &F , int x , int y ){
	int cur = 0;
	vector< deque< int > > w( 2 );
	vvi FF = F;
	while( FF[ 0 ][ 0 ] > 0 && FF[ 1 ][ 0 ] > 0 ){
		FF[ 0 ][ 0 ] --;
		FF[ 1 ][ 0 ] --;
		REP( k , 2 ) w[ k ].push_back( 0 );
		cur ++;
	}
	
	flowGraph G( n , m , s , t );
	REP( i , 10 ) REP( j , 10 )
		if( i + j == 9 ) G.add( i , 10 + j , INF );
	int E = G.E;
	REP( i , 10 ) G.add( s , i , FF[ 0 ][ i ] );
	REP( i , 10 ) G.add( 10 + i , t , FF[ 1 ][ i ] );
	cur += G.maxFlow();
	/*
	DEBUG2( x , y );
	DEBUG( cur );
	*/
	cur ++;
	
	
	w[ 0 ].pb( x );
	w[ 1 ].pb( y );
	for( int e = 1 ; e < E ; e += 2 ){
		if( G.cap[ e ] ){
			int a = G.to[ e ] , b = G.from[ e ] - 10;
			assert( 0 <= a && a <= 9 );
			assert( 0 <= b && b <= 9 );
			//DEBUG2( a , b );
			int ww = G.cap[ e ];
			FF[ 0 ][ a ] -= ww ; 
			FF[ 1 ][ b ] -= ww;
			REP( k , ww ){
				w[ 0 ].push_front( a );
				w[ 1 ].push_front( b );
			}
		}
	}

	REP( k , 2 ){
		for( int a = 0 ; a <= 9 ; ++a )
			REP( i , FF[ k ][ a ] ) w[ k ].push_front( a );
	}
	if( best < cur ){
		best = cur;
		v = w;
	}
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	string s;
	while( cin >> s ){
		vvi F( 2 , vi( 10 ) );
		REP( i , SZ(s) ){
			int x = s[ i ] - '0';
			REP( j , 2 ) F[ j ][ x ] ++;
		}
		int n = 10 + 10 + 2;
		int s = n - 1 , t = n - 2;
		int m = 10 + 10 + 10 * 10 + 5;
		int best = -1;
		vector< deque< int > > v( 2 );
		for( int x = 0 ; x <= 9 ; ++x ){
			int y = 10 - x;
			if( y >= 0 && y <= 9 ){
				if( F[ 0 ][ x ] && F[ 1 ][ y ] ){
					F[ 0 ][ x ] -- , F[ 1 ][ y ] --;
					solve( n , m , s , t , best , v , F , x , y );
					solve3( n , m , s , t , best , v , F , x , y );
					F[ 0 ][ x ] ++ , F[ 1 ][ y ] ++;
				}
			}
		}
		
		solve2( best , v , F );
		assert( best != -1 );
		//DEBUG( best );
		REP( k , 2 ) {
			for( auto x : v[ k ] ) cout << x;
			cout << '\n';
		}
		//test();
	}	
}


