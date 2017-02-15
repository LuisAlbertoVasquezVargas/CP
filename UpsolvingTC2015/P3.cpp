#include<bits/stdc++.h>
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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int n , timer , top;
vi G[ N + 5 ];
int dfsn[ N + 5 ] , pila[ N + 5 ] , inpila[ N + 5 ] , comp[ N + 5 ];

int dfs( int u ){
    int low = dfsn[ u ] = ++timer;
    inpila[ pila[ top ++ ] = u ] = 1;
    for( int v : G[ u ] ){
        if( dfsn[ v ] == 0 ) low = min( low , dfs( v ) );
        else if( inpila[ v ] ) low = min( low , dfsn[ v ] );
    }
    if( low == dfsn[ u ] ){
        int fin;
        do{
            fin = pila[ --top ];
            inpila[ fin ] = 0;
            comp[ fin ] = u;
        }while( fin != u );
    }
    return low;
}

void SCC(){
    clr( dfsn , 0 );
    top = timer = 0;
    REP( i , n ) if( !dfsn[ i ] ) dfs( i );
}
int id[ N + 5 ] , len[ N + 1 ];
int Find( int x ){ return id[ x ] = ( (id[ x ] == x) ? x : Find( id[ x ] ) );}
void Union( int u , int v ){
    int pu = Find( u ) , pv = Find( v );
    if( pu != pv ) {
        len[ pv ] += len[ pu ];
        id[ pu ] = pv;
    }
}
int main(){
    int m;
    while( sc( n ) == 1 ){
        sc( m );
        REP( i , n ) id[ i ] = i , len[ i ] = 1;
        REP( i , n ) G[ i ].clear();
        REP( i , m ){
            int u , v;
            sc( u ) , sc( v );
            u -- , v --;
            G[ u ].pb( v );
            Union( u , v );
        }
        SCC();
        vi F( n );
        REP( i , n ) F[ comp[ i ] ] ++;
        vi tristeza( n );
        REP( i , n )
            if( comp[ i ] == i ) {
                if( F[ comp[ i ] ] > 1 ) {
                    tristeza[ Find( comp[ i ] ) ] = 1;
                }
            }
        int ans = 0;
        REP( i , n )
            if( Find( i ) == i ) {
                if( tristeza[ Find( i ) ] ) ans += len[ Find( i ) ];
                else ans += len[ Find( i ) ] - 1;
            }
        printf( "%d\n" , ans );
    }
}

