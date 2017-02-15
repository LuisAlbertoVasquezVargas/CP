#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i ) 
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define mp make_pair
#define fi first
#define se second

#define pb push_back
#define all( v ) v.begin() , v.end()

#define MAXN 350
#define EPS 1e-8
#define PI acos(-1)
#define Vector Point 
#define FOR(i,x,y) for(int i=x;i<y;i++)
#define INF (1e100)

typedef vector< int > vi;
typedef pair< int , int > pii;
typedef vector< pii > vpii;

int N,H,W;

//inline max( int i , int j ){ return i > j ? i : j ; }
typedef double ld;

int X[ MAXN + 5 ] , Y[ MAXN + 5 ] , ind[ MAXN + 5 ] , temp[ MAXN + 5 ];
pii V[ MAXN + 5 ];

bool cmp( int i , int j ){
	if( X[ i ] != X[ j ] ) return X[ i ] < X[ j ];
	return Y[ i ] < Y[ j ];
}
// INTERSECCION DE CIRCULOS
ld DIST[ MAXN + 5 ][ MAXN + 5 ];
bool done[ MAXN + 5 ][ MAXN + 5 ];
bool circleCircleIntersection( int i , int j , ld r ){
    if( i > j ) swap( i , j );
    ld dist;
	if( done[ i ][ j ] ) dist = DIST[ i ][ j ];
	else
	{
		done[ i ][ j ] = 1;
		ld dx = X[ i ] - X[ j ] , dy = Y[ i ] - Y[ j ];
		dist = DIST[ i ][ j ] = sqrt( abs( dx*dx + dy*dy ) ) ;
	}
	return dist < r*2 + EPS;
} 

bool vis[MAXN];

bool f( ld r){

	FOR(i,0,N) vis[ i ] = 0;
	FOR(i,0,N){
		if(vis[i])continue;
		vis[i]=1;
		int last=i;
		ld left = X[ i ] - r,dwn = Y[ i ] - r , right = X[ i ] + r , up = Y[ i ] + r;
		
		FOR( j , i + 1 , N )
			if( circleCircleIntersection( last , j , r ) ){
				last = j ;
				right = X[ j ] + r;
				if( Y[ j ] + r > up ) up = Y[ j ] + r;
				if( Y[ j ] - r > dwn ) dwn = Y[ j ] - r;
				vis[ j ] = 1;
				if(H < up + EPS && dwn< 0 + EPS)return 0;
				if(W < right  + EPS&&left<0 + EPS)return 0;
				if(H < up + EPS&& W < right + EPS)return 0;
				if(dwn<0 + EPS && left < 0 + EPS ) return 0;
			}
		if( H < up + EPS && dwn < 0 + EPS)return 0;
		if( W < right + EPS &&left < 0 + EPS)return 0;
		if( H < up + EPS && W < right + EPS)return 0;
		if( dwn < 0 + EPS && left < 0 + EPS ) return 0;	
	}	
	return 1;
}
  
int main(){
	while(scanf("%d%d%d",&N,&W,&H)==3){
		if(N==-1)break;
		int x,y;
		ld best = INF;
		clr( done , 0 );	
		REP( i , N ){
			scanf("%d%d",&x,&y);
			V[ i ] = mp( x , y );
			ld dx = x , dy = y;
			best = min( best , dx*dx + dy*dy );
		}
		best = sqrt( abs( best ) );
		sort( V , V + N );
		REP( i , N ) X[ i ] = V[ i ].fi , Y[ i ] = V[ i ].se;
		ld lo = 0 , hi = best + 1;
		REP( it , 54 ){
			ld mid = ( lo + hi )/2;
			if( f( mid ) ) lo = mid;
			else hi = mid;
		}
		printf("%.3f\n",(ld( hi + lo )/2.0 ) );
	}
}

