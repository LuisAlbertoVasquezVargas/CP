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

typedef int Flow;
typedef int Cost;
const Flow INF = 0x3f3f3f3f;
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
pair< Flow, Cost > flow( Graph &G , int s , int t ) {
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
 
 
        cost+=cst*mi;
 
        for ( int v = t ; v != s ; v = prev[v] ) {
            Edge &e = G[prev[v]][prev_num[v]];
            e.cap -= mi;
            G[ e.dst ][ e.rev ].cap += mi;
        }
        flow+=mi;
    }
}
int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		vi T( n );
		REP( i , n - 1 ) sc( T[ i ] );
		Graph G( n + 1 );
		int s = n , t = n - 1;
		REP( v , n - 1 ) add_edge( G , s , v , T[ v ] , 0 );
		REP( i , m ){
			int u , v , f , c;
			sc( u ) , sc( v ) , sc( f ) , sc( c );
			u -- , v --;
			add_edge( G , u , v , f , c );
		}
		auto ans = flow( G , s , t );
		printf( "%d %d\n" , ans.fi , ans.se );
	}
}


