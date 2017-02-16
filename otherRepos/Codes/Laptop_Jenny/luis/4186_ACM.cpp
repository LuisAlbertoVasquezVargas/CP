#include<bits/stdc++.h>
using namespace std;
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )
#define FOR(it,A) for( typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()

#define N 100005

#define VIZ(e,x) (orig[e] == x? dest[e] : orig[e])

typedef vector< int > vi;

int n , m , fin ;
int orig[N], dest[N], pila[N], top = 0;
vi E[N];
int low[N], dfsn[N], timer;
int bicomp[N], nbicomp;

void dfsbcc( int u , int p = -1 ){
	//cout << u << '\n';
	low[ u ] = dfsn[ u ] = ++timer;
	FOR( it , E[ u ] ){
		int e = *it, v = VIZ ( e , u );
		if ( dfsn[ v ] == 0 ){
			pila[ top++ ] = e;
			dfsbcc ( v , u );
			low[ u ] = min ( low[ u ], low[ v ]);
			if (low[v] >= dfsn[ u ]){
				do{
					fin = pila[ --top ];
					bicomp[ fin ] = nbicomp;
				}while (fin != e);
				nbicomp++;
			}
		}else if (v!=p && dfsn[v] < dfsn[u]){
			pila[top++] = e;
			low[u] = min (low[u], dfsn[v]);
		}
	}
}
void bcc (){
	REP( i , n ) dfsn[ i ] = 0;
	nbicomp = timer = 0;
	REP( i , n ) if ( dfsn[ i ] == 0 ) dfsbcc ( i );
}
vi G[ N ];
int vis[ N ] , COLOR[ N ];
bool bfs( int s )
{
	queue< int > Q;
	Q.push( s );
	COLOR[ s ] = 0;
	vis[ s ] = 1;
	while( !Q.empty() ){
		int u = Q.front();
		Q.pop();
		FOR( v , G[ u ] ){
			if( vis[ *v ] ){
				if( COLOR[ *v ] == COLOR[ u ] ) return 0;
			}
			else{
				COLOR[ *v ] = COLOR[ u ]^1;
				vis[ *v ] = 1;
				Q.push( *v );
			}
		}
	}
	return 1;
}
int main()
{
	int cases , u , v;
	sc( cases );
	while( cases -- ){
		sc( n );
		sc( m );
		REP( i , N ) E[ i ].clear();
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			orig[ i ] = u;
			dest[ i ] = v;
			E[ u ].pb ( i );
			E[ v ].pb ( i );
		}
		bcc();
		//cout << "test" << endl; 
		/*
		REP( i , n ) cout << part[ i ]; cout << endl;
		REP( i , m ) cout << ponte[ i ]; cout << endl;
		REP( i , m ) cout << bicomp[ i ]; cout << endl;
		*/
		//REP( i , m ) bicomp[ i ] = 0;
		int ans = 0;
		/*REP( i , m )
			cout << i << " " << bicomp[ i ] << endl;
		*/
		vector< vi > BIC( m + 1 );
		REP( i , m )
			BIC[ bicomp[ i ] ] . pb( i );
		vi temp;
		REP( i , nbicomp ) 
		{
			vi &v = BIC[ i ];
			//cout << "BIC " << endl;
			int nv = v.size();
			vi SET;
			REP( j , nv ){
				int ind = v[ j ];
				int u = orig[ ind ] , v = dest[ ind ];
				G[ u ].pb( v );
				G[ v ].pb( u );
				SET.pb( u ) , SET.pb( v );
				vis[ u ] = vis[ v ] = 0;
				//cout << u << " " << v << endl;
			}
			bool bicolorable = bfs( orig[ v[ 0 ] ] );
			
			for( int j = nv - 1 ; j >= 0 ; --j ){
				int ind = v[ j ];
				int u = orig[ ind ] , v = dest[ ind ];
				G[ u ].pop_back();
				G[ v ].pop_back();
				vis[ u ] = vis[ v ] = 0;
			}
			
			sort( all( SET ) );
			int sz = unique( all( SET ) ) - SET.begin();
			if( !bicolorable ) REP( i , sz ) temp.pb( SET[ i ] );
			//cout << "SZ: " << sz << endl;
			
		}
		sort( all( temp ) );
		temp.resize( unique( all( temp ) ) - temp.begin() );
		printf( "%d\n" , temp.size() );
	}
}
