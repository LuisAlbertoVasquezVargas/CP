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

#define INF (1<<20)
#define N 200000

#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;

#define MAX_V 500

int V,cost[MAX_V][MAX_V];
int lx[MAX_V],ly[MAX_V];
int max_match,xy[MAX_V],yx[MAX_V],PREV[MAX_V];
bool S[MAX_V],T[MAX_V];
int slack[MAX_V],slackx[MAX_V];
int q[MAX_V],head,tail;

void init_labels(){
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
	
    for(int x = 0;x<V;++x)
        for(int y = 0;y<V;++y)
            lx[x] = max(lx[x],cost[x][y]);
}

void update_labels(){
    int x,y,delta = INT_MAX;
	
    for(y = 0;y<V;++y) if(!T[y]) delta = min(delta,slack[y]);
    for(x = 0;x<V;++x) if(S[x]) lx[x] -= delta;
    for(y = 0;y<V;++y) if(T[y]) ly[y] += delta;
    for(y = 0;y<V;++y) if(!T[y]) slack[y] -= delta;
}

void add_to_tree(int x, int prevx){
    S[x] = true;
    PREV[x] = prevx;
	
    for(int y = 0;y<V;++y){
        if(lx[x]+ly[y]-cost[x][y]<slack[y]){
            slack[y] = lx[x]+ly[y]-cost[x][y];
            slackx[y] = x;
        }
    }
}

void augment(){
    int x,y,root;
    head = tail = 0;
    memset(S,false,sizeof(S));
    memset(T,false,sizeof(T));
    memset(PREV,-1,sizeof(PREV));
    
    for(x = 0;x<V;++x){
        if(xy[x]==-1){
            q[tail++] = root = x;
            PREV[root] = -2;
            S[root] = true;
            break;
        }
    }
	
    for(y = 0;y<V;++y){
        slack[y] = lx[root]+ly[y]-cost[root][y];
        slackx[y] = root;
    }
	
    while(true){
        while(head<tail){
            x = q[head++];
			
            for(y = 0;y<V;++y){
                if(cost[x][y]==lx[x]+ly[y] && !T[y]){
                    if(yx[y]==-1) break;
					
                    T[y] = true;
                    q[tail++] = yx[y];
                    add_to_tree(yx[y],x);
                }
            }
			
            if(y<V) break;
        }
		
        if(y<V) break;
		
        update_labels();
        head = tail = 0;
		
        for(y = 0;y<V;++y){
            if(!T[y] && slack[y]==0){
                if(yx[y]==-1){
                    x = slackx[y];
                    break;
                }
				
                T[y] = true;
				
                if(!S[yx[y]]){
                    q[tail++] = yx[y];
                    add_to_tree(yx[y],slackx[y]);
                }
            }
        }
		
        if(y<V) break;
    }
	
    ++max_match;
	
    for(int cx = x,cy = y,ty;cx!=-2;cx = PREV[cx],cy = ty){
        ty = xy[cx];
        yx[cy] = cx;
        xy[cx] = cy;
    }
}

int hungarian(){
    int ret = 0;
    max_match = 0;
    memset(xy,-1,sizeof(xy));
    memset(yx,-1,sizeof(yx));
	
    init_labels();
    for(int i = 0;i<V;++i) augment();
    for(int x = 0;x<V;++x) ret += cost[x][xy[x]];
	
    return ret;
}
/*
int main(){
	while( sc( V ) == 1 ){
		REP( i , V ) REP( j , V ) sc( cost[ i ][ j ] );
		printf( "%d\n" , hungarian() );
	}
}
*/

int main(){
	
    freopen( "beloved.in" , "r" , stdin );
    freopen( "beloved.out" , "w" , stdout );
    
    int n ;
    while( sc( n ) == 1 ){
        vi a( n );
        REP( i , n ) sc( a[ i ] );
        REP( i , n ) REP( j , n ) cost[ i ][ j ] = 0;
        REP( i , n ){
            int ki;
            sc( ki );
            REP( j , ki ){
                int x;
                sc( x );
                x --;
	            cost[ i ][ x ] = a[ i ] * a[ i ];
            }
        }
		V = n;
		hungarian();
		REP( i , n ) printf( "%d%c" , cost[ i ][ xy[ i ] ] == 0 ? 0 : (xy[ i ] + 1) , (i + 1 == n) ? 10 : 32 );
    }
	
}


