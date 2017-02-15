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

#define N 5000
#define MOD 1000000007
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

typedef ll Flow;
typedef ll Cost;
const Flow INF = (1LL<<60);
struct Edge {
    int src, dst;
    Cost cst;
    Flow cap;
    int rev;
    Edge(){}
    Edge( int src , int dst , Cost cst , Flow cap , int rev ) : src( src ) , dst( dst ) , cst( cst ) , cap( cap ) , rev( rev ){}
};
bool operator<(const Edge a, const Edge b) {
    return a.cst>b.cst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge( Graph&G , int u , int v , Flow c , Cost l ) {
    G[u].pb( Edge( u , v , l , c , G[v].size() ) );
    G[v].push_back( Edge( v , u , -l, 0 , (int)G[u].size() - 1 ) );
}
// returns the max_flow_mincost with cost <= K

pair< Flow, Cost > flow( Graph &G , int s , int t , ll K = INF ) {
    int n = G.size();
    Flow flow = 0;
    Cost cost = 0;
    while( 1 ) {
        priority_queue< Edge > Q;
        vector< int > prev( n , -1 ), prev_num( n , -1 );
        vector< Cost > length( n , INF );
        Q.push( Edge( -1 , s , 0 , 0 , 0 ) );
        prev[ s ] = s;
        while( !Q.empty() ) {
            Edge e = Q.top(); Q.pop();
            int v = e.dst;
            for ( int i = 0 ; i < (int) G[v].size() ; i++ ) {
                if ( G[v][i].cap > 0 && length[ G[v][i].dst ] > e.cst + G[v][i].cst ) {
                    prev[ G[v][i].dst ] = v;
                    Q.push( Edge( v, G[v][i].dst , e.cst + G[v][i].cst , 0 , 0 ) );
                    prev_num[ G[v][i].dst ] = i;
                    length[ G[v][i].dst  ] = e.cst + G[v][i].cst;
                }
            }
        }
        if( prev[t] < 0 ) return make_pair( flow , cost );
        Flow mi = INF;
        Cost cst = 0;
        for( int v = t ; v != s ; v = prev[v] ) {
            mi = min( mi , G[prev[v]][prev_num[v]].cap );
            cst += G[prev[v]][prev_num[v]].cst;
        }
	if( cst > K ) return make_pair(flow, cost);
	if( cst != 0 ) mi = min(mi, K/cst);
	K -= cst*mi;
        cost+=cst*mi;

        for ( int v = t ; v != s ; v = prev[v] ) {
            Edge &e = G[prev[v]][prev_num[v]];
            e.cap -= mi;
            G[ e.dst ][ e.rev ].cap += mi;
        }
        flow+=mi;
    }
}
int orig[ N + 5 ] , dest[ N + 5 ] ;
ll weight[ N + 5 ];
int main()
{
	int n , m , u , v ;
	ll cost , data , capacity;
	while( sc( n ) == 1 ){
		sc( m );
		Graph G( n + 1 );
		REP( i , m ){
			scanf( "%d%d%lld" , &u , &v , &cost );
			orig[ i ] = u , dest[ i ] = v , weight[ i ] = cost;
		}
		scanf( "%lld%lld" , &data , &capacity );
		
		
		add_edge( G , 0 , 1 , data , 0 );
		
		REP( i , m ){
			u = orig[ i ] , v = dest[ i ] , cost = weight[ i ];
			add_edge( G , u , v , capacity , cost );
			add_edge( G , v , u , capacity , cost );
		}
		
		pair< Flow, Cost > p = flow( G , 0 , n );
		/*
		cout << "Flow   Cost" << endl;
		cout << p.fi << " " << p.se << endl;
		*/
		if( p.fi != data ) puts( "Impossible." );
		else printf( "%lld\n" , p.se );
		
	}
}


