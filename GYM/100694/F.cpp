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

#define INF (1<<29)
#define MAXV 1005
#define MAXE 4100
#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef vector< string > vs;
typedef long long ll;
typedef vector< ll > vll;

int n , m , s , t , E;
int to[ 2 * MAXE + 5 ] , cap[ 2 * MAXE + 5 ] , NEXT[ 2 * MAXE + 5 ];//maxe * 2
int last[ 2 * MAXV + 5 ] , now[ 2 * MAXV + 5 ] , dist[ 2 * MAXV + 5 ];// maxv
void clear(){
    E = 0;
    REP( i , n ) last[ i ] = -1;
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
int maxFlow(){
    int flow = 0;
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

int main(){
    ios_base :: sync_with_stdio( 0 );
    int R , C ;
    while( cin >> R >> C ){
        vi p( R );
        REP( i , R ) cin >> p[ i ]; 
        vs names( R );
        REP( i , R ) cin >> names[ i ];
        vs mat( R );
        REP( i , R ) cin >> mat[ i ];
        vi ind( 3 ) , vec;
        int best = INT_MIN;
        for( int a = 0 ; a < R ; ++a )
            for( int b = a + 1 ; b < R ; ++ b )
                for( int c = b + 1 ; c < R ; ++c ){
                    ind = { a , b , c };
                    int temp = 0;
                    REP( i , 3 ) temp += p[ ind[ i ] ];
                    if( temp <= best ) continue;
                    
                    n = 13 , s = n - 1 , t = n - 2;
                    clear();
                    REP( i , 3 ) add( s , 8 + i , p[ ind[ i ] ] );
                    vi F( 8 );
                    REP( j , C ){
                    	int cur = 0;
                    	REP( i , 3 )
                    		if( mat[ ind[ i ] ][ j ] == '1' )
                    			cur ^= (1 << i);
                    	F[ cur ] ++;
                    }
                    REP( j , 8 ) add( j , t , F[ j ] );
                    REP( i , 3 ) REP( j , 8 )
                    	if( j & (1 << i) ) add( 8 + i , j , INF );
   
                    int cur = maxFlow();
                    if( cur > best ){
                        best = cur;
                        vec = ind;
                    }
                }
        
        cout << best << '\n';
        REP( i , 3 )
            cout << names[ vec[ i ] ] << char( (i + 1 == 3 ? 10 : 32 ));
        
    }
}


