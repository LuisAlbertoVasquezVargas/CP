#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back
#define SZ( v ) ((int)(v).size())

#define N (1<<18)
#define EPS (1e-8)

typedef double ld;
typedef long long ll;
typedef vector< int > vi;

struct Point{
    ll x , y;
    Point(){}
    Point( ll x , ll y ): x( x ) , y( y ) { }
};
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
int sz = 0;
Point H[ N ];
ll m[ N ];
inline bool valid( const Point &L2 , const Point &L1 , const Point &L ){
    return (ld)(L2.y - L.y)*(L1.x - L.x) <= (ld)(L1.y - L.y)*(L2.x - L.x) + EPS;
}
void bs( const Point &P ){
	if( sz >= 2 && valid( H[ sz - 2 ] , H[ sz - 1 ] , P ) ){
		int lo = 0 , hi = sz;
		while( hi - lo > 1 ){
			int med = (lo + hi) >>1;
			if( med >= 2 && valid( H[ med - 2 ] , H[ med - 1 ] , P ) ) hi = med;
			else lo = med;
		}
		sz = lo;
	}
}
void add( const Point &P ){
    bs( P );
    H[ sz ] = P;
	
	if( sz ) {
		if( abs( ( P.x - H[ sz - 1 ].x ) ) < EPS ) {
	   		m[ sz - 1 ] = -( P.y - H[ sz - 1 ].y )/1e-50;
		}else m[ sz - 1 ] = -( P.y - H[ sz - 1 ].y )/( P.x - H[ sz - 1 ].x );
	}
    
    sz ++;
}


vi  G[ N ] , C[ N ];
ll AC[ N ];
bool vis[ N ];

ll S[ N ] , V[ N ];
ll DP[ N ];
void dfs( int v , int p = -1 ){
    vis[ v ] = 1;
    int len = SZ( G[ v ] );
    REP( i , len ){
        int u = G[ v ][ i ] , w = C[ v ][ i ];
        if( vis[ u ] || p == u ) continue;
        AC[ u ] = AC[ v ] + w;
        int ind = lower_bound( m , m + sz - 1 , V[ u ] ) - m;
        DP[ u ] = V[ u ] * H[ ind ].x + H[ ind ].y + S[ u ] +  AC[ u ] * V[ u ];
        
        int tempSZ = sz , Ind , modified = 0 , temp2;
        ll last;
        Point tempP;
        
        Point P = Point( -AC[ u ] , DP[ u ] );
        bs( P );

        Ind  = sz;
        tempP = H[ sz ];
        
        H[ sz ] = P;
        if( sz ) {
            temp2 = sz - 1;
            last = m[ sz - 1 ];
            if( abs( ( P.x - H[ sz - 1 ].x ) ) < EPS ) {
		    	m[ sz - 1 ] = -( P.y - H[ sz - 1 ].y )/1e-50;
			}else m[ sz - 1 ] = -( P.y - H[ sz - 1 ].y )/( P.x - H[ sz - 1 ].x );
    
            modified = 1;
        }
        sz ++;

        dfs( u , v );
        // elimina
        sz = tempSZ;
        H[ Ind ] = tempP;
        if( modified ){
            m[ temp2 ] = last;
        }
    }
}
int main(){
    int n , u , v , w;
    scanf( "%d" , &n );
    REP( i , n - 1 ){
        scanf( "%d%d%d" , &u , &v , &w );
        u -- , v --;
        G[ u ].pb( v );
        G[ v ].pb( u );
        C[ u ].pb( w );
        C[ v ].pb( w );
    }
    for( int i = 1 ; i < n ; ++i ) {
        scanf( "%d%d" , &u , &v );
        S[ i ] = u , V[ i ] = v;
    }

    sz =  0;
    DP[ 0 ] = 0;
    add( Point( 0 , 0 ) );
    dfs( 0 );
    
    for( int i = 1 ; i + 1 < n ; ++i )
        printf( "%I64d " , DP[ i ] );
    printf( "%I64d\n" , DP[ n - 1 ] );
}
