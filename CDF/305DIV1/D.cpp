#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define INF (1<<30)
#define N 200000

#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef long long ll;

struct flowGraph{
	int n , m , s , t , E;
	vi to , cap , NEXT;//maxe * 2
	vi last , now , dist;// maxv
	flowGraph(){}
	flowGraph( int n , int m , int s , int t ) : n( n ) , m( m ) , s( s ) , t( t ) {
		to = cap = NEXT = vi( 2 * m + 5 );
		last = now = dist = vi( n + 5 );
		E = 0;
		last = vi( n + 5 , -1 );
	}
	void add( int u , int v , int uv , int vu = 0 ){
		to[ E ] = v ; cap[ E ] = uv ; NEXT[ E ] = last[ u ] ; last[ u ] = E ++;
		to[ E ] = u ; cap[ E ] = vu ; NEXT[ E ] = last[ v ] ; last[ v ] = E ++;
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
void buildCirculationGraph( int n , vi &from , vi &to , vi &lo , vi &hi , int points ){
	int s = n , t = n + 1;
	flowGraph G( n + 2 , 1000000 , s , t );
	vi d( n + 2 );
	REP( i , SZ( from ) ){
		G.add( from[ i ] , to[ i ] , hi[ i ] - lo[ i ] );
		d[ from[ i ] ] += lo[ i ];
		d[ to[ i ] ] -= lo[ i ];
	}
	//For each v with d(v) < 0, add arc (s, v) with capacity -d(v). 
    //For each v with d(v) > 0, add arc (v, t) with capacity d(v).
	REP( i , n )
		if( d[ i ] < 0 ) G.add( s , i , -d[ i ] );
		else if( d[ i ] > 0 ) G.add( i , t , d[ i ] );
	int f = G.maxFlow();
	/*
	bool solve = 1;
    for( int e = last[ s ] ; e != -1 ; e = next[ e ] )
        if( cap[ e ] ) {
            solve = 0;
            break;
        }
    puts( solve ? "YES" : "NO" );
	*/
	REP( i , points ){
		if( hi[ i ] - G.cap[ 2 * i ] == 1 ) {
			putchar( 'r' );
		}else putchar( 'b' );
	}
	puts( "" );
}
vi UNIQUE( vi x ){
	sort( all( x ) );
	x.resize( unique( all( x ) ) - x.begin() );
	return x;
}
int getId( vi &v , int x ){
	return lower_bound( all( v ) , x ) - v.begin();
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		vi X , Y;
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			X.pb( x ) , Y.pb( y );
		}
		vi A = UNIQUE( X ) , B = UNIQUE( Y );
		int nodes = SZ( A ) + SZ( B ) + 2 , s = nodes - 1 , t = s - 1;
		vi deg( nodes );
		vi from , to , lo , hi;
		REP( i , n ) {
			int u = getId( A , X[ i ] ) , v = SZ( A ) + getId( B , Y[ i ] );
			from.pb( u ) , to.pb( v ) , 
			lo.pb( 0 ) , hi.pb( 1 );
			deg[ u ] ++ , deg[ v ] ++;
		}
		REP( i , SZ( A ) ){
			int u = i;
			from.pb( s ) , to.pb( u ) , 
			lo.pb( deg[ u ]/2 ) , hi.pb( (deg[ u ] - 1)/2 + 1);
		}
		REP( i , SZ( B ) ){
			int v = SZ( A ) + i;
			from.pb( v ) , to.pb( t ) , 
			lo.pb( deg[ v ]/2 ) , hi.pb( (deg[ v ] - 1)/2 + 1);
		}
		from.pb( t ) , to.pb( s ) , lo.pb( 0 ) , hi.pb( 1000000 );
		buildCirculationGraph( nodes , from , to , lo , hi , n );
	}
}


