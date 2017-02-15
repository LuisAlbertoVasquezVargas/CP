#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define FOR(i,c) for(int i=0;i!=(c).size();++i)
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])

#define INF (1<<29)
#define MAXN 3003

typedef int Weight;
typedef vector< int > vi;

// !!!!!!!! following must be initialized by user !!!!!!!!!!!
vi graph[ MAXN ]; 
Weight capacity[ MAXN ][ MAXN ];
int n; // # of vertices
// !!!!!!!!
vi ghtree[ MAXN ]; 
vector<Weight> ghweight[ MAXN ];
int p[ MAXN ] , Prev[ MAXN ]; 
Weight w[ MAXN ] , flow[ MAXN ][ MAXN ];
Weight max_memo[ MAXN ][ MAXN ]; //dp table, initialize to -1

void build_tree() {
	REP( i , MAXN ) w[ i ] = 0;
	clr( p , 0 );
	for( int s = 1 ; s < n ; ++s ){
    	int t = p[ s ];
    	clr( flow , 0 );
    	Weight total = 0;
		while( 1 ){
			queue< int > q; 
			q.push( s );
			clr( Prev , -1 );
			Prev[ s ] = s;
      		while( !q.empty() && Prev[ t ] < 0 ) {
				int u = q.front(); q.pop();
        		FOR( e , graph[ u ] ) if( Prev[ graph[ u ][ e ] ] < 0 && RESIDUE( u , graph[ u ][ e ] ) > 0 )
					Prev[ graph[ u ][ e ] ] = u, q.push( graph[ u ][ e ] );
      		}
      		if( Prev[ t ] < 0 )break;
      		Weight inc = INF;
      		for( int j = t ; Prev[ j ] != j ; j = Prev[ j ] ) inc = min( inc , RESIDUE( Prev[ j ] , j ) );
      		for( int j = t ; Prev[ j ] != j ; j = Prev[ j ] )
				flow[ Prev[ j ] ][ j ] += inc , flow[ j ][ Prev[ j ] ] -= inc;
      		total += inc;
		}
    	w[ s ] = total;
   		REP( u , n ) if( u != s && Prev[ u ] != -1 && p[ u ] == t ) p[ u ] = s;
    	if( Prev[ p[ t ] ] != -1 ) p[ s ] = p[ t ] , p[ t ] = s, w[ s ] = w[ t ] , w[ t ] = total; 
	}
	REP( i , MAXN ) ghtree[ i ].clear() , ghweight[ i ].clear();
	REP( s , n ) if( s != p[ s ] ) {
		ghtree[ s ].push_back( p[ s ] );
		ghtree[ p[ s ] ].push_back( s );
		ghweight[ s ].push_back( w[ s ] );
		ghweight[ p[ s ] ].push_back( w[ s ] ); 
	}
  	clr( max_memo , -1 ); 
}
Weight max_flow( int u , int t , int p = -1 ) {
	if( max_memo[ u ][ t ] != -1 ) return max_memo[ u ][ t ]; 
	if( u == t ) return INF - 1;
	Weight d = INF; 
	FOR( e , ghtree[ u ] ) 
		if( ghtree[ u ][ e ] != p ) {
    		Weight ans = max_flow( ghtree[ u ][ e ] , t , u );
			if( ans < INF ) ans = min( ans , ghweight[ u ][ e ] );
			d = min( d , ans );
		}
	if( d < INF ) max_memo[ u ][ t ] = max_memo[ t ][ u ] = d;
	return d; 
}
  
int main(){
	while(sc(n) == 1){
		int m;
		sc(m);
		REP( i , n ) graph[ i ].clear();
		clr(capacity,0);
		REP(k,m){
			int u,v;
			sc(u),sc(v);
			u--,v--;
			graph[ u ].pb( v );
			capacity[ u ][ v ] = 1;
			
			graph[ v ].pb( u );
			capacity[ v ][ u ] = 1;
		}
		build_tree();
		int ans=0;
		REP(v,n)REP(u,v) ans += max_flow( u , v );
		printf("%d\n",ans);
	}
}

