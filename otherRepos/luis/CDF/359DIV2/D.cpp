#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)v.size())

typedef vector< int > vi;
typedef long long ll;

const int N = 300000;
const int INF = (1<<29);

ll target;
vi G[ N + 5 ];
 
void add( int u , int v ){
	G[ u ].pb( v );
}
int DP[ N + 5 ] , MAXI[ N + 5 ];
void dfs( int u , int p = -1 ){
	DP[ u ] = 1 , MAXI[ u ] = 0;
	for( int i = 0 ; i < SZ( G[ u ] ) ; ++i ){
		int v = G[ u ][ i ];
		if( v == p ) continue;
		dfs( v , u );
		DP[ u ] += DP[ v ];
		MAXI[ u ] = max( MAXI[ u ] , DP[ v ] );
	}
}

int P[N + 5];
int solve( int u , int p = -1 ){
	//cout << "* " << root << endl;
	int root = -1;
	for(auto v : G[ u ]){
		if(v == p) continue;
		MAXI[ v ] = max( MAXI[ v ] , DP[ u ] - DP[ v ] );
		if( 2 * MAXI[ v ] <= DP[ u ] ){
			root = v;
			break;
		}
	}
	int ans = u;
	for(auto v : G[ u ]){
		if(v == p) continue;
		int temp = solve(v , u);
		if(v == root) ans = temp;
	}
	return P[ u ] = ans;
}
int main(){
	int n , Q;
	while(scanf( "%d%d" , &n , &Q ) == 2){
		for( int i = 0 ; i < N ; ++i ) G[ i ].clear();
		for( int u = 2 ; u <= n ; ++u ){
			int p;
			scanf( "%d" , &p );
			add( p - 1 , u - 1 );
			add( u - 1 , p - 1 );
		}
		clr(P , -1);
		dfs(0);
		solve( 0 );
		REP(i , Q){
			int u;
			scanf("%d" , &u);
			u --;
			printf("%d\n" , P[ u ] + 1);
		}
		//REP(i , n) cout << i + 1 << " -> " << P[ i ] + 1 << endl;
	}
}
