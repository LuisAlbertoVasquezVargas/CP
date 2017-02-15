#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define test puts("************test************");

#define N 505
#define M 300000

typedef vector< int > vi;

int A[ N + 5 ] , B[ N + 5 ];

int le[N], ri[N], distx[N], disty[N], q[N];
int to[M], head[N], next[M], edg;
int n, m;

void reset(){
    clr(head, -1); edg = 0;
    clr(le, -1); clr(ri, -1);
}
void add(int u, int v){
    to[edg] = v; next[edg] = head[u]; head[u] = edg++;
}
bool bfs(){
    bool flag = false;
    REP( i , n ) distx[i] = 0;
    REP( i , m ) disty[i] = 0;
    int sz = 0;
    REP( i , n ) if(le[i] == -1) q[sz++] = i;
    REP( ii , sz ){
        int u = q[ ii ];
        for(int i = head[u]; i != -1; i = next[i]){
            int v = to[i];
            if(!disty[v]){
                disty[v] = distx[u] + 1;
                if(ri[v] == -1) flag = true;
                else distx[ri[v]] = disty[v] + 1, q[sz++] = ri[v];
            }
        }
    }
    return flag;
}
bool dfs(int u){
    for(int i = head[u]; i != -1; i = next[i]){
        int v = to[i];
        if(disty[v] == distx[u] + 1){
            disty[v] = 0;
            if(ri[v] == -1 || dfs(ri[v])){
                le[u] = v;
                ri[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hopcroft(){
    int res = 0;
    while( bfs() )
        REP( i , n )
            if(le[i] == -1 && dfs(i)) res++;
    return res;
}


int main(){
	while( sc( n ) == 1 ){
		sc( m );
		if( n == 0 && m == 0 ) break;
		REP( i , n ) sc( A[ i ] );
		REP( i , m ) sc( B[ i ] );
		reset();
		REP( i , n ) REP( j , m ) if( __gcd( A[ i ] , B[ j ] ) > 1 ) add( i , j );
		printf( "%d\n" , hopcroft() );
	}
}



